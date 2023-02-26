//################################## STUDENT DATABASE MANAGEMENT SYSTEM ##########################################
#include <stdio.h>
#include <conio.h>
#include <windows.h>
void addstud();
void display();
void search();
void deleteRec();
void login();
struct student{    
    int roll;
    char name[100];
    char branch[40];
    char gender[10];
    float cgpa;
    char usn[10];
};
int main(){
    int opt;
    while(opt!=5){
    printf("\n\n\t\t\t========STUDENT DATABASE MANAGER========");
    printf("\n\n\n\t\t\t\t1) Add student");
    printf("\n\t\t\t\t2) Display students");
    printf("\n\t\t\t\t3) Search any student details");
    printf("\n\t\t\t\t4) Delete any student");
    printf("\n\t\t\t\t5) Exit from software\n\t\t\t\t____________________");
    printf("\n\t\t\t\tEnter any option: ");
    scanf("%d",&opt);
    switch(opt){
        case 1: system("cls");
                addstud();
                system("cls");
                break;
        case 2: system("cls");
                display();
                system("cls");
                break;
        case 3: system("cls");
                search();
                system("cls");
                break;
        case 4: system("cls");
                deleteRec();
                system("cls");
                break;
        case 5: system("cls");
                printf("\n\n\n\t\t\t\tThank you for using this software !");
                exit(0);
                break;
        default:system("cls");
                printf("\n\t\t\t\tIt was an invalid choice");
                printf("\n\t\t\t\tPlease try with other options");
      }
    }
    return 0;
}
void addstud(){
    login();
    FILE *fp;
    int droll,i=0,flag;
    char again;
    struct student s, t;
    x:fp=fopen("records.txt","a+");
    if(fp==NULL){
        printf("\t\t\t\tAn Error Occured");
        exit(0);
    }
    printf("\n\n\t\t\t========ADD ANY STUDENT'S DETAILS========");
    printf("\n\n\t\t\t\tEnter USN         : ");
    scanf("%s",t.usn);
    printf("\n\t\t\t\tEnter roll number : ");
    scanf("%d",&t.roll);
    droll=t.roll;
    printf("\n\t\t\t\tEnter name        : ");
    scanf("%s",&t.name);
    printf("\n\t\t\t\tEnter branch      : ");
    scanf("%s",&t.branch);
    printf("\n\t\t\t\tEnter gender (M/F): ");
    scanf("%s",&t.gender);
    printf("\n\t\t\t\tEnter CGPA        : ");
    scanf("%f",&t.cgpa);
    while(fread(&s,sizeof(struct student),1,fp)){
        if(droll==s.roll){
            system("cls");
            printf("\n\t\t\t\tEntered data already exists !");
            printf("\n\t\t\t\tPlease enter a valid data...");
            fclose(fp);
            goto x;
        }
        if(!strcmp(t.usn,s.usn)){
            system("cls");
            printf("\n\t\t\t\tEntered data already exists !");
            printf("\n\t\t\t\tPlease enter a valid data...");
            fclose(fp);
            goto x;
        }
    }
    fwrite(&t,sizeof(struct student),1,fp);
    printf("\n\t\t\t\tYOUR DATA HAS BEEN SAVED SUCCESFULLY !");
    printf("\n\t\t\t\tEnter any key to exit...");
    getch();
    fclose(fp);
}
void display(){
    login();
    FILE *fp;
    struct student s;
    fp=fopen("records.txt","r");
    if(fp==NULL){
        printf("\t\t\t\tAn Error Occured");
        exit(0);
    }
    printf("\n\n\t\t\t========STUDENT'S RECORDS========");
    while(fread(&s,sizeof(struct student),1,fp)){
        printf("\n\n\t\t\t\tUSN     : %s",s.usn);
        printf("\n\t\t\t\tRoll num: %d",s.roll);
        printf("\n\t\t\t\tName    : %s",s.name);
        printf("\n\t\t\t\tBranch  : %s",s.branch);
        printf("\n\t\t\t\tGender  : %s",s.gender);
        printf("\n\t\t\t\tCGPA    : %.2f",s.cgpa);
        printf("\n\t\t\t\t____________________");
    }
    fclose(fp);
    printf("\n\t\t\tEnter any key to exit...");
    getch();
}
void search(){
    login();
    FILE *fp;
    int rollNo,flag=0;
    struct student s;
    fp=fopen("records.txt","r");
    if(fp==NULL){
        printf("\t\t\t\tAn Error Occured");
        exit(0);
    }
    printf("\n\n\t\t\t========SEARCH ANY STUDENT'S DETAILS========");
    printf("\n\n\t\t\tEnter roll Number: ");
    scanf("%d",&rollNo);
    while(fread(&s,sizeof(struct student),1,fp)){
        if(s.roll==rollNo){
        printf("\n\n\t\t\t\tUSN     : %s",s.usn);
        printf("\n\t\t\t\tRoll num: %d",s.roll);
        printf("\n\t\t\t\tName    : %s",s.name);
        printf("\n\t\t\t\tBranch  : %s",s.branch);
        printf("\n\t\t\t\tGender  : %s",s.gender);
        printf("\n\t\t\t\tCGPA    : %.2f",s.cgpa);
        printf("\n\t\t\t\t____________________");
        flag=1;
        }
    }
    if(flag==0)
        printf("\n\n\t\t\t\tRecord not found !");
    fclose(fp);
    printf("\n\t\t\tEnter any key to exit...");
    getch();    
}
void deleteRec(){
    login();
    struct student s;
      FILE *fp, *fpt;
      int rollNo,flag=0;
      printf("\n\t\t\t\t=======DELETE STUDENTS RECORD=======\n\n\n");
      fp=fopen("records.txt","r");
      fpt=fopen("recover.txt","w");
      printf("\t\t\t\tEnter the roll no : ");
      scanf("%d",&rollNo);
      if(fp==NULL){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }
    while(fread(&s,sizeof(struct student),1,fp)){
        if(rollNo==s.roll)
           flag=1;
        else
           fwrite(&s,sizeof(struct student),1,fpt);
    }
    fclose(fp);
    fclose(fpt);
    if(!flag)
       printf("\n\n\t\t\t\tRecord not found !");
    else{
        remove("records.txt");
        rename("recover.txt","records.txt");
        printf("\n\n\t\t\t\tRecord deleted successfully !");
    }
    printf("\n\n\t\t\t\tEnter any key to exit...");
    getch();
}
void login(){
    char c;
    int i,flag=1;
    char usrName[30]="vinay_b";
    char realPwd[30]="vinay@123";
    char enteredPwd[30];
    system("cls");
    y:printf("\n\t\t\t\t=======LOGIN TO CONTINUE=======");
    i=0;
    printf("\n\n\t\t\t\tUSERNAME: ");
    scanf("%s",usrName);
    printf("\n\t\t\t\tPASSWORD: ");
    while((c=getch())!=13){
        enteredPwd[i]=c;
        printf("*");
        i++;
    }
    enteredPwd[i]='\0';
    if(!strcmp(enteredPwd,realPwd)){
        system("cls");
        printf("\n\n\n\t\t\t\tLogin Successful....");   
    }
    else{
        system("cls");
        printf("\n\t\t\t\tIncorrect Credentials....");
        printf("\n\t\t\t\tPlease Try again\n");
        goto y;
     }   
}