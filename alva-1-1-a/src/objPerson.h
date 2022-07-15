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

	const std::string m_peopleURL = "../frontalcortex/people/";
	const std::string m_masterURL = "../frontalcortex/people/master.txt";

public:
	void addPerson();
	void checkForRecord(bool newFile);
	void pullRecord();

private:
	std::string askAttribute(std::string attribute);
	void cleanBuffers();
};
