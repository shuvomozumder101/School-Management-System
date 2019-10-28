#include<stdio.h>
#include<conio.h>
#include<string.h>
struct pro
{
    char name[100];
    char id[20];
    char Fname[50];
    char Mname[50];
    char Address[1000];
    char phnumber[100];
};

int main()

{
    system("cls");
   system("color 0");
   struct pro s;
    int n;

     printf("\t\t\t\t-------------------------------------");
     printf("\n\t\t\t\t=<>=<>=WELCOME TO MY SOFTWARE=<>=<>= \n");
     printf("\t\t\t\t-------------------------------------");

  printf("\n\tMAIN MENU:\n");

while(1)
{
     printf("\n 1.ADD RECORD");

  printf("\n 2.VIEW RECORD");

     printf("\n 3.EDIT RECORD");

  printf("\n 4.DISPLAY");

  printf("\n 5.EXIT");

  printf("\n6.delete ");

     printf("\n ENTER YOUR CHOICE:");

  scanf("%d",&n);

    switch(n)
        {
        case 1:
            addrecord();
            break;
        case 2:
            viewrecord();
            break;
        case 3:
            editrecord();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\n \tBYE BYE....\n");
            exit(5);
            break;
        case 6:
            deleterecord();
            break;

        default:
            printf("\nWRONG KEY ...\n");
            break;
        }

}
  getch();
  return ;
}

void addrecord()

{
    system("color E");
      system("cls");
      struct pro s;
      int n;
      FILE *fp1;
      fp1=fopen("c_project.txt","ab+");

    printf("\n\t*****************************\n");
    printf("\t* WELCOME TO THE ADD RECORD *");
    printf("\n\t*****************************\n");

       printf("Enter STUDENT NAME----:");
       scanf("%s",&s.name);
       printf("Enter STUDENT ID ----:");
       scanf("%s",&s.id);
       printf("Enter FATHER NAME----:");
       scanf("%s",&s.Fname);
       printf("Enter MOTHER NAME----:");
       scanf("%s",&s.Mname);
       printf("Enter ALL ADDRESS----:");
       scanf("%s",&s.Address);
       printf("Enter PHONE NUMBER----:");
       scanf("%s",&s.phnumber);
       fflush(stdin);

       fwrite(&s,sizeof(s),1,fp1);
       fflush(stdin);

       getch();
       fclose(fp1);
       return ;
}

void viewrecord()

{
    system("color A");
    system("cls");
    struct pro s;
    FILE  *fp2;
    char id[20];
    fp2=fopen("c_project.txt","rb+");

  printf("\n\n\t\t*******************************\n");
  printf("\t\t* WELCOME TO THE VIEW RECORD *");
  printf("\n\t\t*******************************\n\n");

     printf("ENTER VIEW...\n ID==> : ");
     scanf("%s",&id);

     while (fread(&s,sizeof(s),1, fp2)==1)
{
	 if(strcmp(s.id,id)==0)
{
		printf("\n\t\t\t\tYOUR RECORD IS ");

		printf("\nID==>: %s",s.id);
		printf("\nPERSON NAME==>: %s",s.name);
		printf("\nFNAME==>: %s",s.Fname);
	    printf("\nMNAME==>: %s",s.Mname);
        printf("\nADDRESS==>: %s",s.Address);
		printf("\nPHNUMBER==>: %s",s.phnumber);
      }

      }
        fclose(fp2);

         getch();
         main();
}

void editrecord()

