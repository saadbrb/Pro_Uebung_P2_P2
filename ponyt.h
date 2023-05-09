#ifndef PONYT_H
#define PONYT_H
#include<iostream>
#include<vector>
#include<stdbool.h>
#include<cmath>
#include<algorithm>
#include<limits>
#include<string>

class Position //diese class ist bis ende verwendbar
{
private:
    float x;
    float y;
public:
    Position(float x, float y){
        this->x = x;
        this->y = y;
        x=0;
        y=0;
    }
    //  Position(){}
    float gibX();
    float gibY();

    void addX(float x_);
    void addY(float y_);
    void addPosition(const Position & objkt_);
};//bis hier
class PonyT
{
protected:
    int geburtsJahr;
    std::string name;
    Position ort;// bis endee verwendbar
public:
    PonyT(int geburtsJahr_, std::string name_, float x, float y ): geburtsJahr(geburtsJahr_), name(name_) , ort(x,y){

    }
    std::string gibName();
    int gibGeburtsJahr();
    void setzePos(const Position & objkt_);
    void ortXY(float x, float y);
    float gibX();
    float gibY();
    virtual bool istReitbar(int zahl) = 0;
    virtual unsigned getArt() = 0;
    virtual void zeigInfo() = 0;
    //hier würde, ob es ekzemer oder kinderlieb zurückgibt, unterschied wirde es aber in feierabend funktion vom stall angezeigt
    virtual bool gibFrage() = 0;
    virtual ~PonyT(){

    }
};
#endif // PONYT_H
