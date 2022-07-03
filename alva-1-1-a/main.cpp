#include <iostream>
#include <fstream>

using namespace std;

string keeperFirstName;
string keeperLastName;
string selfName;
int keeperYearDate;
int keeperMonthDate;
int keeperDayDate;


class Person
{
public:
	string status;
	bool alive;
	string knownName;
	string firstName;
	string lastName;
	string middleName;
	int age;
	int birthday;
	string like[5];
	string dislike[5];
};

string greeting(bool formal)
{
	return "";
}

void greet()
{
	/*
	if (assigned)
	{
		cout << greeting(false) << keeperName << endl;
	}
	else
	{
		cout << "Nice to meet you "<< assign() << endl; 
	}
	*/
}

string assign()
{
	ofstream keepfile;
  	keepfile.open ("deephippo/keeper.txt");
  	cout << "Hello!\nI'm Alva or Alva-1-1-A-"<<endl;
  	cout << "Hello, what's your firstname?\n"<<endl;
  	cin >> keeperFirstName;
  	keepfile << "firstname:" << keeperFirstName << "/n";
  	cout << "What's your lastname?\n"<<endl;
  	cin >> keeperLastName;
  	keepfile << "lasttname:" << keeperLastName << "/n";
  	cout << "What year were you born in?\n"<<endl;
  	cin >> keeperLastName;
  	keepfile << "firstname:" << keeperYearDate<<keeperMonthDate<<keeperDayDate<< "/n";

  	keepfile.close();
	return keeperFirstName;
}

void initiaze()
{
	
}

int main()
{
	return 0;
}
