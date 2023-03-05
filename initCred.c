#include <stdio.h>
#include <conio.h>
#include <windows.h>
struct cred{
    char usrName[30];
    char realPwd[30];
};
int main(){
    struct cred info={
        "vinay_b",
        "vinay@123"
    };
    FILE *fpc,*fp;
    fpc=fopen("cred.txt","w");
        if(fpc==NULL){
            printf("\t\t\t\tAn Error Occured");
            exit(0);
        }
    fp = fopen("del.bat","w");
        if(fp == NULL){
            printf("error"); 
            exit(0);      
        }
    fprintf(fp,"del initCred.exe\n");
    fprintf(fp,"del del.bat");
    fclose(fp);
    fwrite(&info,sizeof(struct cred),1,fpc);
    fclose(fpc);
    printf("\n\t\t\t\tCredentials Successfully initialized!!!");
    fpc=fopen("cred.txt","r");
    fclose(fpc);
    printf("Enter any key...");
    getch();
    system("start /B del.bat");
}
