#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
struct student
{
    char first_name[10];
    char middle_name[10];
    char last_name[10];
    struct date
    {
        int d,m,y;
    }dt;
    char sex[10];
    char number[15];
    char guardian_number[15];
    char address[50];
    int standard;
    char division;
    int unique_id;

}s;
COORD coord = {0,0};

void gotoxy(int x , int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    system("color 70");
    start();
    return 0;
}
void menu()
{
    system("cls");
    gotoxy(20,3);
    printf("\t\tWELCOME TO OUR LADY OF REMEDY HIGH SCHOOL PORTAL\n");
    gotoxy(20,5);
    printf("\t\tEnter your choice");
    gotoxy(40,8);
    printf("\t\tMENU");
    gotoxy(30,10);
    printf("1. Add New Record");
    gotoxy(30,12);
    printf("2.Display all ");
    gotoxy(30,14);
    printf("3. Search");
    gotoxy(60,10);
    printf("4.Modify / Alter ");
    gotoxy(60,12);
    printf("5.Delete");
    gotoxy(60,14);
    printf("6.Exit");
    switch(getch())
    {
        case '1':
            add_record();
            break;
        case '2':
            display_records();
            break;
        case '3':
            search_record();
            break;
        case '4':
            modify_record();
            break;
        case '5':
            delete_record();
            break;
        case '6':
            return 0;
        default:
            {
            system("cls");
            printf("Enter a valid option\n");
            printf("Enter any key to go back to menu");
            getch();
            menu();
            }
    }

}
void start()
{
    menu();
}
void back()
{
    start();
}
void add_record()
{
    int sex_flag = 1;
    char sex_char;
    system("cls");
    FILE *fp1;
    fp1 = fopen("student.txt","a+");
    printf("\t\tNEW STUDENT RECORD\t\n");
    printf("Enter First Name\t\t\t");
    fflush(stdin);
    gets(s.first_name);
    printf("Enter Middle Name\t\t\t");
    gets(s.middle_name);
    printf("Enter Last Name\t\t\t\t");
    fflush(stdin);
    gets(s.last_name);
    printf("Birth information:\n");
    fflush(stdin);
    printf("Enter date\t\t\t\t");
    fflush(stdin);
    scanf("%d",&s.dt.d);
    printf("Enter month\t\t\t\t");
    fflush(stdin);
    scanf("%d",&s.dt.m);
    printf("Enter year\t\t\t\t");
    fflush(stdin);
    scanf("%d",&s.dt.y);
    while(sex_flag)
    {
    printf("Enter sex (M/F)\t\t\t\t");
    fflush(stdin);
    scanf("%c",&sex_char);
    switch(sex_char)
    {
    case 'M':
    case 'm':
        strcpy(s.sex,"Male");
        sex_flag=0;
        break;
    case 'F':
    case 'f':
        strcpy(s.sex,"Female");
        sex_flag=0;
        break;
    default :
        printf("Enter again\n");
    }
    }
    printf("Enter Phone number\t\t\t");
    fflush(stdin);
    gets(s.number);

    printf("Enter Phone number of a guardian\t");
    fflush(stdin);
    gets(s.guardian_number);

    printf("Enter Address\t\t\t\t");
    fflush(stdin);
    gets(s.address);

    printf("Enter Standard\t\t\t\t");
    fflush(stdin);
    scanf("%d",&s.standard);

    printf("Enter Division\t\t\t\t");
    fflush(stdin);
    scanf("%c",&s.division);

    printf("Enter id\t\t\t\t");
    fflush(stdin);
    scanf("%d",&s.unique_id);

    SEEK_END;
    fwrite(&s,sizeof(s),1,fp1);
    printf("\n\tRECORD SAVED !");
    fclose(fp1);
    printf("Enter any key to go back to menu!");
    getch();
    system("cls");
    menu();

}

void display_records()
{
    FILE *fp1;
    fp1 = fopen("student.txt","a+");
    system("cls");
    rewind(fp1);
    if(fp1==NULL)
    {
        printf("File Opening Error");
        menu();
    }

    printf("\t\tNAME\t\t\tDOB\t\tSEX\tPHONE NO.\tGUARDIANS NO.\t\tADDRESS\t\t\tCLASS\tDIVISION\tUNIQUE ID\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n ");
    while(fread(&s,sizeof(s),1,fp1)==1)
    {
        printf("%10s  %10s  %10s\t%d/%d/%d\t%s\t%s\t%s\t%-30s\t%d\t%c\t\t%d\n\n",s.first_name,s.middle_name,s.last_name,s.dt.d,s.dt.m,s.dt.y,s.sex,s.number,s.guardian_number,s.address,s.standard,s.division,s.unique_id);
    }
    fclose(fp1);
    getch();
    menu();
}

