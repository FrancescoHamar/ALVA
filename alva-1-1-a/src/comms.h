#pragma once

const std:: string commsURL = "../appData/comms/dir.txt";
const std::string resURL = "../appData/comms/res.txt";

void initNET();
void sendRequest(int indicator, std::string param);
