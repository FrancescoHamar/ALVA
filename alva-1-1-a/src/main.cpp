#include <iostream>
#include <fstream>

std::string listen();
std::string parseDataPost(std::string givenLine);
std::string parseDataPrev(std::string givenLine);
std::string initialize();
const std::string currentDateTime();
bool binaryChoice(std::string theirAnswer);

std::string userInput;
int keeperYearDate;
int keeperMonthDate;
int keeperDayDate;
std::string keeperFirstName;
std::string keeperLastName;


void addPerson()
{
	bool missingFirst = false;
	bool missingLast = false;
	std::cout<< "\nPlease tell me their firstname.\n\n" << std::endl;
	std::string tempFirst = listen();
	if (tempFirst.find("don't") != -1 || tempFirst.find("dont") != -1 || tempFirst.find("no idea") != -1)
	{
		missingFirst = true;
		tempFirst = "";
	}
	std::cout<< "\nPlease tell me their lastname\n\n" << std::endl;
	std::string tempLast = listen();
	if (tempLast.find("don't") != -1 || tempLast.find("dont") != -1 || tempLast.find("no idea") != -1)
	{
		missingLast = true;
		tempLast = "";
	}
	if (missingLast && missingFirst)
	{
		std::cout<< "\n\nSorry, I can't log people without their name.\n\n" << std::endl;
	}
	else
	{
		std::cout<< "\nChecking if person already in logs..." << std::endl;
		std::ifstream masterfile;
		masterfile.open("frontalcortex/people/master.txt");
		std::string line;
		std::string lastLine = ":0";
		std::string fullFile;
		bool noRecord = true;

		if (masterfile.is_open())
		{
			std::cout<< "\nOpening Master file" << std::endl;
			while (getline (masterfile,line))
		    {
		    	if (line.find(tempFirst+" "+tempLast,0) == 0)
		    	{
		    		std::cout<< "\nA record of "+tempFirst+ " "+tempLast+" already exists.\n\n" << std::endl;
		    		noRecord = false;
		    	}
		    	fullFile = fullFile + line + '\n';
		    	lastLine = line;

		    }
		    masterfile.close();
		}
		if (noRecord)
		{
			std::cout<< "\nAdding Person ..\n\n" << std::endl;

			int lastNum = stoi(parseDataPost(lastLine))+1;

			std::ofstream newMasterFile;
			newMasterFile.open("frontalcortex/people/master.txt");
			newMasterFile << fullFile;
			newMasterFile << tempFirst+" "+ tempLast+":"+std::to_string(lastNum)+"\n";
			newMasterFile.close();

			std::ofstream newPersonFile;
			newPersonFile.open("frontalcortex/people/"+std::to_string(lastNum)+".txt");
			newPersonFile << "firstname:"+tempFirst+"\n";
			newPersonFile << "lastname:"+tempLast+"\n";

			std::cout<< "What year where they born in?\n\n" << std::endl;
			std::string tempYear = listen();
			if (tempYear.find("don't") != -1 || tempYear.find("dont") != -1 || tempYear.find("no idea") != -1)
			{
				tempFirst = "";
			}
			newPersonFile << "birthyear:"+tempYear+"\n";

			std::cout<< "What month where they born in?\n\n" << std::endl;
			std::string tempMonth = listen();
			if (tempMonth.find("don't") != -1 || tempMonth.find("dont") != -1 || tempMonth.find("no idea") != -1)
			{
				tempMonth = "";
			}
			newPersonFile << "birthmonth:"+tempMonth+"\n";

			std::cout<< "What day where they born on?\n\n" << std::endl;
			std::string tempDay = listen();
			if (tempDay.find("don't") != -1 || tempDay.find("dont") != -1 || tempDay.find("no idea") != -1)
			{
				tempDay = "";
			}
			newPersonFile << "birthday:"+tempDay+"\n";

			newPersonFile.close();
		}
	}
}

