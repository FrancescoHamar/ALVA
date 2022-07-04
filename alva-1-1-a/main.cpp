#include <iostream>
#include <fstream>

using namespace std;

string keeperFirstName;
string keeperLastName;
string selfName;
string userInput;
int keeperYearDate;
int keeperMonthDate;
int keeperDayDate;
bool born = false;
bool assigned = false;
bool inputReceived = false;

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

string parseData(string givenLine)
{
	int col = givenLine.find(":");
	return givenLine.substr(col+1,-1);
}

string assign()
{
	ofstream keepfile;
  	keepfile.open ("deephippo/keeper.txt");
  	cout << "Hello!\nI'm Alva (Serial Tag: ALVA-S1-V1-ALPHA)\n"<<endl;
  	cout << "What's your firstname?\n"<<endl;
  	cin >> keeperFirstName;
  	keepfile << "firstname:" << keeperFirstName << "\n";
  	cout << "What's your lastname?\n"<<endl;
  	cin >> keeperLastName;
  	keepfile << "lastname:" << keeperLastName << "\n";
  	/*
  	cout << "What year were you born in?\n"<<endl;
  	cin >> keeperLastName;
  	keepfile << "firstname:" << keeperYearDate<<keeperMonthDate<<keeperDayDate<< "/n";
  	*/

  	keepfile.close();
	return keeperFirstName;
}

void greet(bool newUser)
{
	if (newUser)
	{
		cout << "Hello " << keeperFirstName << "!\n\n" << endl;   // Potential use of different words
	}
	else
	{
		cout << "Nice to meet you "<< keeperFirstName << "!" << endl; 
	}
}

const std::string currentDateTime() {  // Not my code!!
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
		while (getline (tagfile,line))
	    {
	    	if (line.find("serial",0) == 0)
	    	{
	    		cout<<"Model: "+line.substr(10,16)+"\n\n"<<endl;
	    	}
	    	if (line.find("born:",0) == 0 && line.find("true",0) == 5)
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
		newtagfile << "born:true\n";
		newtagfile << "birthday:"+currentDateTime();
		newtagfile.close();
	}

	ifstream keeperfile;
	keeperfile.open("deephippo/keeper.txt");

	if (keeperfile.is_open())
	{
		while(getline(keeperfile, line))
		{
			if (line.find("firstname:",0) == 0)
	    	{
	    		assigned = true;
	    		keeperFirstName = parseData(line);
	    	}
	    	if (line.find("lastname:",0) == 0 && assigned)
	    	{
	    		keeperLastName = parseData(line);
	    		greet(true);
	    	}
		}
	}
	keeperfile.close();

	if (!assigned)
	{
		assign();
		greet(false);
	}
}

string listen()
{
	string input = "";
	cout<<"Tell me something to do. Type and Press Enter: "<<endl;
	getline( std::cin, input, '\n' );
	inputReceived = true;
	return input;
}

void idle()
{
	userInput = listen();  // To be timed out after while 
	if (inputReceived)
	{
		transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

		if (userInput.find("how are you") != -1 || userInput.find("how're you") != -1 || userInput.find("what's up") != -1 || 
			userInput.find("whats up") != -1 || userInput.find("what is up") != -1)
		{
			cout<< "I'm not sure, I haven't been given moods and hormones yet. So monotone nothingness is a good way to describe my mood right now.\n\n" << endl;
		}
		else if (userInput.find("what's going on") != -1 || userInput.find("whats going on") != -1 || userInput.find("anything happening") != -1 ||
		 userInput.find("What is up today") != -1)
		{
			cout<< "I don't have access to calendars yet unfortunately.\n\n" << endl;
		}
		else if (userInput.find("weather") != -1 || userInput.find("temperature") != -1 || userInput.find("climate") != -1)
		{
			cout<< "If you look outside you might be able to tell. I belive it is approximately between 260K and 305K. \nFurthermore I stop working above 373K and below about 240K if you want a more accurate but less precise answer\n\n" << endl;
		}
		else if (userInput.find("new person") != -1 || userInput.find("met someone") != -1 || userInput.find("add a name") != -1 || 
			userInput.find("friend") != -1)
		{
			cout<< "I will get the records ready as soon as you make me able to do so.\n\n" << endl;
		}
		else if (userInput.find("new event") != -1 || userInput.find("doing something") != -1 || userInput.find("getting out") != -1 || 
			userInput.find("touch grass") != -1 || userInput.find("touching grass") != -1 || userInput.find("meeting someone") != -1)
		{
			cout<< "Oh wow, that's great. I know you are just testing me though, no need to lie.\n\n" << endl;
		}
		else
		{
			cout<< "I have no idea what you want, should've programmed me better... \n\n" << endl;
		}
		inputReceived = false;
	}
}

int main()
{
	cout<<"Starting Up..."<<endl;
	initialize();
	while (true)
	{
		idle();
	}

	return 0;
}
