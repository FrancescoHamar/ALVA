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

	std::cout<<"\nHere is your to-do list:\n\n"<<std::endl;

	if (urgentL.size() > 0)
	{
		std::cout << "Here are your urgent to-do items: \n\n";
		for(std::string item : urgentL)
		{
			std::cout << count << ": " << item << "\n";
			count++;
		}
	}
	else
	{
		std::cout << "\nYou don't have any urgent items.\n";
	}

	if (commonL.size() > 0)
	{
		std::cout << "\n\nHere are your common to-do items: \n\n";
		for(std::string item : commonL)
		{
			std::cout << count << ": " << item << "\n";
			count++;
		}
	}
	else
	{
		std::cout << "\nYou don't have any common items.\n\n";
	}

	if (longtermL.size() > 0)
	{
		std::cout << "\n\nHere are your long term to-do items: \n\n";
		for(std::string item : longtermL)
		{
			std::cout << count << ": " << item << "\n";
			count++;
		}
	}
	else
	{
		std::cout << "\n\nYou don't have any long term items.\n\n"<<std::endl;
	}
}

void Todo::removeItem()
{
	std::cout<< "\nWhich item number would you like to remove? (please use numerals)\n" << std::endl;
	int answer = std::stoi(listen());
	if (answer <= urgentL.size())
	{
		urgentL.erase(urgentL.begin()+answer-1);
		std::cout<<"\nItem deleted!\n\n";
	}
	else if ((answer - urgentL.size()) <= commonL.size())
	{
		commonL.erase(commonL.begin()+answer-1);
		std::cout<<"\nItem deleted!\n\n";
	}
	else if ((answer - commonL.size()) <= longtermL.size())
	{
		longtermL.erase(longtermL.begin()+answer-1);
		std::cout<<"\nItem deleted!\n\n";
	}
	else
	{
		std::cout<<"\nYou input a number that seems to be out of range.\n\n";
	}
	displayData();
}

void Todo::addItem(int type)
{
	std::cout<<"\nPlease type the item to add: \n"<< std::endl;
	std::string item = listen();
	switch(type)
	{
		// Urgent
		case 1:
			urgentL.push_back(item);
			break;
		// Common
		case 2:
			commonL.push_back(item);
			break;
		// Long term
		case 3:
			longtermL.push_back(item);
			break;
	}
	displayData();
}


void Todo::unloadData()
{
	std::ofstream todoFile;
	todoFile.open(m_todoURL);

	for (std::string item : urgentL)
		todoFile << "urgent:" << item << "\n";

	for (std::string item : commonL)
		todoFile << "common:" << item << "\n";

	for (std::string item : longtermL)
		todoFile << "longterm:" << item << "\n";

	todoFile.close();
}
