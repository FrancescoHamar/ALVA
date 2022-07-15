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

std::string Person::checkForRecord(bool newFile)
{
	std::string code;

	firstName = askAttribute("their FIRST name");
	lastName = askAttribute("their LAST name");

	if (firstName == "" && lastName == "")
	{
		if (newFile)
		{
			std::cout<< "\n\nSorry, I can't record new people without their name.\n\n" << std::endl;
			m_recordExists = true;
			return "0";
		}
		else
		{
			std::cout<< "\n\nSorry, I can't look for records without a name.\n\n" << std::endl;
			m_recordExists = false;
			return "0";
		}
	}
	else
	{
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
		    			code = parseDataPost(m_line);
		    			m_recordExists = true;
		    			return code;
		    		}
		    		else
		    		{
		    			std::cout<< "\nThe record of "+capitalize(firstName)+ " "+capitalize(lastName)+" has been found.\n\n" << std::endl;
		    			code = parseDataPost(m_line);
		    			m_recordExists = true;
		    			return code;
		    		}
		    	}
		    	m_fullFile = m_fullFile + m_line + '\n';
		    	m_lastLine = m_line;

		    }
		    masterfile.close();
		}
		code = std::to_string(stoi(parseDataPost(m_lastLine))+1);
		return code;
	}
}


void Person::addPerson()
{

	m_personCode = checkForRecord(true);
	
	if (!m_recordExists)
	{
		std::cout<< "\nAdding Person ..\n\n" << std::endl;

		std::ofstream masterFile;
		masterFile.open(m_masterURL);
		masterFile << m_fullFile;
		masterFile << firstName+" "+ lastName+":"+m_personCode+"\n";
		masterFile.close();

		std::ofstream personFile;
		personFile.open(m_peopleURL+m_personCode+".txt");
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

	m_personCode = checkForRecord(false);

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
		    	std::cout<< capitalize(descrLine)+": "+capitalize(dataLine)<<std::endl;

		    }

		    // firstName = parseDataPost(personFile.getline(m_line))



		    personFile.close();
		}
		
	}
}

