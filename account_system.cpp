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

int print_ptr(string key, record * rec,record *ptr[],record * head,record * tail){
  int count=0;
  if (rec->date==key || rec->amount==key || rec->type==key || rec->account==key){
    cout<<count<<": "<<rec->date<<" "<<rec->amount<<" "<<rec->type<<" "<<rec->account<<endl;
    ptr[count]=head;
    count++;
  }
  record * current=rec;
  if (current->next!=NULL){
  while (current->next->next!=NULL){
    if (current->next->date==key || current->next->amount==key || current->next->type==key || current->next->account==key){
      cout<<count<<": "<<current->next->date<<" "<<current->next->amount<<" "<<current->next->type<<" "<<current->next->account<<endl;
      ptr[count]=current;
      count++;
      }
    current=current->next;
  }
}
  if (current!=rec){
  current=current->next;
  if (current->date==key || current->amount==key || current->type==key || current->account==key){
     cout<<count<<": "<<current->date<<" "<<current->amount<<" "<<current->type<<" "<<current->account<<endl;
     ptr[count]=tail;
     count++;
    }
  }
  return count;
}

void delete_rec(record * after,record *&rec,record * head,record * tail){
  if (after==head){
    record * tem=rec;
    rec=rec->next;
    delete tem;
  }
  if (after==tail){
    record * current=rec;
    while (current->next->next!=NULL){
      current=current->next;
    }
    record * tem=current->next;
    current->next=NULL;
    delete tem;
  }
  if (after!=head && after !=tail){
    record * tem = after->next;
    after->next=tem->next;
    delete tem;
  }
}

void delete_(record *& rec,string XI){
  if (rec==NULL){
    cout<<"\nThere is no "<<XI<<" record. Delete function is not available yet.\n";
    return;
  }
  record tem1,tem2;
  record * head=&tem1;
  record * tail=&tem2;
  string keyword;
  cout<<"Please enter a key word for searching"<<endl;
  cin>>keyword;
  record *ptr[300];
  if (print_ptr(keyword,rec,ptr,head,tail)!=0){
    cout<<"number you want to delete"<<endl;
    int number;
    cin>>number;
    delete_rec(ptr[number],rec,head,tail);
  }
  else cout<<"\nCannot find a record that matches the key word!"<<endl;
}

int sum_of_part_month(record * rec,string date){
	if (date=="now") date=getdate();
	int total=0;
	record * current = rec;
	while (current!=NULL){
		if ((current->date).substr(0,6)==date.substr(0,6)){
			total+=atoi((current->amount).c_str());
		}
    current=current->next;
	}
	return total;
}

double sum_type(record * rec,string keyword,string month){
	double total=0;
	record * current = rec;
	while (current!=NULL){
		if (current->type==keyword && (current->date).substr(0,6)==month.substr(0,6)){
			total+=atoi((current->amount).c_str());
		}
    current=current->next;
	}
	return total;
}

double sum_account(record * rec,string keyword,string month){		//almost same as sum_type but idk how to combine them
	double total=0;
	record * current = rec;
	while (current!=NULL){
		if (current->account==keyword && (current->date).substr(0,6)==month.substr(0,6)){
			total+=atoi((current->amount).c_str());
		}
    current=current->next;
	}
	return total;
}

void report(record * rec_X,record * rec_I,string month){
	int total_income=sum_of_part_month(rec_I,month);
	int total_expense=sum_of_part_month(rec_X,month);
	cout<<"Month: "<<month<<endl;
	cout<<"Monthly income: "<<total_income<<endl;
	cout<<"Monthly expense: "<<total_expense<<endl;
	cout<<"Balance: "<<total_income-total_expense<<endl;
	cout<<fixed<<setprecision(1);
  cout<<left;
  if (total_income!=0){
	   cout<<setw(40)<<"Percentage of each income type: "<<setw(20)<<"Full-time: "<<sum_type(rec_I,"FT",month)/total_income*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Part-time: "<<sum_type(rec_I,"PT",month)/total_income*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Others: "<<sum_type(rec_I,"OT",month)/total_income*100<<"%"<<endl;
	   cout<<setw(40)<<"Percentage of each income account: "<<setw(20)<<"Cash: "<<sum_account(rec_I,"CA",month)/total_income*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Bank card: "<<sum_account(rec_I,"BC",month)/total_income*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Others: "<<sum_account(rec_I,"OT",month)/total_income*100<<"%"<<endl;
   }
  if (total_expense!=0){
	   cout<<setw(40)<<"Percentage of each expense type: "<<setw(20)<<"Food: "<<sum_type(rec_X,"FD",month)/total_expense*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Transportation: "<<sum_type(rec_X,"TS",month)/total_expense*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Entertainment: "<<sum_type(rec_X,"EN",month)/total_expense*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Utility bills: "<<sum_type(rec_X,"UB",month)/total_expense*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Others: "<<sum_type(rec_X,"OT",month)/total_expense*100<<"%"<<endl;
	   cout<<setw(40)<<"Percentage of each expense account: "<<setw(20)<<"Cash: "<<sum_account(rec_X,"CA",month)/total_expense*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Bank card: "<<sum_account(rec_X,"BC",month)/total_expense*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Credit card: "<<sum_account(rec_X,"CC",month)/total_expense*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Octopus card: "<<sum_account(rec_X,"OC",month)/total_expense*100<<"%"<<endl;
	   cout<<setw(40)<<" "<<setw(20)<<"Others: "<<sum_account(rec_X,"OT",month)/total_expense*100<<"%"<<endl;
   }
}

void check_budget(record * rec,int budget){
	if (sum_of_part_month(rec,"now")>budget){
		cout<<"\nAlert: overspending in this month.\n";
	}
}

void forecast(record * rec){
	int sum=sum_of_part_month(rec,"now");
	int daypassed=atoi((getdate().substr(6,2)).c_str());
	double expected_sum;
	//check how many days in this month. ignore leap year
	string month=getdate().substr(4,2);
	if (month=="02") expected_sum=sum/daypassed*28;
	if (month=="01" || month=="03" || month=="05" || month=="07" || month=="08" || month=="10" || month=="12")
		expected_sum=sum/daypassed*31;
	if (month=="04" || month=="06" || month=="09" || month=="11")
		expected_sum=sum/daypassed*30;
	cout<<"\nExpected expense in this month: "<<expected_sum<<endl;
}

void savedata(record * rec,string name,string password,string X_I){
	name = name + X_I + ".txt";
	ofstream fout;
	fout.open(name.c_str());
	if (fout.fail()){
		cout<<"Failed to open name. Cannot save data to the server"<<endl;
		exit(1);
	}
	fout<<password<<endl;
	record * current = rec;
	while (current != NULL){
		fout<<current->date<<" "<<current->amount<<" "<<current->type<<" "<<current->account<<endl;
		current=current->next;
	}
  fout.close();
}

void delete_all(record *&rec){
	record * tem = rec;
	while (tem!=NULL){
		rec=tem->next;
		delete tem;
		tem=rec;
	}
}
