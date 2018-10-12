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

    void requestMemory(int blockID);
    void writeMemory(int blockID);
    void invalidate();

    int localRead(int casheLocation);
    void localWrite(int casheLocation, int updatedValue);

    void snoop();

private:
    int coreID;
    char coreState;//States: I = Invalid, S = Shared, E = Exclusive, M = Modified

    int cashe[4];
};

void Core::requestMemory(int blockID){
    std::cout << "Core " << coreID << " requesting memory from memory location location " << blockID << ".\n";
}

void Core::writeMemory(int blockID){
    if(coreState == 'M'){
        std::cout << "Core " << coreID << " requesting memory from memory location location " << blockID << ".\n";
    }else{
        std::cout << "CORE NOT IN MODIFIED STATE, WRITE NOT ALLOWED.\N";
    }
}

void Core::invalidate(){
    std::cout << "Core " << coreID << " invalidating other cores with block " << ".\n";
}

int Core::localRead(int casheLocation){
    if(casheLocation >= 0 && casheLocation <= 4){
        return cashe[casheLocation];
    }else{
        std::cout << "CORE " << coreID << "'S CASHE READ LOCATION " << casheLocation << " IS INVALID.\N";
    }
    return 0;
}

void Core::localWrite(int casheLocation, int updatedValue){
    if(casheLocation >= 0 && casheLocation <= 4){
        cashe[casheLocation] = updatedValue;
    }else{
        std::cout << "CORE " << coreID << "'S CASHE WRITE LOCATION " << casheLocation << " IS INVALID.\N";
    }
}

void Core::snoop(){
    std::cout << "Core " << coreID << " snooping on bus.\n";
    std::cout << "Core " << coreID << "'s state is " << coreState << "\n";
}

#endif