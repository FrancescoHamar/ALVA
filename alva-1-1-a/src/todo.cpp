#include <iostream>
#include <fstream>
#include <vector>

#include "todo.h"
#include "util.h"


void Todo::loadData()
{
	std::ifstream file;
	file.open(m_todoURL);
	if (file.is_open())
	{
		while(getline(file, m_line))
		{
			// emplace_back implementation if necessary

			if (m_line.find("urgent") == 0)
			{
				urgentL.push_back(parseDataPost(m_line));
			}
			else if (m_line.find("common") == 0)
			{
				commonL.push_back(parseDataPost(m_line));
			}
			else
			{
				longtermL.push_back(parseDataPost(m_line));
			}
		}
	}
	file.close();
}

void Todo::displayData()
{
	int count = 1;

	std::cout<<"\nHere is your to-do list:\n"<<std::endl;

	if (urgentL.size() > 0)
	{
		std::cout << "Here are your urgent to-do items: \n";
		for(std::string item : urgentL)
			std::cout << count << ": " << item << "\n";
			count++;
	}
	else
	{
		std::cout << "You don't have any urgent items.\n";
	}

	if (commonL.size() > 0)
	{
		std::cout << "Here are your common to-do items: \n";
		for(std::string item : commonL)
			std::cout << count << ": " << item << "\n";
			count++;
	}
	else
	{
		std::cout << "You don't have any common items.\n";
	}

	if (commonL.size() > 0)
	{
		std::cout << "Here are your long term to-do items: \n";
		for(std::string item : longtermL)
			std::cout << count << ": " << item << "\n";
			count++;
	}
	else
	{
		std::cout << "You don't have any long term items.\n";
	}
}

void Todo::removeItem()
{
	std::cout<< "\nWhich item number would you like to remove? (please use numerals)\n" << std::endl;
	int answer = std::stoi(listen());
	if (answer <= urgentL.size())
	{
		urgentL.erase(urgentL.begin()+answer-1);
	}
	else
	{
		answer = answer - urgentL.size();
	}
	if (answer <= commonL.size())
	{
		commonL.erase(commonL.begin()+answer-1);
	}
	else
	{
		answer = answer - commonL.size();
	}
	if (answer <= longtermL.size())
	{
		longtermL.erase(longtermL.begin()+answer-1);
	}
	else
	{
		std::cout<<"Something is wrong \n";
	}

}

void Todo::addItem(int type)
{
	std::cout<<"Please type the item to add: "<< std::endl;
	std::string item = listen();
	switch(type)
	{
		// Urgent
		case 1:
			urgentL.push_back(item);
			break;
		// Common
		case 2:
			std::cout<<"Adding common item";
			commonL.push_back(item);
			break;
		// Long term
		case 3:
			longtermL.push_back(item);
			break;
	}
	std::cout<<commonL[0]<< std::endl;
	unloadData();
	loadData();
	displayData();
}


void Todo::unloadData()
{
	std::cout<<"Unloading"<<std::endl;
	std::ofstream todoFile;
	std::cout<<m_todoURL;
	todoFile.open(m_todoURL);

	for (std::string item : urgentL)
		todoFile << "urgent:" << item << "\n";

	for (std::string item : commonL)
		todoFile << "common:" << item << "\n";
	
	for (std::string item : longtermL)
		todoFile << "longterm:" << item << "\n";

	todoFile.close();
}




