#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"


int main()
{
   loadCustomers();
   int option;

   printf("\n");
   printf("\t\t\t Welcome to Banque Ras \n");
   printf("\t\t-------------------------------------\n");
   printf("\t\t1.create customer\n");
   printf("\t\t2.edit_customer \n");
   printf("\t\t3.print_customer_data \n");
   printf("\t\t4.delete_customer \n");
   printf("\t\t5.deposit\n");
   printf("\t\t6.money_transfer\n");
   printf("\t\t7.withdraw\n");
   printf("\t\t8.Exit\n\n");

   while(1){

   printf("\t\tEnter your option ");
   scanf("%d",&option);

   switch (option) {
     case 1 :
        create_customer();
        break;
     case 2 :
        edit_customer();
        break;
     case 3 :
        print_customer_data();
        break;
     case 4 :
        delete_customer();
        break;
     case 5 :
         depositMoney();
         break;
     case 6 :
         transfer_money();
         break;
     case 7 :
         withdrawMoney();
         break;
     case 8 :
          return 0 ;
     default :
        printf("\n\t\tInvalid option , please choose from the menu\n");
        break;

   } }

     return 0 ;
};


