#ifndef SHETLANDPONYT_H
#define SHETLANDPONYT_H

#include<iostream>
#include<vector>
#include<stdbool.h>
#include<cmath>
#include<algorithm>
#include<limits>
#include<string>
#include"ponyt.h"

class ShetlandponyT : public PonyT
{
private:
    bool kinderlieb;

    const unsigned art=1;
public:
    ShetlandponyT(int geburtsJahr_, std::string name_, bool kinderlieb_, float x, float y): PonyT(geburtsJahr_,name_, x,y), kinderlieb(kinderlieb_){}
    bool istKiunderlieb();
    bool istReitbar(int zahl) override;
    void zeigInfo() override;
    unsigned getArt()override;
    bool gibFrage() override;
    ~ShetlandponyT() override{}
};
#endif // SHETLANDPONYT_H