void retrievePerson()
{
	bool missingFirst = false;
	bool missingLast = false;
	std::cout<< "\nWhat is their firstname.\n\n" << std::endl;
	std::string tempFirst = listen();
	if (tempFirst.find("don't") != -1 || tempFirst.find("dont") != -1 || tempFirst.find("no idea") != -1)
	{
		missingFirst = true;
		tempFirst = "";
	}
	std::cout<< "\nPlease tell me their lastname\n\n" << std::endl;
	std::string tempLast = listen();
	if (tempLast.find("don't") != -1 || tempLast.find("dont") != -1 || tempLast.find("no idea") != -1)
	{
		missingLast = true;
		tempLast = "";
	}
	if (missingLast && missingFirst)
	{
		std::cout<< "\n\nSorry, I can't look for people without their name.\n\n" << std::endl;
	}
	else
	{
		std::cout<< "\nFinding person's logs..." << std::endl;
		std::ifstream masterfile;
		masterfile.open("../frontalcortex/people/master.txt");
		std::string line;
		std::string personCode;
		bool recordExists = false;

		if (masterfile.is_open())
		{
			std::cout<< "\nOpening Master file.." << std::endl;
			while (getline (masterfile,line))
		    {
		    	if (line.find(tempFirst+" "+tempLast,0) == 0)
		    	{
		    		std::cout<< "\nRecord of "+tempFirst+ " "+tempLast+" found.\n\n" << std::endl;
		    		recordExists = true;
		    		personCode = parseDataPost(line);
		    	}

		    }
		    masterfile.close();
		}
		if (recordExists)
		{
			std::ifstream personFile;
			personFile.open("../frontalcortex/people/"+personCode+".txt");

			if (personFile.is_open())
			{
				while (getline (personFile,line))
			    {
			    	int col = line.find(":");
			    	line = line.insert(col+1," ");
			    	std::cout<< line+"\n";

			    }
			    personFile.close();
			}
			
		}
	}
}


void peopleHub()
{
	std::cout<< "\nDo you want to add this person to your contacts?\n\n" << std::endl;
	std::string answer = listen();
	if (binaryChoice(answer))
	{
		addPerson();
	}
	else
	{
		std::cout<< "\nDo you want to know something about them?\n\n" << std::endl;
		answer = listen();
		if (binaryChoice(answer))
		{
			retrievePerson();
		}
	}

}


