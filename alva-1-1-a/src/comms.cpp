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


void readRespose()
{
	std::ifstream resFile;
	resFile.open(resURL)
	
}
