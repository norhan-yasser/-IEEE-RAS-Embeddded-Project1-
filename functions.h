// bank.h
#ifndef BANK_H
#define BANK_H

typedef struct 
{
    int id;
    float cash;
    char name[100];
    char phone[15];
} customer;

void customers(customer accounts[], int n);
void search_by_id(customer accounts[], int n, int id);
void delete_customer(customer accounts[], int *n, int id);

#endif
