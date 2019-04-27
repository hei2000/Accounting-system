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
After executing the program, the system will prompt the user to log in to their accounts, or to create new accounts to use the service with the following message:

> Enter 1 to login
>
> Enter 2 to create new account

Users can only input either '1' or '2', then press 'Enter' to proceed to the next stage. Characters other than '1' or '2' are not accepted and message "Invalid input! Please enter again!" will be shown if they are entered. Users will be required to input their option again until their input is either '1' or '2'.

### Log in to user accounts
If the users input '1', the system will prompt the user to log in to their accounts with the following message:

> Please enter your user name!

Users are required to input their username, which is in the form of string, at this stage. It is assumed that only registered users will be logging into their accounts.
After inputting the user name and pressing 'Enter', the system will prompt the user to enter their password with the following message:

> Please enter your password!

Users then need to enter their password in order to successfully log into the system. The password entered will then be checked with the information stored inside the accounting system, and if the password does not match with the record, the system will prompt the user to re-enter their password until it is correct with the following message:

> Wrong password! Please enter your password again!

If the above message is not shown, it means that the user has already logged into the system successfully and the menu should be displayed immediately. Existing users will be able to retrieve previous financial records stored inside the system after logging in.

### Create new user accounts
If the users input '2', the system will prompt the user to create a new account with the following message:

> Please enter your user name!

Users are required to input a new username, which is in the form of string at this stage.
After inputting the username and pressing 'Enter', the system will prompt the user to create a password with the following message:

> Please enter your password!

The password entered should be in the form of string and there are no limitations on the choice of characters used in the password.

After pressing 'Enter', a new user account is then created for the new user and they are now able to use the accounting system. The menu should then be displayed immediately.

### Menu and Selecting Functions
After successful log-ins, the menu will be immediately displayed in the below format:

> Welcome to your accounting system!
>
> 
> ************** Menu **************
>
> 
> 1: Add income and expenses records
>
> 2: Delete records
>
> 3: Edit records
>
> 4: View previous records
>
> 5: Generate statistical report
>
> 6: Set budget
>
> 7: Generate financial forecast
>
> 
> N: Exit
>
>
> \**********************************
>
>
> Enter your option:

Users then need to input their option (from '1' to '7', or 'N') to the system in one single character. Characters other than the above eight options are not accepted and the system will prompt the user to enter their option again with the following message:

> Invalid input! Please input again!

After the system has received a valid input, the corresponding function will then be activated and users will proceed to the next steps. 

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

The program should then be executing in your complier and accepting user input immediately.