void idle()
{
	std::cout<<"----------\n"<<std::endl;
	userInput = listen();  // To be timed out after while 
	if (userInput != "")
	{

		if (userInput.find("how are you") != -1 || userInput.find("how're you") != -1 || userInput.find("what's up") != -1 || 
			userInput.find("whats up") != -1 || userInput.find("what is up") != -1)
		{
			std::cout<< "\nI'm not sure, I haven't been given moods and hormones yet. So monotone nothingness is a good way to describe my mood right now.\n\n" << std::endl;
		}
		else if (userInput.find("your name") != -1 || userInput.find("you called") != -1 || userInput.find("call you") != -1)
		{
			std::cout<< "\nYou can call me Alva. It's an acronym for Artificial Lifelike Vitalized Automaton. My full name is ALVA-S1-V1-ALPHA.\n\n" << std::endl;
		}
		else if (userInput.find("what's going on") != -1 || userInput.find("whats going on") != -1 || userInput.find("anything happening") != -1 ||
		 userInput.find("What is up today") != -1 || userInput.find(" today") != -1)
		{
			std::cout<< "\nI don't have access to calendars yet unfortunately.\n\n" << std::endl;
		}
		else if (userInput.find("who made you") != -1 || userInput.find("you from") != -1 || userInput.find("creator") != -1 ||
		 userInput.find("programmed ") != -1 || userInput.find("created ") != -1)
		{
			std::cout<< "\nI was idealized and created by Pizzapie. That's all the information I have about my origins.\n\n" << std::endl;
		}
		else if (userInput.find("version ") != -1 || userInput.find("series") != -1 || userInput.find("serial") != -1 ||
		 userInput.find("tag") != -1)
		{
			std::cout<< "\nMy serial tag code is ALVA-S1-V1-ALPHA which are respectively my name, series number, version number, and production type.\n\n" << std::endl;
		}
		else if (userInput.find("keeper") != -1 || userInput.find("owner") != -1 || userInput.find("who am i") != -1 || userInput.find("my name?") != -1 || 
			userInput.find("who i am") != -1 || userInput.find("you owned by") != -1 || userInput.find("owns you") != -1)
		{
			std::cout<< "\nTo the fullest of my knowledge I am owned by " + keeperFirstName +" "+keeperLastName+" (which I can only assume that is you).\n\n"<< std::endl;
		}
		else if (userInput.find("weather") != -1 || userInput.find("temperature") != -1 || userInput.find("climate") != -1)
		{
			std::cout<< "\nIf you look outside you might be able to tell. I belive it is approximately between 260K and 305K. \nFurthermore I stop working above 373K and below about 240K if you want a more accurate but less precise answer\n\n" << std::endl;
		}
		else if (userInput.find("person") != -1 || userInput.find(" met") != -1 || userInput.find("add a name") != -1 || userInput.find("new people") != -1 || 
			userInput.find("contact") != -1 || userInput.find("someone") != -1 || userInput.find("guy") != -1 || userInput.find("man") != -1 || 
			userInput.find("woman") != -1 || userInput.find("girl") != -1)
		{
			std::cout<< "\nAccessing Records....\n" << std::endl;
			peopleHub();

		}
		else if (userInput.find(" new event") != -1 || userInput.find("doing something") != -1 || userInput.find("getting out") != -1 || 
			userInput.find(" touch grass") != -1 || userInput.find("touching grass") != -1 || userInput.find("meeting someone") != -1)
		{
			std::cout<< "\nOh wow, that's great. I know you are just testing me though, no need to lie.\n\n" << std::endl;
		}
		else if (userInput.find("this") != -1 || userInput.find(" thing") != -1 || userInput.find(" thigh") != -1)
		{
			std::cout<< "\nI have no idea what you want, should've programmed me better... \n\n" << std::endl;
		}
		else if (userInput.find("hello") != -1 || userInput.find("good evening") != -1 || userInput.find("good morning") != -1 || 
			userInput.find("good afternoon") != -1 || userInput.find("greetings") != -1 || userInput.find("sup") != -1 || userInput.find("hi") != -1 || 
			userInput.find("hey") != -1)
		{
			std::cout<< "\n\nHey! What's up?\n\n" << std::endl;
		}
		else if (userInput.find("m doing fine") != -1 || userInput.find("m good") != -1 || userInput.find("m ok") != -1 || 
			userInput.find("m fine") != -1 || userInput.find("m doing good") != -1 || userInput.find("m doing ok") != -1 || 
			userInput.find("awesome") != -1 || userInput.find("great") != -1 || userInput.find("wonderful") != -1 || 
			userInput.find("all good") != -1 || userInput.find("pretty g") != -1 || userInput.find("alright") != -1 || 
			userInput.find("all right") != -1)
		{
			std::cout<< "\nThat's good to hear!\n\n" << std::endl;
		}
		else if (userInput == "thank you" || userInput == "thanks")
		{
			std::cout<< "\nYou are welcome!\n\n" << std::endl;
		}
		else
		{
			std::cout<< "\nI'm sorry, I don't know what you mean. Unfortunately I was programmed by an incompetent person, or perhaps you misspelled something.\n\n" << std::endl;
		}
	}
}

int main()
{
	std::cout<<"Starting Up...\n"<<std::endl;
	std::string keeperName = initialize();
	keeperFirstName = parseDataPrev(keeperName);
	keeperLastName = parseDataPost(keeperName);
	while (true)
	{
		idle();
	}

	return 0;
}
