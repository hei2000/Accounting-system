#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

struct record{
  string date;
  string amount;
  string type;
  string account;
  record * next;
};

//Output: return current date in the form of YYYYMMDD
string getdate();
//Function: print the date,amount,type and account of the given linked list pointer
//Input: head of income/expense linked list pointer
void view(record * rec);
//Function: Open the corresponding user's file that stored previous record.
//          Copy all data in the file to the corresponding linked list
//Input: user name, income/expense linked list pointer, X(expense) or I(income)

string getdata(string name,record *& rec,string X_I);
//Function: Login and check its password / create a new account
//          If the user had a account already, get data from the corresponding file throught the function getdata()
//Input: a string to store username, a string to store user's password, two empty record(struct) pointer to get data from different files
//Output: return the password of the user account
void login(string & name, string & password,record *& rec_X,record *& rec_I);
//Function: print a menu to guide the user

void printmenu();
//Input: Date of spending or earning,record pointer of linked list
//Output: return a record pointer point just ranked before the new data in chronological order
record * findpos(string date,record * rec);
//Function: insert the data to the linked list after the record pointer "after"
//Input: a record pointer points to the location before the date of spending/earning in chronological order
//        ,data to insert,the linked list to be inserted
void insert(record *& after,string input,record *& rec);
//Function: Print the input format(expense)
void print_format_X();
//Function: Print the input format(income)
void print_format_I();
//Function: Add the user's input to the linked list in chronological order
//Input: pointer of the linked list to be added,to tell whether it is a expense/income linked list 1(expense)/2(income)
void add(record *& rec,int XI);

//Function: print the items containing the keyword.
//Input: the keyword of item to be deleted, record pointer of linked list that stores the item to be deleted
//       ,array of record pointer to store the location,two record pointer representing the head and tail
//Output: an array of record pointer that stored the location of record pointer
int print_ptr(string key, record * rec,record *ptr[],record * head,record * tail);
//Function: delete the required item in the corresponding linked list
void delete_rec(record * after,record *&rec,record * head,record * tail);
//Function: print the items containing the keyword through the function print_ptr()
//          ask the user the choose the one he wants to delete
//          delete it through the function delete_rec()
//Input: record pointer of linked list to be deleted, a string that tells whether it is a expense or income linked list
void delete_(record *& rec,string XI);

//Input: record pointer of income/expense linked list,date in the form of YYYYMMDD
//Output: return the sum of amount in the required month
int sum_of_part_month(record * rec,string date);
//Input: record pointer of income/expense linked list,type name,the required month
//Output: the sum of amount of items match with the keyword(type) and month
double sum_type(record * rec,string keyword,string month);
//Input: record pointer of income/expense linked list,account name,the required month
//Output: the sum of amount of items match with the keyword(account) and month
double sum_account(record * rec,string keyword,string month);
//Function: print a financial report of the required month. It contains the month, monthly income, monthly expense,
//          balance, percentage of each income type, income account, expense type, expense account spent in that month.
//Input: the record pointers of income and expense linked list,the required month
void report(record * rec_X,record * rec_I,string month);

//Function: check whether the amount of expense in this month exceed the budget that user set
//          if yes, print a alert to remind the user
//          record pointer of expense linked list,the budget user set
void check_budget(record * rec,int budget);

//Function: print the expected amount of expense in this month through the current expense record
void forecast(record * rec);

//Function: stored the user's data to a particular file. The user can get it back after login
//Input: record pointer of linked list to be stored, username, user password, X(expense)/I(income)
void savedata(record * rec,string name,string password,string X_I);

//Function: delete all dynamic variables after use to prevent memory leakage
void delete_all(record *&rec);