void modify_record()
{
    int sex_flag = 1;
    int modify_flag = 1;
    char sex_char;
    char modifyname[20];
    FILE *fp1;
    fp1 = fopen("student.txt","a+");
    system("cls");
    printf("Enter the first name of the student you wish to modify records of:\n");
    gets(modifyname);
    rewind (fp1);
    while(fread(&s,sizeof(s),1,fp1)==1)
    {
        //printf("entered loop check \n");
        if(strcmp(s.first_name,modifyname)==0)
        {
        printf("Enter modified record\n\n");
        printf("Enter First Name\t\t\t");
        fflush(stdin);
        gets(s.first_name);
        printf("Enter Middle Name\t\t\t");
        gets(s.middle_name);
        printf("Enter Last Name\t\t\t\t");
        fflush(stdin);
        gets(s.last_name);
        printf("Birth information:\n");
        fflush(stdin);
        printf("Enter date\t\t\t\t");
        fflush(stdin);
        scanf("%d",&s.dt.d);
        printf("Enter month\t\t\t\t");
        fflush(stdin);
        scanf("%d",&s.dt.m);
        printf("Enter year\t\t\t\t");
        fflush(stdin);
        scanf("%d",&s.dt.y);
        while(sex_flag)
        {
        printf("Enter sex (M/F)\t\t\t\t");
        fflush(stdin);
        scanf("%c",&sex_char);
        switch(sex_char)
        {
        case 'M':
        case 'm':
            strcpy(s.sex,"Male");
            sex_flag=0;
            break;
        case 'F':
        case 'f':
            strcpy(s.sex,"Female");
            sex_flag=0;
            break;
        default :
            printf("Enter again\n");
        }
        }
        printf("Enter Phone number\t\t\t");
        fflush(stdin);
        gets(s.number);

        printf("Enter Phone number of a guardian\t");
        fflush(stdin);
        gets(s.guardian_number);

        printf("Enter Address\t\t\t\t");
        fflush(stdin);
        gets(s.address);

        printf("Enter Standard\t\t\t\t");
        fflush(stdin);
        scanf("%d",&s.standard);

        printf("Enter Division\t\t\t\t");
        fflush(stdin);
        scanf("%c",&s.division);

        printf("Enter id\t\t\t\t");
        fflush(stdin);
        scanf("%d",&s.unique_id);

        fseek(fp1,-sizeof(s),SEEK_CUR);
        fwrite(&s,sizeof(s),1,fp1);
        printf("\n\t\tRECORD MODIFIED!\t\t");
        modify_flag = 0;
        fclose(fp1);
        break;
        }
        }
     if(modify_flag)
        {
            printf("\n\tNo record found!\t");
        }
        getch();
        menu();
}
void delete_record()
{
    char student_delete[20];
    system("cls");
    FILE *fp1,*ftemp;
    fp1 = fopen("student.txt","a+");
    printf("\nEnter first name of student to delete:\t ");
    gets(student_delete);
    ftemp = fopen("Temp.txt","w");
    while(fread(&s,sizeof(s),1,fp1) == 1)
    {
        if(strcmp(s.first_name,student_delete) != 0)
        {
            fwrite(&s,sizeof(s),1,ftemp);
        }
    }
            fclose(fp1);
            fclose(ftemp);
            remove("student.txt");
            rename("temp.txt","student.txt");
            printf("\nRECORD DELETED!\n");
            getch();
            menu();
}
void search_record()
{
    system("cls");
    FILE *fp1;
    char student_search[10];
    int search_flag = 1;
    fp1 = fopen("student.txt","a+");
    printf("Enter the first, last or middle name of the student you wish to search\t");
    fflush(stdin);
    gets(student_search);
    printf("\t\tNAME\t\tDOB\t\tSEX\tPHONE NO.\tGUARDIANS NO.\t\tADDRESS\t\t\tCLASS\tDIVISION\tUNIQUE ID\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n ");
    while(fread(&s,sizeof(s),1,fp1) == 1)
    {
        if((strcmp(student_search,s.first_name)==0)||(strcmp(student_search,s.middle_name)==0)||(strcmp(student_search,s.last_name)==0))
        {
            search_flag = 0;
            printf("%s\t%s\t%s\t\t%d/%d/%d\t%s\t%s\t%s\t%-30s\t%d\t%c\t\t%d\n",s.first_name,s.middle_name,s.last_name,s.dt.d,s.dt.m,s.dt.y,s.sex,s.number,s.guardian_number,s.address,s.standard,s.division,s.unique_id);
        }
    }
    if(search_flag)
    {
        printf("\nNO RECORDS FOUND!\n");
    }
    printf("\n press any key to go back to menu\n");
    getch();
    fclose(fp1);
    menu();

}

