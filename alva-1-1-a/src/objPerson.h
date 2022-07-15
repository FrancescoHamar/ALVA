#pragma once

#include <iostream>

class Person
{
public:
	std::string firstName, lastName;
	std::string birthYear, birthMonth, birthDay;
	std::string relation;
	std::string sports;
	std::string music;
	std::string behavior;
	std::string notes;

private:
	bool m_recordExists;

	std::string m_line;
	std::string m_lastLine;
	std::string m_fullFile;
	std::string m_personCode;

	std::string m_peopleURL;
	std::string m_masterURL;

public:
	void addPerson();
	std::string checkForRecord(bool newFile);
	void pullRecord();

	Person()
	{
		firstName = "";
		lastName = "";
		birthYear = "";
		birthMonth = "";
		birthDay = "";
		relation = "";
		sports = "";
		music = "";
		behavior = "";
		notes = "";
		m_line = "";
		m_lastLine = "";
		m_fullFile = "";
		m_personCode = "";
		m_peopleURL = "../frontalcortex/people/";
		m_masterURL = "../frontalcortex/people/master.txt";
	}

private:
	std::string askAttribute(std::string attribute);
	void cleanBuffers();
};
