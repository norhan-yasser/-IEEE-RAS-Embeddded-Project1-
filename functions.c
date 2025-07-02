#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"



 int customerCount = 0;
 int  searchId;

struct Customer {

   int id;
   char name[50];
   double balance;
   char phone[15];
};

 struct Customer customers[100]; // 100 Max customers numbers

//function to create new customer
void  create_customer(){

    //check if customers is full
     if (customerCount >= 100) {
        printf("Customer list is full.\n");
        return;
    }

    struct Customer c; //struct to temporarily save the data

    // Loop until a valid and unique ID is entered
    while(1) {

    printf("Enter Customer ID: ");
    scanf("%d", &searchId);

    //making sure ID is only 4 digits
    if (!idCheck(searchId)) {
        printf("ID must be exactly 4 digits.\n");
        continue;
    }
      // Loop until a valid and unique ID is entered
      if (findCustomerById(searchId)!=-1){
         printf("This ID already exists .");
      } else {
          // ID is valid and unique, assign to customer
          c.id=searchId;
          break ;}

    }


    // Read customer name
    printf("Enter name: ");
    scanf(" %[^\n]", c.name);

    // Loop until a valid (positive) balance is entered
    while(1) {

    printf("Enter cash: ");
    scanf("%lf", &c.balance);


    if (c.balance <= 0) {
        printf("Cash must be positive.\n");

    }else { break ;}

    }

    // Read phone number
    printf("Enter phone: ");
    scanf(" %[^\n]", c.phone);


     // Add customer to the list and increment the counter
    customers[customerCount] = c;
    customerCount++;

    // Save to file
    saveCustomers();
    printf("Customer added successfully.\n");

}


//function to edit customer data (name,phone) by ID
void edit_customer(){

    printf("Enter customer ID to update te data : ");
    scanf("%d", &searchId);

    // Search for the customer by ID and get their index
    int index = findCustomerById(searchId);

    // If the customer is not found, print an error and return
    if( index ==-1)
    {
        printf("Customer with ID %d not found.\n", searchId);
        return;
    }

     //Read new customer name
     printf("Enter new name: ");
     scanf(" %[^\n]", customers[index].name);

     //Read new phone number
     printf("Enter new phone: ");
     scanf(" %[^\n]", customers[index].phone);

     //save changes to file
     saveCustomers();

     //inform customer the update is successfull
     printf("Customer updated.\n");
     return;

}


//Function to print customer data by ID
void print_customer_data(){


    printf("Enter customer ID to print data : ");
    scanf("%d", &searchId);

    // Search for the customer by ID and get their index
    int index = findCustomerById(searchId);

     // If the customer is not found, print an error and return
     if(index == -1)
    {
        printf("YOUR ACCOUNT IS NOT AVAILABLE.\n");
    }else {

    for(int i = 0; i < 4; i++) //printing customer data
    {

            printf("\n\t=== Account Details ===\n");
            printf("ID    : %d\n", customers[index].id);
            printf("Name  : %s\n", customers[index].name);
            printf("Cash  : %.2f\n", customers[index].balance);
            printf("phone : %s\n", customers[index].phone);
            printf("===========================\n");
            break;
    }}


}


//Function to delete customer information by ID
void delete_customer()
{
    printf("Enter customer ID to be deleted: ");
    scanf("%d", &searchId);

    // Search for the customer by ID and get their index
    int index = findCustomerById(searchId);


    // If the customer is not found, print an error and return
    if( index ==-1)
    {
        printf("Customer with ID %d not found.\n", searchId);
        return;
    }


    // Shift all customers after the deleted one to fill the gap
    for (int j = index; j < customerCount - 1; j++) {
        customers[j] = customers[j + 1];
    }

    // Decrease the total number of customers
    customerCount--;

    // Save updated customer list to file
    saveCustomers();

     // Confirm deletion
    printf("Customer deleted.\n");

}


// Function to deposit money into a customer's account
void depositMoney() {

    double amount;
    printf("Enter customer ID to deposit: ");
    scanf("%d", &searchId);

    // Search for the customer by ID and get their index
    int index = findCustomerById(searchId);

    // If the customer is not found, print an error and return
    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    // Check if the entered amount is valid (greater than 0)
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    // Add the deposit amount to the customer's balance
    customers[index].balance += amount;

    //save changes to file
    saveCustomers();

     // Confirm Transaction
    printf("Deposit successful. New balance: $%.2f\n", customers[index].balance);
}


