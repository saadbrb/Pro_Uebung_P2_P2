#ifndef ISLANDPFERDT_H
#define ISLANDPFERDT_H
#include<iostream>
#include<vector>
#include<stdbool.h>
#include<cmath>
#include<algorithm>
#include<limits>
#include<string>
#include"ponyt.h"

class IslandpferdT : public PonyT
{
private:
    bool ekzemer;
    const unsigned art = 0;
public:
    IslandpferdT(int geburtsJahr_, std::string name_, bool ekzemer_, float x, float y): PonyT(geburtsJahr_,name_,x,y), ekzemer(ekzemer_){}
    bool hatEkzem();
    bool istReitbar(int zahl) override;
    bool gibFrage() override;
    void zeigInfo() override;
    unsigned getArt()override;
    ~IslandpferdT() override{}
};
#endif // ISLANDPFERDT_H
