#include <stdio.h>

//header function
void header(){
    printf("\n\t\t\t\033[1m        WELCOME TO CASHFLOW \033[0m\n");
    printf("\t\t\t   -----------------------------\t\t\n");
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
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        printf("Add money");
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