#include "shetlandponyt.h"

bool ShetlandponyT::istKiunderlieb(){
    return kinderlieb;
}
bool ShetlandponyT::istReitbar(int zahl){

    if(zahl > 8 && zahl <= 12){
        return true;
    }
    else if (zahl >= 5 && zahl <= 8 && istKiunderlieb()) {
        return true;
    }
    else {
        return false;
    }
}
void ShetlandponyT::zeigInfo(){

    std::cout<<"Shetlandpony";
    std::cout<<" "<<gibName()<<"       "<<gibGeburtsJahr()<<" ";
    if(istKiunderlieb()){
        std::cout<<"   y \n";
    }
    else {
        std::cout<<"   n \n";
    }
}
unsigned ShetlandponyT::getArt(){
    return art;

}

bool ShetlandponyT::gibFrage(){
    return kinderlieb;
}
