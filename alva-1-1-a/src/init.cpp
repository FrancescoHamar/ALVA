#include <iostream>
#include <fstream>

std::string listen();
std::string parseDataPost(std::string givenLine);
const std::string currentDateTime();
bool binaryChoice(std::string theirAnswer);

std::string firstName;
std::string lastName;
std::string selfName;
bool assigned = false;
bool born = false;

void greet(bool newUser)
{
	if (newUser)
	{
		std::cout << "Hello " << firstName << "!\n\n" << std::endl;   // Potential use of different words
	}
	else
	{
		std::cout << "Nice to meet you "<< firstName << "!" << std::endl; 
	}
}

std::string assign()
{
	std::ofstream keepfile;
  	keepfile.open ("../deephippo/keeper.txt");
  	std::cout << "Hello!\nI'm Alva (Serial Tag: ALVA-S1-V1-ALPHA)\n"<<std::endl;
  	std::cout << "What's your firstname?\n"<<std::endl;
  	std::cin >> firstName;
  	keepfile << "firstname:" << firstName << "\n";
  	std::cout << "What's your lastname?\n"<<std::endl;
  	std::cin >> lastName;
  	keepfile << "lastname:" << lastName << "\n";
  	/*
  	std::cout << "What year were you born in?\n"<<std::endl;
  	std::cin >> lastName;
  	keepfile << "firstname:" << keeperYearDate<<keeperMonthDate<<keeperDayDate<< "/n";
  	*/

  	keepfile.close();
	return firstName;
}

std::string initialize()
{
	std::ifstream tagfile;
	tagfile.open("../deephippo/tag.txt");
	std::string line;
	std::string fullFile;

	if (tagfile.is_open())
	{
		while (getline (tagfile,line))
	    {
	    	if (line.find("serial",0) == 0)
	    	{
	    		std::cout<<"Model: "+parseDataPost(line)+"\n\n"<<std::endl;
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
		std::ofstream newtagfile;
		newtagfile.open("../deephippo/tag.txt");
		newtagfile << fullFile;
		newtagfile << "born:true\n";
		newtagfile << "birthday:"+currentDateTime();
		newtagfile.close();
	}

	std::ifstream keeperfile;
	keeperfile.open("../deephippo/keeper.txt");

	if (keeperfile.is_open())
	{
		while(getline(keeperfile, line))
		{
			if (line.find("firstname:",0) == 0)
	    	{
	    		assigned = true;
	    		firstName = parseDataPost(line);
	    	}
	    	if (line.find("lastname:",0) == 0 && assigned)
	    	{
	    		lastName = parseDataPost(line);
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

	return firstName+":"+lastName;
}

