#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

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
void addmoney(struct Cash c)
{
    char desc[20];
    fp = fopen("./datafiles/cash.txt", "a");
    if (fp == NULL)
        {
            fprintf(stderr, "\nError opened file\n");
            exit (1);
        }
    c.Income = 1334;
    c.Expense = 0;
    strcpy(c.Description, "wdl"); 
    // c.Description = desc;
    fwrite (&c, sizeof(struct Cash), 1, fp);
    if(fwrite != 0)
            printf("Entry Added\n");
        else
            printf("Error writing entry !\n");
    while(fread(&c, sizeof(struct Cash), 1, fp))
        printf ("income = %d expense = %d description = %s \n", c.Income,
        c.Expense, c.Description);
 
    fclose(fp);
}

int main()
{
    // Header
    header();
    int n;

    struct Cash c;

    printf("Choose an option:\n\n");
    printf("1.Add Money\n");
    printf("2.Add Expense\n");
    printf("3.View Cashflow\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Add money");
        addmoney(c);
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