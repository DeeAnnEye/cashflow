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

    printf("1.Add Money\n");
    printf("2.Add Expense\n");
    printf("3.View Cashflow\n");
    
}