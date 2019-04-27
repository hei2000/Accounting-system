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

//Return: current date in the form of YYYYMMDD
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
void login(string & name, string & password,record *& rec_X,record *& rec_I);
//Function: print a menu to guide the user

void printmenu();
//Function: Find the position of record pointer just before the new data in chronological order
//Input: Date of spending or earning,record pointer of linked list
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

int print_ptr(string key, record * rec,record *ptr[],record * head,record * tail);
void delete_rec(record * after,record *&rec,record * head,record * tail);
void delete_(record *& rec,string XI);

int sum_of_part_month(record * rec,string date);
double sum_type(record * rec,string keyword,string month);
double sum_account(record * rec,string keyword,string month);
void report(record * rec_X,record * rec_I,string month);

void check_budget(record * rec,int budget);

void forecast(record * rec);

void savedata(record * rec,string name,string password,string X_I);

void delete_all(record *&rec);
