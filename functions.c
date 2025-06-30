// bank.c
#include <stdio.h>
#include <string.h>
#include "functions.h"

void customers(customer accounts[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter ID for account %d: ", i+1);
        scanf("%d", &accounts[i].id);
        getchar();

        printf("Enter Cash for account %d: ", i+1);
        scanf("%f", &accounts[i].cash);
        getchar();

        printf("Enter Name for account %d: ", i+1);
        fgets(accounts[i].name, sizeof(accounts[i].name), stdin);
        accounts[i].name[strcspn(accounts[i].name, "\n")] = '\0';

        printf("Enter Phone for account %d: ", i+1);
        fgets(accounts[i].phone, sizeof(accounts[i].phone), stdin);
        accounts[i].phone[strcspn(accounts[i].phone, "\n")] = '\0';

        printf("-----------------------------\n");
    }
}

void search_by_id(customer accounts[], int n, int id)
{
    int found = 0;

    for(int i = 0; i < n; i++)
    {
        if(accounts[i].id == id)
        {
            printf("\n\t=== Account Details ===\n");
            printf("ID    : %d\n", accounts[i].id);
            printf("Name  : %s\n", accounts[i].name);
            printf("Cash  : %.2f\n", accounts[i].cash);
            printf("Phone : %s\n", accounts[i].phone);
            printf("===========================\n");
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("YOUR ACCOUNT IS NOT AVAILABLE.\n");
    }
}

void delete_customer(customer accounts[], int *n, int id)
{
    int found = 0;

    for(int i = 0; i < *n; i++)
    {
        if(accounts[i].id == id)
        {
            found = 1;
            for(int j = i; j < *n - 1; j++)
            {
                accounts[j] = accounts[j + 1];
            }
            (*n)--;
            printf("Customer with ID %d deleted successfully.\n", id);
            break;
        }
    }

    if(!found)
    {
        printf("Customer with ID %d not found.\n", id);
    }
}
