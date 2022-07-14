#include <iostream>

std::string listen()
{
	std::string input = "";
	getline( std::cin, input, '\n' );
	transform(input.begin(), input.end(), input.begin(), ::tolower);
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
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

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
