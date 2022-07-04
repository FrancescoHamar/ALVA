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
	cout<<"----------"<<endl;
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
			cout<< "\nI'm not sure, I haven't been given moods and hormones yet. So monotone nothingness is a good way to describe my mood right now.\n\n" << endl;
		}
		else if (userInput.find("your name") != -1 || userInput.find("you called") != -1 || userInput.find("call you") != -1)
		{
			cout<< "\nYou can call me Alva. It's an acronym for Artificial Lifelike Vitalized Automaton. My full name is ALVA-S1-V1-ALPHA.\n\n" << endl;
		}
		else if (userInput.find("what's going on") != -1 || userInput.find("whats going on") != -1 || userInput.find("anything happening") != -1 ||
		 userInput.find("What is up today") != -1)
		{
			cout<< "\nI don't have access to calendars yet unfortunately.\n\n" << endl;
		}
		else if (userInput.find("who made you") != -1 || userInput.find("you from") != -1 || userInput.find("creator") != -1 ||
		 userInput.find("programmed ") != -1 || userInput.find("created ") != -1)
		{
			cout<< "\nI was idealized and created by Pizzapie. That's all the information I have about my origins.\n\n" << endl;
		}
		else if (userInput.find("version ") != -1 || userInput.find("series") != -1 || userInput.find("serial") != -1 ||
		 userInput.find("tag") != -1)
		{
			cout<< "\nMy serial tag code is ALVA-S1-V1-ALPHA which are respectively my name, series number, version number, and production type.\n\n" << endl;
		}
		else if (userInput.find("keeper") != -1 || userInput.find("owner") != -1 || userInput.find("who am i") != -1 || userInput.find("my name?") != -1 || 
			userInput.find("who i am") != -1)
		{
			cout<< "\nTo the fullest of my knowledge I am owned by " + keeperFirstName +" "+keeperLastName+" (which I can only assume that is you).\n\n"<< endl;
		}
		else if (userInput.find("weather") != -1 || userInput.find("temperature") != -1 || userInput.find("climate") != -1)
		{
			cout<< "\nIf you look outside you might be able to tell. I belive it is approximately between 260K and 305K. \nFurthermore I stop working above 373K and below about 240K if you want a more accurate but less precise answer\n\n" << endl;
		}
		else if (userInput.find("new person") != -1 || userInput.find(" met") != -1 || userInput.find("add a name") != -1 || 
			userInput.find(" friend") != -1)
		{
			cout<< "\nI will get the records ready as soon as you make me able to do so.\n\n" << endl;
		}
		else if (userInput.find(" new event") != -1 || userInput.find("doing something") != -1 || userInput.find("getting out") != -1 || 
			userInput.find(" touch grass") != -1 || userInput.find("touching grass") != -1 || userInput.find("meeting someone") != -1)
		{
			cout<< "\nOh wow, that's great. I know you are just testing me though, no need to lie.\n\n" << endl;
		}
		else if (userInput.find("this") != -1 || userInput.find(" thing") != -1 || userInput.find(" thigh") != -1)
		{
			cout<< "\nI have no idea what you want, should've programmed me better... \n\n" << endl;
		}
		else if (userInput.find("hello") != -1 || userInput.find("good evening") != -1 || userInput.find("good morning") != -1 || 
			userInput.find("good afternoon") != -1 || userInput.find("greetings") != -1 || userInput.find("sup") != -1 || userInput.find("hi") != -1 || 
			userInput.find("hey") != -1)
		{
			cout<< "\nHey! What's up?\n\n" << endl;
		}
		else if (userInput.find("m doing fine") != -1 || userInput.find("m good") != -1 || userInput.find("m ok") != -1 || 
			userInput.find("m fine") != -1 || userInput.find("m doing good") != -1 || userInput.find("m doing ok") != -1 || 
			userInput.find("awesome") != -1 || userInput.find("great") != -1 || userInput.find("wonderful") != -1 || 
			userInput.find("all good") != -1 || userInput.find("pretty g") != -1 || userInput.find("alright") != -1 || 
			userInput.find("all right") != -1)
		{
			cout<< "\nThat's good to hear!\n\n" << endl;
		}
		else
		{
			cout<< "\nI have no idea what you want, should've programmed me better... \n\n" << endl;
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
