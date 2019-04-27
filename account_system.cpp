#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "account_system.h"
using namespace std;

//return current date in the form of YYYYMMDD
string getdate(){
	time_t now = time(0);
	tm *datetm = localtime(&now);
	string date = to_string(1900+datetm->tm_year);
	if ((1+datetm->tm_mon)<10){
		date = date + "0";
		}
	date = date + to_string(1+datetm->tm_mon);
	if (datetm->tm_mday<10){
		date = date + "0";
		}
	date = date + to_string(datetm->tm_mday);
	return date;
}

//print record within one month instead of all record???
void view(record * rec){
	cout<<left<<setw(10)<<"Date"<<setw(10)<<"Amount"<<setw(10)<<"Type"<<setw(10)<<"Account"<<endl;
	record * current = rec;
	while (current!=NULL){
		cout<<setw(10)<<current->date<<setw(10)<<current->amount<<setw(10)<<current->type<<setw(10)<<current->account<<endl;
		current=current->next;
	}
}

//get data from the user's file and store it in a linked list
//return password

string getdata(string name,record *& rec,string X_I){
  record * tail;
  string password,str;
  ifstream fin;
  name = name + X_I + ".txt";
  fin.open(name.c_str());
  if (fin.fail()){
  	cout<<"Failed to open name. Cannot get data from server."<<endl;
	exit(1);
	}
  getline(fin,password);
  int counter=0;
  while (getline(fin,str)){
    istringstream iss(str);
    record * p = new record;
    record * tail;
    iss>>p->date>>p->amount>>p->type>>p->account;
    p->next=NULL;
    if (rec==NULL){
      rec=p;
      tail=p;
      }
    else{
      tail->next=p;
      tail=p;
      }
    }
  fin.close();
  return password;
  }

void login(string & name, string & password,record *& rec_X,record *& rec_I){
  int number;
  cout<<"Enter 1 to login\nEnter 2 to create new account\n";
  cin>>number;
  while (number!=1 && number!=2){
    cout<<"Invalid input! Please enter again!"<<endl;
    cin>>number;
    }
  if (number==1){
    cout<<"Please enter your user name!"<<endl;
    cin>>name;
    string check_password;
    check_password=getdata(name,rec_X,"X");                                  //file input
    getdata(name,rec_I,"I");
    cout<<"Please enter your password!"<<endl;
    cin>>password;
    while (check_password!=password){
      cout<<"Wrong password! Please enter your password again!"<<endl;
      cin>>password;
      }
    }
  if (number==2){
    cout<<"Please enter your user name for new account!"<<endl;
    cin>>name;
    cout<<"Please enter your password for new account!"<<endl;
    cin>>password;
    }
  }

void printmenu(){
  cout << "Welcome to your accounting system!\n\n"
    << "************** Menu **************\n\n"
    << "1: Add income and expenses records\n"
    << "2: Delete records\n"
    << "3: Edit records\n"
    << "4: View previous records\n"
    << "5: Generate statistical report\n"
    << "6: Set budget\n"
    << "7: Generate financial forecast\n\n"
    << "N: Exit\n\n"
    << "**********************************\n";
}

record * findpos(string date,record * rec){
  record * current = rec;
  int intdate = atoi(date.c_str());
  while (current != NULL){
  if (intdate<atoi((current->date).c_str())) return NULL;
  if (current->next==NULL){
    return current;
  }
  if (intdate>atoi((current->next->date).c_str())){
    current=current->next;
    }
  else{
    return current;
    }
  }
  return rec;
}

void insert(record *& after,string input,record *& rec){
  record * tem = new record;
  istringstream iss(input);
  iss>>tem->date>>tem->amount>>tem->type>>tem->account;
  if (rec==NULL){
    tem->next=NULL;
    rec=tem;
  }
  else{ if (after == NULL){
    tem->next=rec;
    rec=tem;
  }
  else{
    tem->next=after->next;
    after->next=tem;
    }
  }
}

void print_format_X(){
  cout<<"\nPlease enter the short form for type and account.\n"
      <<"Type: FD(Food),TS(Transportation),EN(Entertainment),UB(Utility Bills,OT(Others)\n"
      <<"Account: CA(Cash),BC(Bank Card),OT(Others)\n";
}

void print_format_I(){
  cout<<"\nPlease enter the short form for type and account.\n"
      <<"Type: FT(Full-time),PT(Part-time),OT(Others)\n"
      <<"Account: CA(Cash),BC(Bank card),OT(Others)\n";
}

void add(record *& rec,int XI){
  cout << "Add income and expenses records\n\n"
    << "*******************************\n"
    << "1: Import multiple records\n"
    << "2: Input single record\n"
    << "N: Exit\n\n"
    << "*******************************\n\n"
    << "Enter your option: ";
  char option;
  string input;
  cin >> option;
  if (option=='N'){
    cout<<"\nBack to the menu\n";
    return;
  }
  while (option != '1' && option != '2') {
    cout << "Invalid input! Please input again! " << endl;
    cin >> option;
  }
  if (option == '1') {
    string filename;
    cout << "Enter the filename of import file: ";
    cin >> filename;
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail()){
      cout<<"Failed to open name. Cannot get data from file." << endl;
    	exit(1);
    }
    while (getline(fin, input)){
      record * after = findpos(input.substr(0,8),rec);
      insert(after, input,rec);
    }
    fin.close();
  }
  else if (option == '2') {
    cout << "Please enter date, amount, type and account according to the format below." << endl;
    cout << "YYYYMMDD AMOUNT TYPE ACCOUNT" << endl;
    if (XI==1) print_format_X();
    if (XI==2) print_format_I();
    cin.ignore();
    getline(cin,input);
    record * after = findpos(input.substr(0,8),rec);
    insert(after, input,rec);
  }
}
