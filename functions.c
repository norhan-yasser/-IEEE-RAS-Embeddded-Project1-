#include <stdio.h>
#include <string.h>
#include <stdbool.h>



 int customerCount = 0;

struct Customer {

   int id;
   char name[50];
   double balance;

};

 struct Customer customers[60];


void  create_customer(){


}

void edit_customer(){


}

void print_customer_data(){

    int searchId;
    printf("Enter customer ID to print data : ");
    scanf("%d", &searchId);
    int index = findCustomerById(searchId);

     if(index == -1)
    {
        printf("YOUR ACCOUNT IS NOT AVAILABLE.\n");
    }else {

    for(int i = 0; i < 4; i++)
    {

            printf("\n\t=== Account Details ===\n");
            printf("ID    : %d\n", customers[index].id);
            printf("Name  : %s\n", customers[index].name);
            printf("Cash  : %.2f\n", customers[index].balance);
            printf("===========================\n");
            break;
    }}


}

void delete_customer()
{   int searchId;
    printf("Enter customer ID to be deleted: ");
    scanf("%d", &searchId);
    int index = findCustomerById(searchId);

    if( index ==-1)
    {
        printf("Customer with ID %d not found.\n", searchId);
        return;
    }

    for (int j = index; j < customerCount - 1; j++) {
        customers[j] = customers[j + 1];
    }
    customerCount--;
    saveCustomers();
    printf("Customer deleted.\n");

}

void depositMoney() {
    int id;
    double amount;
    printf("Enter customer ID to deposit: ");
    scanf("%d", &id);
    int index = findCustomerById(id);
    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    customers[index].balance += amount;
    saveCustomers();
    printf("Deposit successful. New balance: $%.2f\n", customers[index].balance);
}


/*// Function to transfer money between two customers.
bool transfer_money(struct customer *sender, struct customer *receiver, double amount){

    // Making sure that the customers are invalid.
    if (sender == NULL || receiver == NULL){
        printf("Error: Invalid sender or receiver.\n");
        return 0;
    }

    // Making sure that the amount is > 0.
    if (amount <= 0){
        printf("Error: Transfer amount must be positive.\n");
        return 0;
    }

    // Making sure that the sender have an enough money.
    if (amount > sender->balance){
        printf("Error: You don't have enough money.\n");
        return 0;
    }

    // Making sure that the customer isn't a child.
    if (sender->id == receiver->id) {
        printf("Error: Cannot transfer to the same person.\n");
        return 0;
    }

    // If all of these doesn't exist, transfer the money.
    sender->balance -= amount;
    receiver->balance += amount;

    // Printing transfer details.
    printf("Transfer sucsessful.\n");
    printf("From: %s (ID: %d)\n", sender->name, sender->id);
    printf("To: %s (ID: %d)\n", receiver->name, receiver->id);
    printf("Amount: $%.2f\n", amount);
    printf("New balance - %s: $%.2f\n", sender->name, sender->balance);
    printf("New balance - %s: $%.2f\n", receiver->name, receiver->balance);

    return 1;
}*/

// Function to withdraw money from a customer's account.
void withdrawMoney() {
     int id;
    double amount;
    printf("Enter customer ID to withdraw: ");
    scanf("%d", &id);
    int index = findCustomerById(id);
    if (index ==-1) {
        printf("Customer not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    if (customers[index].balance < amount){

        printf("Error: You don't have enough money.\n");
        return;
    }

    customers[index].balance -= amount;
    saveCustomers();
    printf("Deposit successful. New balance: $%.2f\n", customers[index].balance);

}


void saveCustomers() {
    FILE *customerFileP = fopen("customers.txt", "w");
    for (int i = 0; i < customerCount; i++) {
        fprintf(customerFileP, "%d %s %.2f\n", customers[i].id,
                customers[i].name, customers[i].balance);
    }
    fclose(customerFileP);


}


void loadCustomers() {
    FILE *customerFileP = fopen("customers.txt", "r");
    if (!customerFileP) return;

    customerCount = 0;
    while (fscanf(customerFileP, "%d %s %lf", &customers[customerCount].id,
                  customers[customerCount].name,
                  &customers[customerCount].balance) == 3) {
        customerCount++;
    }
    fclose(customerFileP);
}


int findCustomerById(int id) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == id) return i;
    }
    return -1;
}
