# Accounting-system

## Problem Statement
The concept of monetary has existed since ancient times, and it takes people lots of time and effort to book-keep their financial records accurately in a manual way. Errors often occur when handling a huge amount of numerical data such as our income and expenses, since organizing and manipulating data by human alone may not be reliable. It is also difficult and time-consuming for people to monitor their financial status through manual accounting, as a great amount of records has to be carefully reviewed in order to extract only the useful financial records, and to generate the desired financial report. It is complicated for human to sort and filter their transaction records from existing handwritten financial records too. Therefore, a lot of limitations exist if people really want to manage their financial records manually.

## Scope
Personal users are the target users of this system. The accounting system keeps track of the users’ daily income and expenses from different categories, and generates different financial reports upon request. It is assumed that the system is only used by a single user during each execution, and financial records stored are all in the same currency. Only integer amounts will be accepted for simpler and better management of financial records. 

## Problem Setting
To solve the above problems, a digital accounting system is introduced to replace the traditional yet time-consuming manual book-keeping method. This new system allows registered users to manage and keep their financial records (income and expenses) on their own devices, eliminating the need of carrying a physical cashbook since the system can perform balance calculations on its own. Users, who have logged into their respective accounts, can add financial records, or to view or amend records that are previously stored in the system at any time. They can set a budget for themselves in the system, so that when their expenses reach the set budget, the system will automatically alert the users to be aware of their financial status. The system is also able to generate monthly financial reports and expenditure forecasts, based on the data stored inside the system for better control of users’ income. No internet connection is required for this system, all financial records will be stored on the users’ own devices and accounts set up are only accessible in the same device. 

## Program Functionalities and Features
The newly developed accounting program includes the following functions:
After new users have created a new account / existing users have successfully logged into their accounts, they will be able to:
1. to add records of income and expenses, which contain general information like the amount received/spent, the date of transaction, the type of income/expenses and the corresponding financial account involved;
2. to delete any records that are previously added to the system;
3. to edit any records that are previously added to the system;
4. to view the stored financial records sorted or filtered by different criteria;
5. to generate monthly statistical report of the users’ financial state upon request;
6. to set a budget for the users’ expenses and alert them when their expenses reach the set budget; and
7. to forecast the income and expenses for the next time period based on the previous financial records stored in the system.

##  Input / Output Specifications
The following input guidelines must be strictly followed when using the program functions in order to generate outputs displayed in correct formats. 
### 1: Add income and expenses records
### 2: Delete records
### 3: Edit records
### 4: View previous records
### 5: Generate statistical report
### 6: Set budget
### 7: Generate financial forecast

## Compliation and Execution Instructions
Before compling and executing the program, please download 'Makefile' and '______.cpp' to the same directory on your device. Make sure you have a complier installed on your device, for example, Terminal, before proceeding to the next steps.
### To compile the program
In your complier, enter the following command:
make (name)
The program should be successfully complied.
### To execute the program
In your complier, enter the following command:
./(name)
The program should then be executing and accepting user input immediately.
