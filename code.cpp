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
    cout<<"Please enter your user name!"<<endl;
    cin>>name;
    cout<<"Please enter your password!"<<endl;
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
    << "**********************************\n\n"
    << "Enter your option: ";
}

record * findpos(string date,record * rec){
  record * current = rec;
  int intdate = atoi(date.c_str());
  while (current != NULL){
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

void insert(record * after,string input){
  record * tem = new record;
  istringstream iss(input);
  iss>>tem->date>>tem->amount>>tem->type>>tem->account;
  tem->next=after->next;
  after->next=tem;
}

void add(record * rec){
  cout << "Add income and expenses records\n\n"
    << "*******************************\n"
    << "1: Import multiple records\n"
    << "2: Input single record\n"
    << "N: Exit\n\n"
    << "*******************************\n\n"
    << "Enter your option: ";
  char option;
  cin >> option;
  while (option != 'N' || option != '1' || option != '2') {
    cout << "Invalid input! Please input again! " << endl;
    cin >> option;
  }
  if (option == '1') {
    string filename;
    cout << "Enter the filename of import file: ";
    cin >> filename;
    fin.open(filename.c_str());
    if (fin.fail()){
      cout<<"Failed to open name. Cannot get data from file." << endl;
    	exit(1);
    }
    // not yet finish
    fin.close();
  }
  else if (option == '2') {
    cout << "Please enter date, amount, type of expense and account according to the format below" << endl;
    cout << "YYYYMMDD AMOUNT TYPE ACCOUNT" << endl;
    string input;
    cin.ignore();
    getline(cin,input);
    record * after = findpos(input.substr(0,8),rec);
    insert(after, input);
  }
}

int print_ptr(string key, record * rec,record *ptr[],record * head,record * tail){
  int count=0;
  if (rec->date==key || rec->amount==key || rec->type==key || rec->account==key){
    cout<<count<<": "<<rec->date<<" "<<rec->amount<<" "<<rec->type<<" "<<rec->account<<endl;
    ptr[count]=head;                                                                               //delete head
    count++;
  }
  record * current=rec;
  while (current->next->next!=NULL){
    if (current->next->date==key || current->next->amount==key || current->next->type==key || current->next->account==key){
      cout<<count<<": "<<current->next->date<<" "<<current->next->amount<<" "<<current->next->type<<" "<<current->next->account<<endl;
      ptr[count]=current;
      count++;
      }
    current=current->next;
  }
  if (current!=rec){
  current=current->next;
  if (current->date==key || current->amount==key || current->type==key || current->account==key){
     cout<<count<<": "<<current->date<<" "<<current->amount<<" "<<current->type<<" "<<current->account<<endl;
     ptr[count]=tail;
     count++;                                                                              //delete tail
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

void delete_(record *& rec){
  record tem1,tem2;
  record * head=&tem1;
  record * tail=&tem2;
  string keyword;
  cout<<"Please enter a key word for searching"<<endl;
  cin>>keyword;
  record *ptr[300];                              //use dynamic memory if possible
  if (print_ptr(keyword,rec,ptr,head,tail)!=0){
    cout<<"number you want to delete"<<endl;
    int number;
    cin>>number;
    delete_rec(ptr[number],rec,head,tail);
  }
  else cout<<"Not found!"<<endl;
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

int sum_of_this_month(record * rec){
	string date=getdate();
	int total=0;
	record * current = rec;
	while (current!=NULL){
		if ((current->date).substr(0,6)==date.substr(0,6)){
			total+=atoi((current->amount).c_str());
		}
	}
	return total;
}

void check_budget(record * rec,int budget){
	if (sum_of_this_month(rec)>budget){
		cout<<"overspend"<<endl;
	}
}

void forecast(record * rec){
	int sum=sum_of_this_month(rec);
	int daypassed=atoi((getdate().substr(6,2)).c_str());
	double expected_sum;
	//check how many days in this month. ignore leap year
	string month=getdate().substr(4,2);
	if (month=="02") expected_sum=sum/daypassed*28;
	if (month=="01" || month=="03" || month=="05" || month=="07" || month=="08" || month=="10" || month=="12")
		expected_sum=sum/daypassed*31;
	if (month=="04" || month=="06" || month=="09" || month=="11")
		expected_sum=sum/daypassed*30;
	cout<<"expect use "<<expected_sum<<endl;
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
}

void delete_all(record *&rec){
	record * tem = rec;
	while (tem!=NULL){
		rec=tem->next;
		delete tem;
		tem=rec;
	}
}

int main(){
  record * rec_X = NULL;                                //dynamic memory management
  record * rec_I = NULL;
  string name=" ",password=" ";
  char X_I;
  int budget=-1;
  login(name,password,rec_X,rec_I);

  printmenu();
  char choice;
  while (choice!='N'){
  cout<<"input your choice"<<endl;
  cin>>choice;
  switch (choice){
  case '1':
    cout<<"1: Expense\n2: Income\n";
    cin >> X_I;
    if (X_I=='1') add(rec_X);
    if (X_I=='2') add(rec_I);
    break;
  case '2':
    cout<<"1: Expense\n2: Income\n";
    cin >> X_I;
    if (X_I=='1') delete_(rec_X);
    if (X_I=='2') delete_(rec_I);
    break;
  case '3':
    cout<<"1: Expense\n2: Income\n";
    cin >> X_I;
    if (X_I=='1'){
    delete_(rec_X);
    add(rec_X);
    }
    if (X_I=='2'){
    delete_(rec_I);
    add(rec_I);
    }
    break;
  case '4':
    cout<<"Expense:"<<endl;
    view(rec_X);
    cout<<"Income:"<<endl;
    view(rec_I);
    break;
  case '5':
    report();
    break;
  case '6':
    cout<<"Please input the budget of this month"<<endl;
    cin>>budget;
    break;
  case '7':
    forecast(rec_X);					//can forecase within year
    break;
  case 'N':
    cout<<"Bye!"<<endl;
    break;
  default:
    cout<<"invalid input! Please input again!"<<endl;
    }
  check_budget(rec_X,budget);
  }
  savedata(rec_X,name,password,"X");                           //file output
  savedata(rec_I,name,password,"I");
  delete_all(rec_X);                    		   //avoid memory leakage
  delete_all(rec_I);
  return 0;
  }
