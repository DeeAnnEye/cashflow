#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;
FILE *fr;

struct Cash
{
    int Income;
    int Expense;
    char Description[50];
};

// header function
void header()
{
    printf("\n\t\t\t\033[1m        WELCOME TO CASHFLOW \033[0m\n");
    printf("\t\t\t   -----------------------------\t\t\n");
}

void mainmenu()
{
    printf("Choose an option:\n\n");
    printf("1.Add Money\n");
    printf("2.Add Expense\n");
    printf("3.View Cashflow\n");
}
void addmoney(struct Cash cash)
{
   printf("Enter Income:");
   scanf("%d",&cash.Income);
   printf("Enter Expense:");
   scanf("%d",&cash.Expense);
   printf("Enter Description:");
   scanf("%s",&cash.Description);

   fp= fopen ("datafiles/cash.txt", "a");
   if (fp == NULL) {
      fprintf(stderr, "\nError to open the file\n");
      exit (1);
   }
    fwrite (&cash, sizeof(struct Cash), 1, fp);
   if(fwrite != 0)
      printf("Contents to file written successfully !\n");
   else
      printf("Error writing file !\n");
   fclose (fp);
//    fr= fopen ("datafiles/cash.txt", "r");
//     while(fread(&cash, sizeof(struct Cash), 1, fr))
//       printf (" income = %d expense = %d description = %s\n", cash.Income, cash.Expense, cash.Description);
//    fclose (fr);
}

int main()
{
    // Header
    header();
    int n;
    struct Cash cash;
    
    mainmenu();
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        addmoney(cash);
        break;
    case 2:
        printf("Add Expense");
        break;
    case 3:
        printf("View Cashflow");
        break;
    default:
        printf("Invalid option");
        break;
    }
}