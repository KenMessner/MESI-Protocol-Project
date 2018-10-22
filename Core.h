//Core class for each of the four cores
//MESI Project, The goal in this project is to implement the MESI cache coherence protocol
//Author: Kenneth Messner
//Last Modified: 10/12/18

#include <fstream>
#include <iostream>
#include <iostream>
#include <string>

#ifndef CORE_H
#define CORE_H

//GLOBAL - Array of Ten Blocks of Four Memory Locations
int systemMemory[10][4] = {0};

class Core{
public:
    Core();
    Core(int ID){coreID = ID; coreState = 'I';}
    Core(int ID, char state){coreID = ID; coreState = state;}

    void requestMemory(int blockID, int memoryID);
    void writeMemory();
    int localRead(int memoryID);
    void localWrite(int memoryID, int updatedValue);

    char getState();
    void changeState(char newState);
    int getBlockID();
    void changeBlockID(int newBlockID);

private:
    int coreID;
    char coreState;//States: I = Invalid, S = Shared, E = Exclusive, M = Modified

    int casheBlockID = -1;
    int cashe[4] = {-1};
};

void Core::requestMemory(int blockID, int memoryID){
    casheBlockID = blockID;
    cashe[0] = systemMemory[casheBlockID][0];
    cashe[1] = systemMemory[casheBlockID][1];
    cashe[2] = systemMemory[casheBlockID][2];
    cashe[3] = systemMemory[casheBlockID][3];
}

void Core::writeMemory(){
    systemMemory[casheBlockID][0] = cashe[0];
    systemMemory[casheBlockID][1] = cashe[1];
    systemMemory[casheBlockID][2] = cashe[2];
    systemMemory[casheBlockID][3] = cashe[3];
    casheBlockID = -1;
}

int Core::localRead(int memoryID){
        return cashe[memoryID];
}

void Core::localWrite(int memoryID, int updatedValue){
    cashe[memoryID] = updatedValue;
}

char Core::getState(){
    return coreState;
}

void Core::changeState(char newState){
    coreState = newState;
}

int Core::getBlockID(){
    return casheBlockID;
}

void Core::changeBlockID(int newBlockID){
    casheBlockID = newBlockID;
}

#endif