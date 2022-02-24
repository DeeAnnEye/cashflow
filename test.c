#include <stdio.h>
#include <stdlib.h>

FILE *fp;
// header function
void header()
{
    printf("\n\t\t\t\033[1m        WELCOME TO CASHFLOW \033[0m\n");
    printf("\t\t\t   -----------------------------\t\t\n");
}
void addmoney()
{
    fp = fopen("./datafiles/cash.txt", "a");
    fputs("Hello world\n", fp);
    fclose(fp);
}

int main()
{
    // Header
    header();
    int n;
    printf("Choose an option:\n\n");
    printf("1.Add Money\n");
    printf("2.Add Expense\n");
    printf("3.View Cashflow\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Add money");
        addmoney();
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