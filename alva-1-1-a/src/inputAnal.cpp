#include <iostream>

#include "init.h"
#include "util.h"
#include "objPerson.h"

void peopleHub()
{
	Person personInstance;

	std::cout<< "\nDo you want to add this person to your contacts?\n\n" << std::endl;
	std::string answer = listen();
	if (binaryChoice(answer))
	{
		personInstance.addPerson();
	}
	else
	{
		std::cout<< "\nDo you want to know something about them?\n\n" << std::endl;
		answer = listen();
		if (binaryChoice(answer))
		{
			personInstance.displayData();
		}
	}
}


void basicIdle()
{

	std::cout<<"----------\n"<<std::endl;
	std::string userInput = listen();  // To be timed out after while 
	if (userInput != "")
	{

		if (userInput.find("how are you") != -1 || userInput.find("how're you") != -1 || userInput.find("what's up") != -1 || 
			userInput.find("whats up") != -1 || userInput.find("what is up") != -1)
		{
			std::cout<< "\nI'm not sure, I haven't been given moods and hormones yet. So monotone nothingness is a good way to describe my mood right now.\n\n" << std::endl;
		}
		else if (userInput.find("your name") != -1 || userInput.find("you called") != -1 || userInput.find("call you") != -1)
		{
			std::cout<< "\nYou can call me Alva. It's an acronym for Artificial Lifelike Vitalized Automaton. My full name is ALVA-S1-V1-ALPHA.\n\n" << std::endl;
		}
		else if (userInput.find("what's going on") != -1 || userInput.find("whats going on") != -1 || userInput.find("anything happening") != -1 ||
		 userInput.find("What is up today") != -1 || userInput.find(" today") != -1)
		{
			std::cout<< "\nI don't have access to calendars yet unfortunately.\n\n" << std::endl;
		}
		else if (userInput.find("who made you") != -1 || userInput.find("you from") != -1 || userInput.find("creator") != -1 ||
		 userInput.find("programmed ") != -1 || userInput.find("created ") != -1)
		{
			std::cout<< "\nI was idealized and created by Pizzapie. That's all the information I have about my origins.\n\n" << std::endl;
		}
		else if (userInput.find("version ") != -1 || userInput.find("series") != -1 || userInput.find("serial") != -1 ||
		 userInput.find("tag") != -1)
		{
			std::cout<< "\nMy serial tag code is ALVA-S1-V1-ALPHA which are respectively my name, series number, version number, and production type.\n\n" << std::endl;
		}
		else if (userInput.find("keeper") != -1 || userInput.find("owner") != -1 || userInput.find("who am i") != -1 || userInput.find("my name?") != -1 || 
			userInput.find("who i am") != -1 || userInput.find("you owned by") != -1 || userInput.find("owns you") != -1)
		{
			std::cout<< "\nTo the fullest of my knowledge I am owned by " + capitalize(self.firstName) +" "+ capitalize(self.lastName) +" (which I can only assume that is you).\n\n"<< std::endl;
		}
		else if (userInput.find("weather") != -1 || userInput.find("temperature") != -1 || userInput.find("climate") != -1)
		{
			std::cout<< "\nIf you look outside you might be able to tell. I belive it is approximately between 260K and 305K. \nFurthermore I stop working above 373K and below about 240K if you want a more accurate but less precise answer\n\n" << std::endl;
		}
		else if (userInput.find("person") != -1 || userInput.find(" met") != -1 || userInput.find("add a name") != -1 || userInput.find("new people") != -1 || 
			userInput.find("contact") != -1 || userInput.find("someone") != -1 || userInput.find("guy") != -1 || userInput.find("man") != -1 || 
			userInput.find("woman") != -1 || userInput.find("girl") != -1)
		{
			std::cout<< "\nAccessing Records....\n" << std::endl;
			peopleHub();

		}
		else if (userInput.find(" new event") != -1 || userInput.find("doing something") != -1 || userInput.find("getting out") != -1 || 
			userInput.find(" touch grass") != -1 || userInput.find("touching grass") != -1 || userInput.find("meeting someone") != -1)
		{
			std::cout<< "\nOh wow, that's great. I know you are just testing me though, no need to lie.\n\n" << std::endl;
		}
		else if (userInput.find("this") != -1 || userInput.find(" thing") != -1 || userInput.find(" thigh") != -1)
		{
			std::cout<< "\nI have no idea what you want, should've programmed me better... \n\n" << std::endl;
		}
		else if (userInput.find("hello") != -1 || userInput.find("good evening") != -1 || userInput.find("good morning") != -1 || 
			userInput.find("good afternoon") != -1 || userInput.find("greetings") != -1 || userInput.find("sup") != -1 || userInput.find("hi") != -1 || 
			userInput.find("hey") != -1)
		{
			std::cout<< "\n\nHey! What's up?\n\n" << std::endl;
		}
		else if (userInput.find("m doing fine") != -1 || userInput.find("m good") != -1 || userInput.find("m ok") != -1 || 
			userInput.find("m fine") != -1 || userInput.find("m doing good") != -1 || userInput.find("m doing ok") != -1 || 
			userInput.find("awesome") != -1 || userInput.find("great") != -1 || userInput.find("wonderful") != -1 || 
			userInput.find("all good") != -1 || userInput.find("pretty g") != -1 || userInput.find("alright") != -1 || 
			userInput.find("all right") != -1)
		{
			std::cout<< "\nThat's good to hear!\n\n" << std::endl;
		}
		else if (userInput == "thank you" || userInput == "thanks")
		{
			std::cout<< "\nYou are welcome!\n\n" << std::endl;
		}
		else
		{
			std::cout<< "\nI'm sorry, I don't know what you mean. Unfortunately I was programmed by an incompetent person, or perhaps you misspelled something.\n\n" << std::endl;
		}
	}
}