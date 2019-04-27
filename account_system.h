#pragma once

struct record{
  string date;
  string amount;
  string type;
  string account;
  record * next;
};

string getdate();
void view(record * rec);
string getdata(string name,record *& rec,string X_I);
void login(string & name, string & password,record *& rec_X,record *& rec_I);
void printmenu();
record * findpos(string date,record * rec);
void insert(record *& after,string input,record *& rec);
void print_format_X();
void print_format_I();
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
