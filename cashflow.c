#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *fp;
FILE *fr;

// cash structure
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
// cash structure end

// UTILITY functions

// header function
void header()
{
    printf("\n\t\t\t\033[1m        WELCOME TO CASHFLOW \033[0m\n");
    printf("\t\t\t   -----------------------------\t\t\n");
}

// main menu function
void mainmenu()
{
    printf("Choose an option:\n\n");
    printf("1.Add Money\n");
    printf("2.Add Expense\n");
    printf("3.View Cashflow\n");
}

// cashview menu
void cashviewmenu()
{
    printf("Choose an option:\n\n");
    printf("1.View all Cashflow logs\n");
    printf("2.View logs by Date\n");
    printf("3.Calculate Cashflow for Month\n");
}

// main menu function
void monthselector()
{
    printf("Select Month to view Cashflow:\n\n");
    printf("1.Jan\n");
    printf("2.Feb\n");
    printf("3.Mar\n");
    printf("4.Apr\n");
    printf("5.May\n");
    printf("6.Jun\n");
    printf("7.Jul\n");
    printf("8.Aug\n");
    printf("9.Sept\n");
    printf("10.Oct\n");
    printf("11.Nov\n");
    printf("12.Dec\n");
}
// UTILITY end

// CASH functions
void addincome(struct Cash cash)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    // input data into structure
    printf("Enter Income:");
    scanf("%d", &cash.Income);
    cash.Expense = 0;
    printf("Enter Description:");
    scanf("%s", &cash.Description);
    cash.date.day = tm.tm_mday;
    cash.date.month = tm.tm_mon + 1;
    cash.date.year = tm.tm_year + 1900;

    // file opening
    fp = fopen("datafiles/cash.txt", "a");
    if (fp == NULL)
    {
        fprintf(stderr, "\nError opening cash log\n");
        exit(1);
    }
    // writing to file
    fwrite(&cash, sizeof(struct Cash), 1, fp);
    if (fwrite != 0)
        printf("Added Cash Income.\n");
    else
        printf("Couldn't add income!\n");
    fclose(fp);
}
void addexpense(struct Cash cash)
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    // input data into structure
    cash.Income = 0;
    printf("Enter Expense:");
    scanf("%d", &cash.Expense);
    printf("Enter Description:");
    scanf("%s", &cash.Description);
    cash.date.day = tm.tm_mday;
    cash.date.month = tm.tm_mon + 1;
    cash.date.year = tm.tm_year + 1900;

    // file opening
    fp = fopen("datafiles/cash.txt", "a");
    if (fp == NULL)
    {
        fprintf(stderr, "\nError opening cash log\n");
        exit(1);
    }
    // writing to file
    fwrite(&cash, sizeof(struct Cash), 1, fp);
    if (fwrite != 0)
        printf("Added Cash Expense.\n");
    else
        printf("Couldn't add expense!\n");
    fclose(fp);
}
void viewcash(struct Cash cash)
{
    int n;
    cashviewmenu();
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        // reading data from file
        fr = fopen("datafiles/cash.txt", "r");
        while (fread(&cash, sizeof(struct Cash), 1, fr))
        {
            (cash.Income == 0) ? printf("Income = NIL ") : printf("Income = %d ", cash.Income);
            (cash.Expense == 0) ? printf("Expense = NIL ") : printf("Expense = %d ", cash.Expense);
            printf("Description = %s Date: %d-%d-%d\n", cash.Description, cash.date.day, cash.date.month, cash.date.year);
            // printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        }
        fclose(fr);
        break;
    case 2:
        int m, k = 0;
        monthselector();
        scanf("%d", &m);


        // check month exists
        fr = fopen("datafiles/cash.txt", "r");
        while (fread(&cash, sizeof(struct Cash), 1, fr))
        {
            if (m == cash.date.month)
            {
                k = k + 1;
            }
        }
        // printf("%d\n", k);
        fclose(fr);

        // read data from file
        fr = fopen("datafiles/cash.txt", "r");
        if(k>0){
        while (fread(&cash, sizeof(struct Cash), 1, fr))
        {
                if (m == cash.date.month)
                {
                    (cash.Income == 0) ? printf("Income = NIL ") : printf("Income = %d ", cash.Income);
                    (cash.Expense == 0) ? printf("Expense = NIL ") : printf("Expense = %d ", cash.Expense);
                    printf("Description = %s Date: %d-%d-%d\n", cash.Description, cash.date.day, cash.date.month, cash.date.year);
                }
            // printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        }
        }else{
            printf("No Cashflow for selected month.");
        }
        fclose(fr);
        break;
    case 3:
        monthselector();
        scanf("%d", &m);
        break;
    default:
        printf("Invalid option");
        break;
    }
}
// CASH functions end

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
        addincome(cash);
        break;
    case 2:
        addexpense(cash);
        break;
    case 3:
        viewcash(cash);
        break;
    default:
        printf("Invalid option");
        break;
    }
}