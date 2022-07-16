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



void Person::displayData()
{

	m_personCode = checkForRecord(false);
	int compCounter = 0;

	if (m_recordExists)
	{
		m_personCode = parseDataPost(m_line);

		std::ifstream personFile;
		personFile.open(m_peopleURL+m_personCode+".txt");

		if (personFile.is_open())
		{
			while (getline(personFile, m_line))
		    {
		    	compCounter++;
		    	std::string descrLine = parseDataPrev(m_line);
		    	std::string dataLine = parseDataPost(m_line);
		    	std::cout<< capitalize(descrLine)+": "+capitalize(dataLine)<<std::endl;
		    }

		    personFile.close();
		}
		if (compCounter < 10)
		{
			std::cout<<"\nThis record is incomplete, would you like to complete it?\n"<<std::endl;
			if (binaryChoice(listen()))
			{
				changeData();
			}
		}
	}
}

void Person::loadData()
{

	if (m_recordExists)
	{

		std::ifstream personFile;
		personFile.open(m_peopleURL+m_personCode+".txt");

		if (personFile.is_open())
		{
			while (getline(personFile, m_line))
		    {
		    	if (m_line.find("firstname:") == 0)
		    	{
		    		firstName = parseDataPost(m_line);
		    		std::cout<<firstName<<std::endl;
		    	}
		    	else if (m_line.find("lastname:") == 0)
		    	{
		    		lastName = parseDataPost(m_line);
		    	}
		    	else if (m_line.find("birthyear:") == 0)
		    	{
		    		birthYear = parseDataPost(m_line);
		    	}
		    	else if (m_line.find("birthmonth:") == 0)
		    	{
		    		birthMonth = parseDataPost(m_line);
		    		std::cout<<birthMonth<<std::endl;
		    	}
		    	else if (m_line.find("birthday:") == 0)
		    	{
		    		birthDay = parseDataPost(m_line);
		    	}
		    	else if (m_line.find("relation:") == 0)
		    	{
		    		relation = parseDataPost(m_line);
		    	}
		    	else if (m_line.find("sports:") == 0)
		    	{
		    		sports = parseDataPost(m_line);
		    	}
		    	else if (m_line.find("music:") == 0)
		    	{
		    		music = parseDataPost(m_line);
		    	}
		    	else if (m_line.find("behavior:") == 0)
		    	{
		    		behavior = parseDataPost(m_line);
		    	}
		    	else if (m_line.find("notes:") == 0)
		    	{
		    		notes = parseDataPost(m_line);
		    	}
		    }
		    personFile.close();
		}
	}
}

void Person::unloadData()
{
	std::ofstream personFile;
	personFile.open(m_peopleURL+m_personCode+".txt");
	
	personFile << "firstname:"<<firstName<<"\n";
	personFile << "lastname:"<<lastName<<"\n";
	personFile << "birthyear:"<<birthYear<<"\n";
	personFile << "birthmonth:"<<birthMonth<<"\n";
	personFile << "birthday:"<<birthDay<<"\n";
	personFile << "relation:"<<relation<<"\n";
	personFile << "sports:"<<sports<<"\n";
	personFile << "music:"<<music<<"\n";
	personFile << "behavior:"<<behavior<<"\n";
	personFile << "notes:"<<notes<<"\n";	
    	
	personFile.close();
}

void Person::changeData()
{
	std::string temp;
	loadData();

	std::cout <<"\nLeave blank to keep the data or type the new data, press enter to continue to new data value\n\n"<<std::endl;

	std::cout <<"\nCurrently recorded firstname: "<<capitalize(firstName)<<std::endl;
	temp = listen();
	if (temp != "")
	{
		firstName = temp;
	}

	std::cout <<"\nCurrently recorded lastname: "<<capitalize(lastName)<<std::endl;
	temp = listen();
	if (temp != "")
	{
		lastName = temp;
	}

	std::cout <<"\nCurrently recorded birthyear: "<<capitalize(birthYear)<<std::endl;
	temp = listen();
	if (temp != "")
	{
		birthYear = temp;
	}

	std::cout <<"\nCurrently recorded birthmonth: "<<capitalize(birthMonth)<<std::endl;
	temp = listen();
	if (temp != "")
	{
		birthMonth = temp;
	}

	std::cout <<"\nCurrently recorded birthday: "<<capitalize(birthDay)<<std::endl;
	temp = listen();
	if (temp != "")
	{
		birthDay = temp;
	}

	std::cout <<"\nCurrently recorded relation: "<<capitalize(relation)<<std::endl;
	temp = listen();
	if (temp != "")
	{
		relation = temp;
	}

	std::cout <<"\nCurrently recorded sports: "<<capitalize(sports)<<std::endl;
	temp = listen();
	if (temp != "")
	{
		sports = temp;
	}

	std::cout <<"\nCurrently recorded music: "<<capitalize(music)<<std::endl;
	temp = listen();
	if (temp != "")
	{
		music = temp;
	}

	std::cout <<"\nCurrently recorded behavior: "<<capitalize(behavior)<<std::endl;
	temp = listen();
	if (temp != "")
	{
		behavior = temp;
	}

	std::cout <<"\nCurrently recorded notes: "<<capitalize(notes)<<std::endl;
	temp = listen();
	if (temp != "")
	{
		notes = temp;
	}

	unloadData();

}




