#include <iostream>
#include <fstream>

#include "util.h"
#include "objPerson.h"

void Person::cleanBuffers()
{
	m_fullFile = "";
	m_lastLine = ":0";
	m_line = "";
	m_recordExists = false;
}

std::string Person::askAttribute(std::string attribute)
{
	std::cout<< "\nPlease tell me "+attribute+".\n\n" << std::endl;
	attribute = listen();
	if (attribute.find("don't") != -1 || attribute.find("dont") != -1 || attribute.find("no idea") != -1)
	{
		attribute = "";
	}
	return attribute;
}

void Person::checkForRecord(bool newFile)
{
	firstName = askAttribute("their FIRST name");
	lastName = askAttribute("their LAST name");

	if (firstName == "" & lastName == "")
	{
		if (newFile)
		{
			std::cout<< "\n\nSorry, I can't record new people without their name.\n\n" << std::endl;
		}
		else
		{
			std::cout<< "\n\nSorry, I can't look for records without their name.\n\n" << std::endl;
		}
	}

	std::cout<< "\nChecking if person present in logs..." << std::endl;
	std::ifstream masterfile;
	masterfile.open(m_masterURL);

	if (masterfile.is_open())
	{
		cleanBuffers();
		std::cout<< "\nOpening Master file" << std::endl;
		while (getline (masterfile, m_line))
	    {
	    	if (m_line.find(firstName+" "+lastName,0) == 0)
	    	{
	    		if (newFile)
	    		{
	    			std::cout<< "\nA record of "+capitalize(firstName)+ " "+capitalize(lastName)+" already exists.\n\n" << std::endl;
	    		}
	    		else
	    		{
	    			std::cout<< "\nThe record of "+capitalize(firstName)+ " "+capitalize(lastName)+" has been found.\n\n" << std::endl;
	    		}
	    		m_recordExists = true;
	    	}
	    	m_fullFile = m_fullFile + m_line + '\n';
	    	m_lastLine = m_line;

	    }
	    masterfile.close();
	}
}


void Person::addPerson()
{

	checkForRecord(true);
	
	if (!m_recordExists)
	{
		std::cout<< "\nAdding Person ..\n\n" << std::endl;

		int lastNum = stoi(parseDataPost(m_lastLine))+1;

		std::ofstream masterFile;
		masterFile.open(m_masterURL);
		masterFile << m_fullFile;
		masterFile << firstName+" "+ lastName+":"+std::to_string(lastNum)+"\n";
		masterFile.close();

		std::ofstream personFile;
		personFile.open(m_peopleURL+std::to_string(lastNum)+".txt");
		personFile << "firstname:"+firstName+"\n";
		personFile << "lastname:"+lastName+"\n";

		birthYear = askAttribute("what year they were born in");
		personFile << "birthyear:"+birthYear+"\n";

		birthMonth = askAttribute("what month they were born in");
		personFile << "birthmonth:"+birthMonth+"\n";

		birthDay = askAttribute("what day they were born on");
		personFile << "birthday:"+birthDay+"\n";

		relation = askAttribute("their relation to you");
		personFile << "relation:"+relation+"\n";

		sports = askAttribute("what sports they play");
		personFile << "sports:"+sports+"\n";

		music = askAttribute("any music related notes about them");
		personFile << "music:"+music+"\n";

		behavior = askAttribute("any behavioral observations you'd like to note");
		personFile << "behavior:"+behavior+"\n";

		notes = askAttribute("any extra notes you'd like to record");
		personFile << "notes:"+notes+"\n";

		personFile.close();
	}
}



void Person::pullRecord()
{

	checkForRecord(false);

	if (m_recordExists)
	{
		m_personCode = parseDataPost(m_line);

		std::ifstream personFile;
		personFile.open(m_peopleURL+m_personCode+".txt");

		if (personFile.is_open())
		{
			// int i = 1;
			while (getline(personFile, m_line))
		    {
		    	std::string descrLine = parseDataPrev(m_line);
		    	std::string dataLine = parseDataPost(m_line);
		    	std::cout<< capitalize(descrLine)+": "+capitalize(dataLine);

		    }

		    // firstName = parseDataPost(personFile.getline(m_line))



		    personFile.close();
		}
		
	}
}

