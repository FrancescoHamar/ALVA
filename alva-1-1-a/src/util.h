#pragma once

#include "init.h"

extern Self self;

std::string listen();
std::string parseDataPost(std::string givenLine);
std::string parseDataPrev(std::string givenLine);
const std::string currentDateTime();
bool binaryChoice(std::string theirAnswer);
std::string capitalize(std::string word);
std::string askAttribute(std::string attribute);
