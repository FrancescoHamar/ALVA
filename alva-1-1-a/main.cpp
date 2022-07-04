#include <iostream>
#include <fstream>

using namespace std;

string keeperFirstName;
string keeperLastName;
string selfName;
int keeperYearDate;
int keeperMonthDate;
int keeperDayDate;
bool born = false;

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

const std::string currentDateTime() {  // Not my code
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void initialize()
{
	ifstream tagfile;
	tagfile.open("deephippo/tag.txt");
	string line;
	string fullFile;
	if (tagfile.is_open())
	{
		while ( getline (tagfile,line) )
	    {
	    	if (line.find("serial",0) == 0)
	    	{
	    		cout<<"Model: "+line.substr(11,10)+"\n\n"<<endl;
	    	}
	    	if (line.find("born: ",0) == 0 && line.find("true",0) == 6)
	    	{
	    		born = true;
	    		break;
	    	}
	    	fullFile = fullFile + line + '\n';

	    }
	    tagfile.close();
	}
	if (!born)
	{
		ofstream newtagfile;
		newtagfile.open("deephippo/tag.txt");
		newtagfile << fullFile;
		newtagfile << "born: true\n";
		newtagfile << "birthday: "+currentDateTime();
		newtagfile.close();
	}
}

int main()
{
	cout<<"Starting Up..."<<endl;
	initialize();
	return 0;
}
