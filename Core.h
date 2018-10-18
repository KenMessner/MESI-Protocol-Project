//Core class for each of the four cores
//MESI Project, The goal in this project is to implement the MESI cache coherence protocol
//Author: Kenneth Messner
//Last Modified: 10/12/18

#include <iostream>
#include <string>

#ifndef CORE_H
#define CORE_H

class Core{
public:
    Core();
    Core(int ID){coreID = ID; coreState = 'I';}
    Core(int ID, char state){coreID = ID; coreState = state;}

    void requestMemory(int blockID, int memoryID);
    void writeMemory(int blockID, int memoryID);
    void invalidate(int invalidBlockID);
    int localRead(int memoryID);
    void localWrite(int memoryID, int updatedValue);
    void snoop();

    char getState();
    void changeState(char newState);
    int getBlockID();

private:
    int coreID;
    char coreState;//States: I = Invalid, S = Shared, E = Exclusive, M = Modified

    int casheBlockID = -1;
    int cashe[4] = {-1};
};

void Core::requestMemory(int blockID, int memoryID){
    std::cout << "Core " << coreID << " requesting memory from memory location location " << blockID << ".\n";
}

void Core::writeMemory(int blockID, int memoryID){
    if(coreState == 'M'){
        std::cout << "Core " << coreID << " requesting memory from memory location location " << blockID << ".\n";
    }else{
        std::cout << "CORE NOT IN MODIFIED STATE, WRITE NOT ALLOWED.\N";
    }
}

void Core::invalidate(int invalidBlockID){
    std::cout << "Core " << coreID << " invalidating other cores with block " << ".\n";
}

int Core::localRead(int memoryID){
    if(memoryID >= 0 && memoryID <= 4){
        std::cout << "Core " << coreID << " has performed a local write on block " << casheBlockID << ".\n";
        return cashe[memoryID];
    }else{
        std::cout << "CORE " << coreID << "'S CASHE READ LOCATION " << memoryID << " IS INVALID.\n";
    }
    return 0;
}

void Core::localWrite(int memoryID, int updatedValue){
    if(memoryID >= 0 && memoryID <= 4){
        cashe[memoryID] = updatedValue;
    }else{
        std::cout << "CORE " << coreID << "'S CASHE WRITE LOCATION " << memoryID << " IS INVALID.\n";
    }
}

void Core::snoop(){
    std::cout << "Core " << coreID << " snooping on bus.\n";
    std::cout << "Core " << coreID << "'s state is " << coreState << "\n";
}

char Core::getState(){
    return coreState;
}

void Core::changeState(char newState){
    coreState = newState;
}

int Core::getBlockID(){
    return cahseBlockID;
}

#endif