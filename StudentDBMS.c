//################################## STUDENT DATABASE MANAGEMENT SYSTEM ##########################################
#include <stdio.h>
#include <conio.h>
#include <windows.h>
void addstud();
void display();
void search();
void deleteRec();
void changeCredMenu();
void login();
char* Cbranch(char,char);
struct student{    
    char name[100];
    char lname[100];
    char branch[40];
    char gender[10];
    float cgpa;
    char usn[10];
};
struct cred{
    char usrName[30];
    char realPwd[30];
};
int main(){
    int opt;
    while(opt!=6){
    printf("\n\n\t\t\t========STUDENT DATABASE MANAGER========");
    printf("\n\n\n\t\t!!! INITIALIZE YOUR CREDENTIALS DURING INITIAL SETUP !!!");
    printf("\n\n\n\t\t\t\t1) Add student");
    printf("\n\t\t\t\t2) Display students");
    printf("\n\t\t\t\t3) Search any student details");
    printf("\n\t\t\t\t4) Delete any student");
    printf("\n\t\t\t\t5) Change credentials");
    printf("\n\t\t\t\t6) Exit from software\n\t\t\t\t____________________");
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
                changeCredMenu();
                break;
        case 6: system("cls");
                printf("\n\n\n\t\t\t\tThank you for using this software !");
                getch();
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
    char colCode[3] = "3BR";
    FILE *fp;
    int i=0,flag;
    char again;
    struct student s, t;
    x:fp=fopen("records.txt","a+");
    if(fp==NULL){
        printf("\t\t\t\tAn Error Occured");
        exit(0);
    }
    a:printf("\n\n\t\t\t========ADD ANY STUDENT'S DETAILS========");
    printf("\n\n\t\t\t\tEnter USN         : ");
    scanf("%s",t.usn);
    for(int i = 0; i < 3; i++){
        if(colCode[i]!=t.usn[i]){
            system("cls");
            printf("\n\n\t\t\t\tThis student dosent belongs to BITM!!"); 
            goto a;
        }
    }
    strcpy(t.branch,Cbranch(t.usn[5],t.usn[6]));
    printf("\n\t\t\t\tEnter first name  : ");
    scanf("%s",&t.name);
    printf("\n\t\t\t\tEnter last name   : ");
    scanf("%s",&t.lname);
    printf("\n\t\t\t\tEnter gender (M/F): ");
    scanf("%s",&t.gender);
    printf("\n\t\t\t\tEnter CGPA        : ");
    scanf("%f",&t.cgpa);
    while(fread(&s,sizeof(struct student),1,fp)){
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
char* Cbranch(char a,char b){
    if(a == 'E' && b == 'C')
        return "ECE";
    if(a == 'E' && b == 'E')
        return "EEE";
    if(a == 'C' && b == 'S')
        return "CSE";  
    if(a == 'C' && b == 'V')
        return "CIVIL";
    if(a == 'M' && b == 'E')
        return "MECH";
    if(a == 'A' && b == 'I')
        return "AIML";  
    else
        return "----";
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
        printf("\n\t\t\t\tName    : %s %s",s.name,s.lname);
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
    int flag=0;
    struct student s,temp;
    fp=fopen("records.txt","r");
    if(fp==NULL){
        printf("\t\t\t\tAn Error Occured");
        exit(0);
    }
    printf("\n\n\t\t\t========SEARCH ANY STUDENT'S DETAILS========");
    printf("\n\n\t\t\tEnter USN Number: ");
    scanf("%s",temp.usn);
    while(fread(&s,sizeof(struct student),1,fp)){
        if(!strcmp(temp.usn,s.usn)){
        printf("\n\n\t\t\t\tUSN     : %s",s.usn);
        printf("\n\t\t\t\tName    : %s %s",s.name,s.lname);
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
    struct student s,tempDel;
      FILE *fp, *fpt;
      int flag=0;
      printf("\n\t\t\t\t=======DELETE STUDENTS RECORD=======\n\n\n");
      fp=fopen("records.txt","r");
      fpt=fopen("recover.txt","w");
      printf("\t\t\t\tEnter USN no : ");
      scanf("%s",tempDel.usn);
      if(fp==NULL){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }
    while(fread(&s,sizeof(struct student),1,fp)){
        if(!strcmp(tempDel.usn,s.usn))
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
    char enteredPwd[30];
    char enteredUsr[30];
    FILE *fp;
    struct cred info;
    system("cls");
    y:printf("\n\t\t\t\t=======LOGIN TO CONTINUE=======");
    i=0;
    printf("\n\n\t\t\t\tUSERNAME: ");
    scanf("%s",enteredUsr);
    printf("\n\t\t\t\tPASSWORD: ");
    while((c=getch())!=13){
        enteredPwd[i]=c;
        printf("*");
        i++;
    }
    enteredPwd[i]='\0';
    system("cls");
    fp=fopen("cred.txt","r");
    while(fread(&info,sizeof(struct cred),1,fp)){
        if(!strcmp(enteredPwd,info.realPwd) && !strcmp(enteredUsr,info.usrName)){
            printf("\n\t\t\t\tLogin Successful"); 
        }
        else{
            printf("\n\t\t\t\tAccess Denied!");           
            goto y;
        }
    }
    fclose(fp);   
}
void changeCredMenu (){
    char pet[40] = "bolt", worst[40] = "assignments",c;
    char upet[40], uworst[40];
    int opt,i=0,check=0,ans=0,ans1=0;
    FILE *fpc;
    fpc=fopen("cred.txt","w");
    struct cred info;
        if(fpc==NULL){
            printf("\t\t\t\tAn Error Occured");
            exit(0);
    }
    while(opt!=3 && check == 0){
    printf("\n\n\t\t\t\t========CHANGE CREDENTIALS========");
    printf("\n\n\n\t\t\t\tChoose any question that you can answer !");
    printf("\n\n\n\t\t\t\t1) What is your pet name?");
    printf("\n\t\t\t\t2) Which is the worst thing in BITM?");
    printf("\n\t\t\t\t3) Try other ways");
    printf("\n\t\t\t\t4) Dont want to make any changes...\n\t\t\t\t____________________");
    printf("\n\t\t\t\tEnter any option: ");
    scanf("%d",&opt);
    switch(opt){
        case 1: system("cls");
                printf("\n\n\n\t\t\t\t1) What is your pet name?");
                scanf("%s",&upet);
                if(!strcmp(upet,pet)){
                    ans=1;
                    printf("\n\n\t\t\t\tUSERNAME: ");
                    scanf("%s",info.usrName);
                    s:printf("\n\t\t\t\tPASSWORD: ");
                    while((c=getch())!=13){
                        info.realPwd[i]=c;
                        printf("*");
                        i++;
                    }
                    info.realPwd[i]='\0';
                }
                if(info.realPwd[0]=='\0'){
                    system("cls");
                    printf("\n\t\t\t\tPlease enter a valid password...\n");
                    goto s;
                }
                system("cls");
                fwrite(&info,sizeof(struct cred),1,fpc);
                fclose(fpc);
                system("cls");
                if(ans == 0){
                    system("cls");
                    printf("\n\t\t\t\tINVALID ANSWER !");
                }
                else{
                    system("cls");
                    printf("\n\t\t\t\tCredentials updated successfully!");
                }
                check = 1;
                break;
        case 2: system("cls");
                printf("\n\n\n\t\t\t\t2) Which is the worst thing in BITM?");
                scanf("%s",&uworst);
                if(!strcmp(uworst,worst)){
                    ans1=1;
                    printf("\n\n\t\t\t\tNEW USERNAME: ");
                    scanf("%s",info.usrName);
                    y:printf("\n\t\t\t\tNEW PASSWORD: ");
                    while((c=getch())!=13){
                        info.realPwd[i]=c;
                        printf("*");
                        i++;
                    }
                    info.realPwd[i]='\0';
                }
                if(info.realPwd[0]=='\0'){
                    system("cls");
                    printf("\n\t\t\t\tPlease enter a strong password...\n");
                    goto y;
                }
                system("cls");
                fwrite(&info,sizeof(struct cred),1,fpc);
                fclose(fpc);
                if(ans1 == 0){
                    system("cls");
                    printf("\n\t\t\t\tINVALID ANSWER !");
                }
                else{
                    system("cls");
                    printf("\n\t\t\t\tCredentials updated successfully!");
                }
                check = 1;
                break;
        case 3: system("cls");
                printf("\t\t\tReinitialize your credentials!!");
                printf("\n\t\t\tcontact mydbms00@gmail.com for an initialization");
                printf("\n\t\t\tEnter any key...");
                getch();
        case 4: system("cls");
                return;
                break;
        default:system("cls");
                printf("\n\t\t\t\tIt was an invalid choice");
                printf("\n\t\t\t\tPlease try with other options");
      }
    }
}