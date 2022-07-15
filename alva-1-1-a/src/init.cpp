#include <iostream>
#include <fstream>

#include "util.h"
#include "objPerson.h"
#include "init.h"

void Self::greet(bool newUser)
{
	if (newUser)
	{
		std::cout << "Hello " << capitalize(firstName) << "!\n\n" << std::endl;   // Potential use of different words
	}
	else
	{
		std::cout << "Nice to meet you "<< capitalize(firstName) << "!" << std::endl; 
	}
}

void Self::initializeAlva()
{
	std::cout<<"Starting Up...\n"<<std::endl;
	
	std::ifstream tagfile;
	tagfile.open(m_tagURL);
	std::string line;
	std::string fullFile;

	if (tagfile.is_open())
	{
		while (getline (tagfile,line))
	    {

	    	if (line.find("serialtag:") == 0)
	    	{
	    		serialtag = parseDataPost(line);
	    		std::cout<<"Model: "+serialtag+"\n\n"<<std::endl;
	    	}
	    	else if (line.find("series:") == 0)
	    	{
	    		m_series = parseDataPost(line);
	    	}
	    	else if (line.find("version:") == 0)
	    	{
	    		m_version = parseDataPost(line);
	    	}
	    	else if (line.find("status:") == 0)
	    	{
	    		m_status = parseDataPost(line);
	    	}
	    	else if (line.find("born:") == 0 && line.find("true",0) == 5)
	    	{
	    		m_born = true;
	    	}
	    	else if (line.find("birthday:") == 0)
	    	{
	    		m_alvaBirthday = parseDataPost(line);
	    	}
	    	fullFile = fullFile + line + '\n';

	    }
	    tagfile.close();
	}

	if (!m_born)
	{
		std::ofstream newtagfile;
		newtagfile.open(m_tagURL);
		newtagfile << fullFile;
		newtagfile << "born:true\n";
		m_born = true;
		m_alvaBirthday = currentDateTime();
		newtagfile << "birthday:"+m_alvaBirthday;
		newtagfile.close();
	}
}

void Self::initializeKeeper()
{
	std::string line;
	std::ifstream keeperfile;
	keeperfile.open(m_keeperURL);
	int initCounter = 0;

	if (keeperfile.is_open())
	{
		while(getline(keeperfile, line))
		{
			if (line.find("firstname:") == 0)
	    	{
	    		initCounter++;
	    		firstName = parseDataPost(line);
	    	}
	    	else if (line.find("lastname:") == 0)
	    	{
	    		initCounter++;
	    		lastName = parseDataPost(line);
	    	}
	    	else if (line.find("birthyear:") == 0)
	    	{
	    		initCounter++;
	    		m_birthYear = parseDataPost(line);
	    	}
	    	else if (line.find("birthmonth:") == 0)
	    	{
	    		initCounter++;
	    		m_birthMonth = parseDataPost(line);
	    	}
	    	else if (line.find("birthdate:") == 0)
	    	{
	    		initCounter++;
	    		m_birthDate = parseDataPost(line);
	    	}
		}
		if (initCounter == 5)
		{
			m_assigned = true;
			greet(true);
		}
	}
	keeperfile.close();

	if (!m_assigned)
	{
		std::ofstream keepfile;
	  	keepfile.open (m_keeperURL);

	  	std::cout << "Hello!\nI'm Alva (Serial Tag: "+serialtag+")\n"<<std::endl;

	  	firstName = askAttribute("your FIRST name");
	  	keepfile << "firstname:" << firstName << "\n";

	  	lastName = askAttribute("your LAST name");
	  	keepfile << "lastname:" << lastName << "\n";

	  	m_birthYear = askAttribute("the year you were born in");
	  	keepfile << "birthyear:" << m_birthYear << "\n";

	  	m_birthMonth = askAttribute("the month you were born in");
	  	keepfile << "birthmonth:" << m_birthMonth << "\n";

	  	m_birthDate = askAttribute("the day you were born on");
	  	keepfile << "birthdate:" << m_birthDate << "\n";

	  	keepfile.close();

	  	greet(false);
	}
}

