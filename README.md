# Accounting-system

## Problem Statement
The concept of monetary has existed since ancient times, and it takes people lots of time and effort to book-keep their financial records accurately in a manual way. Errors often occur when handling a huge amount of numerical data such as our income and expenses, since organizing and manipulating data by human alone may not be reliable. It is also difficult and time-consuming for people to monitor their financial status through manual accounting, as a great amount of records has to be carefully reviewed in order to extract only the useful financial records, and to generate the desired financial report. It is complicated for human to sort and filter their transaction records from existing handwritten financial records too. Therefore, a lot of limitations exist if people really want to manage their financial records manually.


## Scope
Personal users are the target users of this system. The accounting system keeps track of the users’ daily income and expenses from different categories, and generates different financial reports upon request. It is assumed that the system is only used by a single user during each execution, and financial records stored are all in the same currency. Only integer amounts will be accepted for simpler and better management of financial records. 


## Problem Setting
To solve the above problems, a digital accounting system is introduced to replace the traditional yet time-consuming manual book-keeping method. This new system allows registered users to manage and keep their financial records (income and expenses) on their own devices, eliminating the need of carrying a physical cashbook since the system can perform balance calculations on its own. Users, who have logged into their respective accounts, can add financial records, or to view or amend records that are previously stored in the system at any time. Records are divided into two types: income and expenses, and they must be imported to the system respectively (i.e. mixed records cannot be imported together). They can set a budget for themselves in the system, so that when their expenses reach the set budget, the system will automatically alert the users to be aware of their financial status. The system is also able to generate monthly financial reports and expenditure forecasts, based on the data stored inside the system for better control of users’ income. No internet connection is required for this system, all financial records will be stored on the users’ own devices and accounts set up are only accessible in the same device. 


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
If the option entered is '1', this function will be activated and the system will ask whether the input records belong to income or expense with the following message:

> 1: Expense
>
> 2: Income
>
> Enter 1 or 2:

Users then need to input either option '1' or '2'. Options other than these two are not accepted.

After defining the income/expense type, the system will ask whether the user wants to import multiple records from an external file, or to input single records within the system, with the following message:

> Add income and expenses records
> 
> \*******************************
>
>1: Import multiple records
>
>2: Input single record
>
>N: Exit
>
> \*******************************
> 
>Enter your option:

Users are then required to input one of the option ('1', '2' or 'N'). If the input does not belong to the three options, the system will prompt the user to re-enter their option until it gets a valid input, with the following message:

> Invalid input! Please input again!

#### Option 1: Import multiple records
If option '1' is entered, the system will prompt the user to enter the filename of the file that stores the financial records, with the following message:

> Enter the filename of import file:

If the file with the entered filename cannot be found, the system will output the following message and quit the whole system immediately to avoid further error:

> Failed to open (filename.txt). Cannot get data from file.

But if the file can be found and are in the correct import format (see appendix 1), the financial records will be added to the accounting system and will be sorted according to the record date. Users will be headed back to the main menu after the following message is shown:

> Records are successfully imported.

#### Option 2: Input single record
If option '2' is entered, the system will prompt the user to enter a single record with the following message:

> Please enter date, amount, type and account according to the format below.
> 
> YYYYMMDD AMOUNT TYPE ACCOUNT

If the chosen record type is expense (1), the following reminder will be displayed:

>> Please enter the short form for type and account.
>>
>> Type: FD(Food), TS(Transportation), EN(Entertainment), UB(Utility Bills), OT(Others)
>>
>> Account: CA(Cash), BC(Bank Card), OT(Others)

If the chosen record type is income (2), the following reminder will be displayed:

>> Please enter the short form for type and account.
>>
>> Type: FT(Full-time), PT(Part-time), OT(Others)
>>
>> Account: CA(Cash), BC(Bank Card), OT(Others)

Users now can input the records according the formats specified above. For example:

>>> For expense:
>>> 
>>> 20190427 13 FD CA

>>> For income:
>>>
>>> 20190427 500 PT OT

Please be reminded that the amount entered can only be in integer form.

After the record is successfully added, the following message will be displayed and users will be brought back to the main menu:

> Record is successfully added.

#### Option N: Exit
If option 'N' is entered, user will be brought back to the main menu after the following message is shown:

> Back to the menu

### 2: Delete records
If the option entered is '2', this function will be activated and the system will ask whether the record to be deleted belongs to income or expense with the following message:

> 1: Expense
>
> 2: Income
>
> Enter 1 or 2:

Users then need to input either option '1' or '2'. Options other than these two are not accepted.

After defining the income/expense type, the system will proceed to the next step to check if there are any existing records stored inside the system.

If there are no records, the following message will be displayed and users will be then brought back to the main menu:

> There is no (expense/income) record. Delete function is not available yet.

But if there are records stored inside the system, the system will prompt the user to search for a certain record with the following message:

> Please enter a key word for searching

Users can then input their search keyword, which can be the date, amount, type or account. There is no limitation for the searching keyword. After inputting, the system will return the search results sorted by date as below:

> An example of searching for expense with keyword 'FD'
>>
>> 0: 20181010 10 FD CA
>>
>> 1: 20181215 500 FD BC
>>
>> 2: 20190420 65 FD OT
>>
>> Number you want to delete

Then, user are required to select the record to be deleted by entering the corresponding number. For example, if '2' is entered, the record '20190420 65 FD OT' will then be deleted from the accounting system. This action is not reversible.

However, if there are no results matching the entered keyword, the following message will be shown and users will be brought back to the main menu immediately:

> Cannot find a record that matches the key word!

### 3: Edit records
If the option entered is '3', this function will be activated and the system will ask whether the record to be edited belongs to income or expense with the following message:

> 1: Expense
>
> 2: Income
>
> Enter 1 or 2:

Users then need to input either option '1' or '2'. Options other than these two are not accepted.

After defining the income/expense type, the system will proceed to the next step to check if there are any existing records stored inside the system.

If there are no records, the following message will be displayed and users will be then brought back to the main menu:

> There is no (expense/income) record. Edit function is not available yet.

But if there are records stored inside the system, the system will prompt the user to search for the record they would like to edit with the following message:

> Please enter a key word for searching

Users can then input their search keyword, which can be the date, amount, type or account, to find and edit their record. There is no limitation for the searching keyword.

For the next steps, please refer to the guide of 'Delete' and 'Add' respectively, since 'Edit' is an integrated function of 'Delete' and 'Add'.

### 4: View previous records
If the option entered is '4', this function will be activated and the system will display all the stored records sorted by date in the following format:

> Example
>>
>> Expense:
>>
>> Date      Amount    Type      Account    
>>
>> 20180123  10        TS        CA        
>>
>> 20181010  10        FD        CA
>>
>> 20181215  500       FD        BC
>>
>> 20190420  65        FD        OT
>>
>>
>> Income:
>>
>> Date      Amount    Type      Account    
>>
>> 20181210  500       PT        CA
>>
>> 20190110  10000     FT        BC
>>
>> 20190125  400       OT        OT

After showing all records, the users will be brought back to the main menu automatically.

### 5: Generate statistical report
### 6: Set budget
### 7: Generate financial forecast

## Compilation and Execution Instructions
Before compiling and executing the program, please download 'Makefile' and '______.cpp' to the same directory on your device. Make sure you have a complier installed on your device, for example, Terminal, before proceeding to the next steps.
### To compile the program
In your complier, enter the following command:

make (name)

The program should be successfully complied.
### To execute the program
In your complier, enter the following command:

./(name)

The program should then be executing in your complier and accepting user input immediately.

## Appendix
