//Main function where IO and BUS functions will be placed
//MESI Project, The goal in this project is to implement the MESI cache coherence protocol
//Author: Kenneth Messner
//Last Modified: 10/12/18

#include "Core.h"

char initalPrompt();
void parseRequest(std::string request);
void bus();

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
        std::cout << "Core Request works as follows,\n Core Number{0-3}, Operation{R/W}, Block{0-9}, Memory Location{0-3}, Write Value\n EX1: 0 R 3 0\n EX2: 2 W 0 1 2000\n EX3: 3 W 7 0 220\n\n";
        std::cout << "Enter Request: ";
        std::cin >> userRequest; 
    }else{
        std::cout << "ADD FILE INPUT FOR SCRIPTED EVENT\N\N";
    }
    
    int cycleCounter = 0;
    while(userRequest != "q" && userRequest != "Q" && userRequest != "quit" && userRequest != "Quit" && userRequest != "QUIT" && cycleCounter < 100){
        std::cout << "Cycle " << cycleCounter << ": ";
        
        parseRequest(userRequest);
    
        if(choice = 'M'){
            std::cout << "Enter Request: ";
            std::cin >> userRequest;
        }else{
            userRequest = "quit";
        }
        ++cycleCounter;
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
    if(request[0] <= 4 && request[0] >= 0 && request.size() > 2){
        int ID = request[0] - 48;//subtract 48 from a number character to get the number
        request.erase(0,1);
    }else{
        std::cout << "Format incorrect.\n";
        return;
    }

    if(request[0] == 'W' || request[0] == 'w' && request.size() > 2){
        char action = 'W';
    }else if (request[0] == 'R' || request[0] == 'r' && request.size() > 2){
        char action = 'R';
    }else{
        std::cout << "Format incorrect.\n";
        return;
    }

    //read in block num, drop space, read in location in block, drop space, IF WRITE read in value (muli digit values accepted.)
    //sent information to bus and bus will use core methods

}

void bus(){
    
}