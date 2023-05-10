#ifndef STALLT_H
#define STALLT_H
#include<iostream>
#include<vector>
#include<stdbool.h>
#include<cmath>
#include<algorithm>
#include <ctime>
#include <cstdlib>
#include<limits>
#include<string>
#include"ponyt.h"
#include "shetlandponyt.h"
#include "islandpferdt.h"
#define N 20

class StallT
{
private:
    PonyT* pferdeboxen[N];

public:
    StallT(){
        for(unsigned i=0; i<N; i++){
            pferdeboxen[i] = nullptr;
        }
    }
    int belgeteBoxen();
    bool einstellen(PonyT* obkjt_);
    PonyT* herausholen(std::string name_);
    float durchschnittsalter();
    void weidegang(std::vector<PonyT*> &weide);
    void zeigInfo();
    void deletAllElemnt();
    void ponyAnlegen();
    int checkInt();
    int berechneJahr();
    void feierabend(int geburtsJahr_, std::string name_, bool momen, unsigned genger);
    void pushSchet(int geburtsjahr,std::string name,bool kinderlieb);
    void pushIsland(int geburtsjahr,std::string name,bool ekzemer);
    ~StallT(){
        for(PonyT* A: pferdeboxen){
            delete A;
        }
    }
};
#endif // STALLT_H