// Function to transfer money between two customers.
void transfer_money(){

    double amount;
    printf("Enter your ID : ");
    scanf("%d", &searchId);

    // Search for the customer by ID and get their index
    int indexSender = findCustomerById(searchId);

    // If the customer is not found, print an error and return
    if (indexSender ==-1) {
        printf("Customer not found.\n");
        return;
    }

    // Ask Customer to enter receiver ID
    printf("Enter ID of the receiver:");
    scanf("%d", &searchId);

    // Search for the receiver by ID and get their index
    int indexRecievier = findCustomerById(searchId);

    if (indexRecievier ==-1) {
        printf("Customer not found.\n");
        return;
    }

    // Making sure that the customer isn't a child.
    if (customers[indexSender].id == customers[indexRecievier].id) {
        printf("Error: Cannot transfer to the same person.\n");
        return ;
    }


    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);


    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

     if (customers[indexSender].balance < amount){

        printf("Error: You don't have enough money.\n");
        return;
    }



    // If all of these doesn't exist, transfer the money.
    customers[indexSender].balance -= amount;
    customers[indexRecievier].balance += amount;

    // Printing transfer details.
    printf("Transfer sucsessful.\n");
    printf("From: %s (ID: %d)\n",  customers[indexSender].name,  customers[indexSender].id);
    printf("To: %s (ID: %d)\n", customers[indexRecievier].name, customers[indexRecievier].id);
    printf("Amount: $%.2f\n", amount);
    printf("New balance - %s: $%.2f\n", customers[indexSender].name, customers[indexSender].balance);
    printf("New balance - %s: $%.2f\n", customers[indexRecievier].name, customers[indexRecievier].balance);


}

// Function to withdraw money from a customer's account.
void withdrawMoney() {

    double amount;
    printf("Enter customer ID to withdraw: ");
    scanf("%d", &searchId);

    // Search for the customer by ID and get their index
    int index = findCustomerById(searchId);

    // If the customer is not found, print an error and return
    if (index ==-1) {
        printf("Customer not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    // Check if the entered amount is valid (greater than 0)
    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    //check if balance is more than the amount
    if (customers[index].balance < amount){

        printf("Error: You don't have enough money.\n");
        return;
    }

    //withdraw the amount from the customer's balance
    customers[index].balance -= amount;

    //save changes to file
    saveCustomers();

     // Confirm Transaction
    printf("Withdraw successful. New balance: $%.2f\n", customers[index].balance);

}


// Function to save all customer data to a text file
void saveCustomers() {

    // Open the file "customers.txt" in write mode
    FILE *customerFileP = fopen("customers.txt", "w");

    // Loop through all customers and write their data to the file
    for (int i = 0; i < customerCount; i++) {
        fprintf(customerFileP, "%d %s %.2f %s\n", customers[i].id,
                customers[i].name, customers[i].balance, customers[i].phone);
    }

    // Close the file after writing
    fclose(customerFileP);


}

// Function to load customer data from a text file into memory
void loadCustomers() {

     // Open the file "customers.txt" in read mode
    FILE *customerFileP = fopen("customers.txt", "r");


    // If the file doesn't exist, exit the function
    if (!customerFileP) return;

     // Reset customer count before loading
    customerCount = 0;

    // Read customer data line by line until the end of the file
    while (fscanf(customerFileP, "%d %s %lf %s", &customers[customerCount].id,
                  customers[customerCount].name,
                  &customers[customerCount].balance,&customers[customerCount].phone) == 4) {
        customerCount++; // Read customer data line by line until the end of the file
    }

    // Close the file after reading
    fclose(customerFileP);
}

// Function to search for a customer by their ID
// Returns the index of the customer if found, otherwise -1
int findCustomerById(int id) {

       // Loop through all customers
    for (int i = 0; i < customerCount; i++) {

        // If ID matches, return the index
        if (customers[i].id == id) return i;
    }
    return -1;
}

// Function to check if an ID is exactly 4 digits (between 1000 and 9999)
// Returns true if valid, false otherwise
 bool idCheck(int id) {

    return id >= 1000 && id <= 9999;

}
