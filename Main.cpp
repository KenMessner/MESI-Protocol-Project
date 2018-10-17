//Main function where IO and BUS functions will be placed
//MESI Project, The goal in this project is to implement the MESI cache coherence protocol
//Author: Kenneth Messner
//Last Modified: 10/12/18

#include "Core.h"

char initalPrompt();
void parseRequest(std::string request);
void bus(const int coreNumber, const char action, const int blockNumber, const int blockLocation, const int writeValue);

//GLOBAL - Array of Four CPU Cores
Core* cores[4];
//GLOBAL - Array of Ten Blocks of Four Memory Locations
int systemMemory[10][4] = {0};

int main(){
    //Create all 4 cores and store them into the global cores array
    for(int index = 0; index < 4; index++){
        cores[index] = new Core(index);
    }

    char choice = initalPrompt();

    std::string userRequest;

    if(choice = 'M'){
        std::cout << "Core Request works as follows,\n Core Number{0-3},Operation{R/W},Block{0-9},Memory Location{0-3},Write Value\n EX1: 0,R,3,0\n EX2: 2,W,0,1,2000\n EX3: 3,W,7,0,220\n\n";
        std::cout << "Enter Request: ";
        std::cin >> userRequest;
    }else{
        std::cout << "ADD FILE INPUT FOR SCRIPTED EVENT\N\N";
        return 0;
    }
    
    while(userRequest != "q" && userRequest != "Q" && userRequest != "quit" && userRequest != "Quit" && userRequest != "QUIT"){
        parseRequest(userRequest);
    
        std::cout << "Enter Request: ";
        std::cin >> userRequest;
    }
}

char initalPrompt(){
    std::cout << "Do you want to manually => (M) input operations or would you like to run a scripted =>(S) run? (M/S): ";
    std::string choice;
    std::cin >> choice;

    if(choice == "M" || choice == "m"){
        std::cout << "You chose to input manual opperations.\n\n";
        return 'M';
    }else if(choice == "S" || choice == "s"){
        std::cout << "You chose to use scripted input.\n\n";
        return 'S';
    }else{
        std::cout << "Input invalid, the scripted input will be used by default.\n\n";
        return 'S';
    }
}

void parseRequest(std::string request){
    if(request.size() < 7){std::cout << "*** Request Not Long Enough.\n"; return;}//break of request doesn't meet the minimum read request characters
    int ID = -1;
    if(request[0] - 48 <= 3 && request[0] - 48 >= 0){
        ID = request[0] - 48;//subtract 48 from a number character to get the number
        request.erase(0,2);
    }else{
        std::cout << "*** Core ID Format Invalid: " << request << "\n";
        return;
    }

    if(request.size() < 5){std::cout << "*** Request Not Long Enough.\n"; return;}
    char action = 'Z';
    if(request[0] == 'W' || request[0] == 'w'){
        action = 'W';
        request.erase(0,2);
    }else if (request[0] == 'R' || request[0] == 'r'){
        action = 'R';
        request.erase(0,2);
    }else{
        std::cout << "*** Action Format Invalid: " << request << "\n";
        return;
    }

    if(request.size() < 3){std::cout << "*** Request Not Long Enough.\n"; return;}
    int blockNumber = -1;
    if(request[0] >= 0 || request[0] <= 9){
        blockNumber = request[0] - 48;
        request.erase(0,2);
    }else{
        std::cout << "*** Block Number Format Invalid: " << request << "\n";
        return;
    }

    if(request.size() == 0){std::cout << "*** Request Not Long Enough.\n"; return;}
    int blockLocation = -1;
    if(request[0] >= 0 || request[0] <= 3){
        blockLocation = request[0] - 48;
        request.erase(0,2);
    }else{
        std::cout << "*** Block Location Format Invalid: " << request << "\n";
        return;
    }

    int value = -1;
    if(action == 'W'){
        value = std::stoi(request);
    }else if(action == 'R'){
        value = 0;
    }else{
        std::cout << "*** Write Value Format Invalid: " << request << "\n";
        return;
    }
    
    bus(ID, action, blockNumber, blockLocation, value);
}

void bus(const int coreNumber, const char action, const int blockNumber, const int blockLocation, const int writeValue){
    //std::cout << "User Input: " << coreNumber << ", " << action << ", "  << blockNumber << ", "  << blockLocation << ", "  << writeValue << ".\n";
    
}