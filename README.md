# Banque Ras - C Bank Management System

## Overview

**Banque Ras** is a simple terminal-based bank management system written in C.  
It allows users to manage customer records, including creating accounts, editing details, performing transactions, and saving data persistently using text files.  
This project demonstrates essential C programming concepts such as `structs`, file I/O, modular design using header/source files, and input validation.

---

## Features

- Create a new customer with a unique 4-digit ID
- Edit customer information (name and phone)
- View customer account details
- Deposit and withdraw money
- Transfer funds between accounts
- Delete customer records
- Data persistence through file saving and loading

---

## Technologies Used

- Language: C
- Tools: Any C-compatible IDE (e.g., Code::Blocks, Visual Studio Code, Dev-C++)
- File Handling: Standard C file I/O (`fopen`, `fprintf`, `fscanf`, `fclose`)

---

## Project Structure

- `main.c` – Entry point and menu
- `functions.h` – Function declarations (header file)
- `functions.c` – Core logic and functionality
- `customers.txt` – Data file for customer records

---

## How to Run

1. **Compile the program** using GCC:
   ```bash
   gcc main.c functions.c -o banque_ras


## Run the program:

./banque_ras

## Data File Format
Customer data is stored in customers.txt in this format:
<id> <name> <balance> <phone>

## Example:
1001 Ahmed 2500.50 01012345678

## Input Validations
- ID must be exactly 4 digits (1000–9999)
- Maximum 3 attempts for entering IDs in key operations

**Validations include:**
- Preventing duplicate IDs
- Avoiding overdraft on withdrawals
- Preventing transfers to the same account
- Accepting only positive values for money transactions

  ## Sample Menu
               Welcome to Banque Ras 
    -------------------------------------
    1. Create Customer
    2. Edit Customer
    3. Print Customer Data
    4. Delete Customer
    5. Deposit
    6. Money Transfer
    7. Withdraw
    8. Exit


## Strengths of the Project
- Modular and organized code (separates logic from UI)
- Well-structured input validation and user guidance
- Persistent data storage via file system
- Clear and consistent coding style with comments
- Easily extensible with additional features

## Authors
- Norhan yasser
- Abdelrahman Mohamed
- Aya Ali
- Ahmed Shehata


