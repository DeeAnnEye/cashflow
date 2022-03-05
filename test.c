#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *fp;
FILE *fr;

struct Cash
{
    int Income;
    int Expense;
    char Description[50];
    struct Date
    {
        int day;
        int month;
        int year;
    } date;
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
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    // input data into structure
    printf("Enter Income:");
    scanf("%d", &cash.Income);
    printf("Enter Expense:");
    scanf("%d", &cash.Expense);
    printf("Enter Description:");
    scanf("%s", &cash.Description);
    cash.date.day = tm.tm_mday;
    cash.date.month = tm.tm_mon+1;
    cash.date.year = tm.tm_year+1900;

    // file opening
    fp = fopen("datafiles/cash.txt", "a");
    if (fp == NULL)
    {
        fprintf(stderr, "\nError to open the file\n");
        exit(1);
    }
    // writing to file
    fwrite(&cash, sizeof(struct Cash), 1, fp);
    if (fwrite != 0)
        printf("Contents to file written successfully !\n");
    else
        printf("Error writing file !\n");
    fclose(fp);
    // reading data from file
    fr = fopen("datafiles/cash.txt", "r");
    while (fread(&cash, sizeof(struct Cash), 1, fr))
        printf(" income = %d expense = %d description = %s Date: %d-%d-%d\n", cash.Income, cash.Expense, cash.Description, cash.date.day,cash.date.month,cash.date.year);
    // printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    fclose(fr);
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