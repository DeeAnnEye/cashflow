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
    printf("\n\t\t **** CASHFLOW MANAGER ****");
    printf("\n\t ---------------------------------------------------\t\t\n");
}

// main menu function
void mainmenu()
{
    printf("\n\nChoose an option:\n\n");
    printf("\t1.Add Income\n");
    printf("\t2.Add Expense\n");
    printf("\t3.View Cashflow\n");
    printf("\t4.Delete Cashflow\n");
}

// cashview menu
void cashviewmenu()
{
    printf("\nChoose an option:\n\n");
    printf("\t1.View all Cashflow logs\n");
    printf("\t2.View logs by Month\n");
    printf("\t3.Calculate Cashflow for Month\n");
}

// main menu function
void monthselector()
{
    printf("\nSelect Month to view Cashflow:\n\n");
    printf("\t1.Jan");
    printf("\t2.Feb");
    printf("\t3.Mar\n");
    printf("\t4.Apr");
    printf("\t5.May");
    printf("\t6.Jun\n");
    printf("\t7.Jul");
    printf("\t8.Aug");
    printf("\t9.Sept\n");
    printf("\t10.Oct");
    printf("\t11.Nov");
    printf("\t12.Dec\n");
}

// delete menu
void deletemenu()
{
    printf("\n\nChoose an option:\n\n");
    printf("\t1.Delete Cashflow by Date\n");
    printf("\t2.Delete Cashflow by Month\n");
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
    scanf(" %[^\n]s", &cash.Description);
    cash.date.day = tm.tm_mday;
    cash.date.month = tm.tm_mon + 1;
    cash.date.year = tm.tm_year + 1900;

    // file opening
    fp = fopen("cash.txt", "a");
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
    scanf(" %[^\n]s", &cash.Description);
    cash.date.day = tm.tm_mday;
    cash.date.month = tm.tm_mon + 1;
    cash.date.year = tm.tm_year + 1900;

    // file opening
    fp = fopen("cash.txt", "a");
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
    int n, m, k = 0, income = 0, expense = 0;
    cashviewmenu();
    printf("\nEnter your choice:");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        // reading data from file
        fr = fopen("cash.txt", "r");
        while (fread(&cash, sizeof(struct Cash), 1, fr))
        {
            printf("\n-------------------------------------------------------------------------------------\n");
            (cash.Income == 0) ? printf("| Income = NIL ") : printf("| Income = %d ", cash.Income);
            (cash.Expense == 0) ? printf("| Expense = NIL ") : printf("| Expense = %d ", cash.Expense);
            printf("| Description = %s | Date: %d-%d-%d\n", cash.Description, cash.date.day, cash.date.month, cash.date.year);
            // printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        }
        fclose(fr);
        break;
    case 2:
        monthselector();
        printf("\nEnter your choice:");
        scanf("%d", &m);

        // check month exists
        fr = fopen("cash.txt", "r");
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
        fr = fopen("cash.txt", "r");
        if (k > 0)
        {
            while (fread(&cash, sizeof(struct Cash), 1, fr))
            {
                if (m == cash.date.month)
                {
                    printf("\n-------------------------------------------------------------------------------------\n");
                    (cash.Income == 0) ? printf("| Income = NIL ") : printf("| Income = %d ", cash.Income);
                    (cash.Expense == 0) ? printf("| Expense = NIL ") : printf("| Expense = %d ", cash.Expense);
                    printf("| Description = %s | Date: %d-%d-%d\n", cash.Description, cash.date.day, cash.date.month, cash.date.year);
                }
                // printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
            }
        }
        else
        {
            printf("No Cashflow for selected month.");
        }
        fclose(fr);
        break;
    case 3:
        monthselector();
        printf("\nEnter your choice:");
        scanf("%d", &m);

        // check month exists
        fr = fopen("cash.txt", "r");
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
        fr = fopen("cash.txt", "r");
        if (k > 0)
        {
            while (fread(&cash, sizeof(struct Cash), 1, fr))
            {
                if (m == cash.date.month)
                {
                    income = income + cash.Income;

                    expense = expense + cash.Expense;
                }
                // printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
            }
            printf("\nTotal Income this month: %d", income);
            printf("\nTotal Expense this month: %d", expense);
        }
        else
        {
            printf("\nNo Cashflow for selected month.\n");
        }

        if (expense > income)
        {
            printf("\n Cash spent in Excess.\n");
        }
        else
        {
            if (income == 0 && expense == 0)
            {
                break;
            }
            else
            {
                printf("\nCash spent within limit.\n");
            }
        }
        fclose(fr);

        break;
    default:
        printf("Invalid option");
        break;
    }
}
void deletecash(struct Cash cash)
{
    int d, m, y, n;
    deletemenu();
    printf("\nEnter your choice:");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("\nEnter Date,Month,Year(DD M YYYY) of cashflow to delete:");
        scanf("%d %d %d", &d, &m, &y);
        // printf("%d %d %d", d, m, y);
        // scanf("%d",&m);

        fr = fopen("cash.txt", "r");
        fp = fopen("temp.txt", "w");
        while (fread(&cash, sizeof(struct Cash), 1, fr))
        {
            if (d != cash.date.day && m != cash.date.month && y != cash.date.year)
            {
                fwrite(&cash, sizeof(cash), 1, fp);
            }
        }
        fclose(fr);

        fclose(fp);
        remove("cash.txt");

        rename("temp.txt", "cash.txt");
        printf("\nCashflow deleted.");
    }
    else if (n == 2)
    {
        printf("\nEnter Month,Year(M YYYY) of cashflow to delete:");
        scanf("%d %d", &m, &y);

        fr = fopen("cash.txt", "r");
        fp = fopen("temp.txt", "w");
        while (fread(&cash, sizeof(struct Cash), 1, fr))
        {
            if (m != cash.date.month && y != cash.date.year)
            {
                fwrite(&cash, sizeof(cash), 1, fp);
            }
        }
        fclose(fr);

        fclose(fp);
        remove("cash.txt");

        rename("temp.txt", "cash.txt");
        printf("\nCashflow deleted.");
    }
    else
    {
        printf("\nInvalid Choice.\n");
    }
}
// CASH functions end

int main()
{
menu:
    system("cls");
    // Header
    header();
    int n;
    struct Cash cash;

    mainmenu();
    printf("\nEnter your choice:");
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
    case 4:
        deletecash(cash);
        break;
    default:
        printf("Invalid option");
        break;
    }
    printf("\n (1) Main menu\n (0) Exit\n");
    printf("\nEnter your choice:");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        goto menu;
    case 0:
        break;
    default:
        printf("Invalid choice");
        break;
    }
}