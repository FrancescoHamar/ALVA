#include <iostream>
#include <algorithm>
#include <ctime>
#include "util.h"

std::string listen()
{
	std::string input = "";
	getline( std::cin, input, '\n' );
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);
	return input;
}

std::string parseDataPost(std::string givenLine)
{
	int col = givenLine.find(":");
	return givenLine.substr(col+1,-1);
}

std::string parseDataPrev(std::string givenLine)
{
	int col = givenLine.find(":");
	return givenLine.substr(0,col);
}

const std::string currentDateTime() {  // Not my code!!
    time_t now = std::time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *std::localtime(&now);
    std::strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

bool binaryChoice(std::string theirAnswer)
{
	if (theirAnswer.find("yes") != -1 || theirAnswer.find("yea") != -1 || theirAnswer.find("yep") != -1 || theirAnswer.find("sure") != -1 || 
		theirAnswer.find("ok") != -1)
	{
		return true;
	}
	else if (theirAnswer.find("no") != -1 || theirAnswer.find("nah") != -1 || theirAnswer.find("dont") != -1 || theirAnswer.find("don't") != -1)
	{
		return false;
	}
	std::cout<< "\nPlease answer with a clear yes or no answer.\n\n" << std::endl;
	return binaryChoice(listen());
}

std::string capitalize(std::string word)
{
	word.front() = toupper(word[0]);
	return word;
}

std::string askAttribute(std::string attribute)
{
	std::cout<< "\nPlease tell me "+attribute+".\n\n" << std::endl;
	attribute = listen();
	if (attribute.find("don't") != -1 || attribute.find("dont") != -1 || attribute.find("no idea") != -1)
	{
		attribute = "";
	}
	return attribute;
}

