#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED


struct Customer {
    int id;
    char name[50];
    char phone[15];
    float cash;
};

void addCustomer(struct Customer customers[], int *count);
void updateCustomer(struct Customer customers[], int count);

#endif // FUNCTIONS_H_INCLUDED
