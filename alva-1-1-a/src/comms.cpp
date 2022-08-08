#include <iostream>
#include <fstream>

#include "comms.h"

void sendRequest(int indicator, std::string param)
{
	std::ofstream commsFile;
	commsFile.open(commsURL);

	switch(indicator)
	{
		// Weather Call
		case 1:
			commsFile << "weather\n";
			commsFile << param+"\n";
			break;

		// Other Calls
		case 2:
			break;

		default:
			std::cout<<"Wrong call"<<std::endl;
			break;
	}

	commsFile.close();
}

void initNET()
{
	// Could be more complex in the future (It will definitely initiate an exe)
	
	system("python3 net.py");
}

std::string getResponse()
{
	std::ifstream resFile;
	std::string response;
	std::string line;
	resFile.open(resURL);
	if (resFile.is_open())
	{
		while (getline(resFile, line))
		{
			response = line+response;
		}
	}
	return response;
}
