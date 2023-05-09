#include "ponyt.h"

float Position::gibX(){
    return x;
}
float Position::gibY(){
    return y;
}
void Position::addX(float x_){
    x = x_;
}
void Position::addY(float y_){
    y = y_;
}

void PonyT::ortXY(float x, float y){
    ort.addX(x); ort.addY(y);
}
float PonyT::gibX(){
    return ort.gibX();
}
float PonyT::gibY(){
    return ort.gibY();
}

void Position::addPosition(const Position & objkt_){
    addX(objkt_.x);
    addY(objkt_.y);
}

void PonyT::setzePos(const Position & objkt_){
    ort.addPosition(objkt_);
}

std::string PonyT::gibName(){
    return name;
}


int PonyT::gibGeburtsJahr(){
    return geburtsJahr;
}
