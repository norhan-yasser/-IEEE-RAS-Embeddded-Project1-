// main.c
#include <stdio.h>
#include "functions.h"

int main()
{
    int n, id;

    printf("Enter number of accounts: ");
    scanf("%d", &n);
    getchar();

    if (n <= 0)
    {
        printf("Invalid number of accounts.\n");
        return 1;
    }

    customer accounts[n];
    customers(accounts, n);

    printf("\n--- Search Phase ---\n");
    printf("Enter ID to search: ");
    scanf("%d", &id);
    getchar();
    search_by_id(accounts, n, id);

    printf("\n--- Deletion Phase ---\n");
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    getchar();
    delete_customer(accounts, &n, id);

    printf("\n--- New List After Deletion ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("Account %d - ID: %d, Name: %s, Cash: %.2f, Phone: %s\n",
               i + 1, accounts[i].id, accounts[i].name, accounts[i].cash, accounts[i].phone);
    }

    return 0;
}
