#pragma once

const std:: string commsURL = "../frontalcortex/comms/dir.txt";
const std::string resURL = "../frontalcortex/comms/res.txt";

void initNET();
void sendRequest(int indicator, std::string param);
std::string getResponse();
