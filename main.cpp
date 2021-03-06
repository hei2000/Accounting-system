#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
#include "account_system.h"

int main(){
  record * rec_X = NULL;                                       //dynamic memory management
  record * rec_I = NULL;                                       //Linked list
  string name=" ",password=" ";
  string report_month;
  char X_I;
  int budget=INT32_MAX;
  login(name,password,rec_X,rec_I);                           //Multi-user,get previos record if you created an account before
  char choice='0';
  cout << "Welcome to your accounting system!" << endl;
  while (choice!='N'){
  printmenu();
  cin>>choice;
  switch (choice){
  case '1':
    cout<<"1: Expense\n2: Income\nEnter 1 or 2: ";
    cin >> X_I;
    if (X_I=='1') add(rec_X,1);
    if (X_I=='2') add(rec_I,2);
    break;
  case '2':
    cout<<"1: Expense\n2: Income\nEnter 1 or 2: ";
    cin >> X_I;
    if (X_I=='1') delete_(rec_X,"expense");
    if (X_I=='2') delete_(rec_I,"income");
    break;
  case '3':
    cout<<"1: Expense\n2: Income\nEnter 1 or 2: ";
    cin >> X_I;
    if (X_I=='1'){
      if (rec_X!=NULL){
        delete_(rec_X,"expense");
        add(rec_X,1);
      }
      else cout<<"\nThere is no expense record. Edit function is not available yet.\n";
    }
    if (X_I=='2'){
      if (rec_I!=NULL){
        delete_(rec_I,"income");
        add(rec_I,2);
      }
      else cout<<"\nThere is no income record. Edit function is not available yet.\n";
    }
    break;
  case '4':
    cout<<"\nExpense:"<<endl;
    view(rec_X);
    cout<<"\nIncome:"<<endl;
    view(rec_I);
    cout<<endl;
    break;
  case '5':
    cout<<"Please input the month in the following format.\nYYYYMM: ";
    cin>>report_month;
    report(rec_X,rec_I,report_month);                                     //output financial report of a particular month
    break;
  case '6':
    cout<<"Please input the budget of this month"<<endl;
    cin>>budget;
    break;
  case '7':
    forecast(rec_X);                                                      //output the expected amount of expense in this month
    break;
  case 'N':
    cout<<"\nThank you for using the accounting system. Goodbye\n\n";
    break;
  default:
    cout<<"invalid input! Please input again!"<<endl;
    }
  check_budget(rec_X,budget);                                             //alert if the spending in this month exceed the budget they set
  }
  savedata(rec_X,name,password,"X");                                      //file output
  savedata(rec_I,name,password,"I");                                      //save user's data
  delete_all(rec_X);                    		                              //avoid memory leakage, destroy dynamic variables
  delete_all(rec_I);
  return 0;
  }