{
        system("color F");
        system("cls");
        struct pro s;
	    char select,id[20];
        int xx;

        FILE   *fp3;
        fp3 = fopen ("c_project.txt","rb+");
        printf("\n\n\t\t\t\t\t*******************************\n");
        printf("\t\t\t\t\t* WELCOME TO THE EDITING MENU *");
        printf("\n\t\t\t\t\t*******************************\n\n");

        printf("Enter your id:");
        scanf("%s",&id);
	do
{
	if ( fp3 == 0 )
{
		printf( "\n RECORD DOES NOT EXISTS....." );
		printf("\nPLEASE ENTER ANY KEY TO GO BACK.....");
		getch();
		return;
}
	while (fread(&s,sizeof(s),1, fp3)==1)
{
	if(strcmp(s.id,id)==0)
{
		printf("\n\t\t\t\tYOUR OLD RECORD WAS AS: ");

		printf("\n ID==>: %s",s.id);
		printf("\n NAME==>: %s",s.name);
		printf("\n FNAME==>: %s",s.Fname);
	    printf("\n MNAME==>: %s",s.Mname);
        printf("\n ADDRESS==>: %s",s.Address);
		printf("\n PHNUMBER==>: %s",s.phnumber);

		printf("\n\n\t\t\t\tWHAT YOU WANT LIKE TO EDIT...?");

		printf("\n1.ID=>");
		printf("\n2.PERSON NAME=>.");
	    printf("\n3.FNAME=>");
		printf("\n4.MNAME=>");
        printf("\n5.ADDRESS=>");
		printf("\n6.PHNUMBER=>");
		printf("\n7.WHOLE RECORD=>");
		printf("\n8.GO BACK TO MAIN MENU.");

    do
{
		printf("\n\tENTER YOUR CHOICE:");
		fflush(stdin);
	    scanf("%d",&xx);
	switch(xx)
{
    case 1:
		printf("\nENTER EDIT ID:...");
		fflush(stdin);
		printf("\nNEW ID:=>");
		gets(s.id);
    break;
    case 2:
		printf("\nENTER EDIT NAME:...");
		printf("\nPERSON NEW NAME:=>");
		fflush(stdin);
		gets(s.name);

    break;
	case 3:
	    printf("\nENTER EDIT FATHER NAME:...");
		printf("\nNEW FNAME:=>");
		fflush(stdin);
		gets(s.Fname);
    break;
	case 4:
		printf("\nENTER EDIT MOTHER NAME:...");
		printf("\nNEW MNAME:=>");
		fflush(stdin);
		gets(s.Mname);
	break;
	case 5:
		printf("ENTER EDIT ADDRESS:...");
		printf("\nADDRESS:=>");
		fflush(stdin);
		gets(s.Address);
		break;
	case 6:
		printf("ENTER EDIT PHONE NUMBER:...");
		printf("\nPHNUMBER:=>");
		fflush(stdin);
		gets(s.phnumber);
		break;
	case 7:
		printf("\nENTER YOUR NEW DATA:");

	    printf("\nNEW ID:=>");
	    fflush(stdin);
		gets(s.id);

		printf("\n PERSON NAME:=>");
		gets(s.name);
		fflush(stdin);

		printf("\n FATHER NAME:=>");
        fflush(stdin);
		gets(s.Fname);

		printf("\n MOTHER NAME:=>");
        fflush(stdin);
		gets(s.Mname);

		printf("\n ADDRESS:=>");
		fflush(stdin);
		gets(s.Address);

		printf("\nPHONE NUMBER:=>");
        fflush(stdin);
		gets(s.phnumber);
	break;

	case 8:
		printf("\nPLEASE ENTER ANY KEY TO GO BACK...\n");
		fflush(stdin);
		getch();
	 break;
	return ;

	default:
		printf("\nYOUR TYPED SOMETHING ELSE...PLEASE TRY AGAIN\n");
	break;
}
}
    while(xx<1||xx>9);

		fseek(fp3,-sizeof(s),SEEK_CUR);
		fwrite(&s,sizeof(s),1,fp3);

		fseek(fp3,-sizeof(s),SEEK_CUR);
		fread(&s,sizeof(s),1,fp3);
	    select=5;
		break;
}
}
	if(select == 5)
{
		system("cls");
		printf("\t\t =*= EDITING COMPLETED=*=...\n");
        printf("\t\t===========================\n");

		printf("\t\t------------------------\n");
		printf("\t THE NEW RECORD IS...\n");
		printf("\t\t------------------------\n");

		printf("\nID:=> %s",s.id);
		printf("\nNAME:=> %s",s.name);
		printf("\nFNAME:=> %s",s.Fname);
		printf("\nMNAME:=> %s",s.Mname);
        printf("\nADDRESS:=> %s",s.Address);
		printf("\nPHNUMBER:=> %s",s.phnumber);

		printf( "\n\n\t EDIT ANOTHER RECORD DO YOU LIKE(Y/N)?" );
		scanf("%c",&select);

		return;
}
	else
{
		printf("\n DOES NOT EXIST.....\n");
		printf("\nWOULD YOU LIKE TO TRY AGAIN.....(Y/N)");
		scanf("%c",&select);
		system("cls");
}
}
    while(select=='Y'||select=='y');

		getch();
fclose (fp3);
return;
}

display()

{
       system("color 0");
       system("cls");
       struct pro s;
       FILE *fp4;
       fp4=fopen("c_project.txt","rb+");

    printf("\t\t***************************************");
    printf("\n\t\t DISPLAY ALL STUDENTS DITELS=>=>=>\n");
    printf("\t\t***************************************");

    printf("\n||==========================||");
    printf("\n\t  ID \n\t  NAME \n\t  F-NAME \n\t  M-NAME \n\t  ADDRESS \n\t  PH-NUMBER ");
    printf("\n||==========================||\n");

        while(fread(&s,sizeof(s),1,fp4)==1)
    {
        printf("*******DITELS*******");
        printf("\n %s \n %s \n %s \n %s \n %s \n %s \n ",s.id,s.name,s.Fname,s.Mname,s.Address,s.phnumber);
        printf("******end******\n\n");
    }
      getch();
      fclose(fp4);
main();
}
