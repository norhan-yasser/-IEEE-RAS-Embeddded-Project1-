#include <stdio.h>
#include <string.h>
#include "functions.h"

// Function to Add new costomer.


void addCustomer(struct Customer customers[], int *count) {
    if (*count >= 100) {
        printf("Customer list is full.\n");
        return;
    }

    struct Customer c;

    printf("Enter Customer ID: ");
    scanf("%d", &c.id);

    printf("Enter name: ");
    scanf(" %[^\n]", c.name);

    printf("Enter phone: ");
    scanf(" %[^\n]", c.phone);

    printf("Enter cash: ");
    scanf("%f", &c.cash);

    if (c.cash < 0) {
        printf("Cash must be positive.\n");
        return;
    }

    customers[*count] = c;
    (*count)++;

    printf("Customer added successfully.\n");
}

// Function to update customer.

void updateCustomer(struct Customer customers[], int count) {
    int id, found = 0;
    printf("Enter Customer ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            found = 1;

            printf("Enter new name: ");
            scanf(" %[^\n]", customers[i].name);

            printf("Enter new phone: ");
            scanf(" %[^\n]", customers[i].phone);

            printf("Customer updated.\n");
            return;
        }
    }
    if (!found) {
        printf("Customer with ID %d not found.\n", id);
    }
}
