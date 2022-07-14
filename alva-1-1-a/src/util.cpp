#include <iostream>

std::string listen()
{
	std::string input = "";
	getline( std::cin, input, '\n' );
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	return input;
}

std::string parseDataPrev(std::string givenLine)
{
	int col = givenLine.find(":");
	return givenLine.substr(col+1,-1);
}

std::string parseDataPost(std::string givenLine)
{
	int col = givenLine.find(":");
	return givenLine.substr(col+1,-1);
}
