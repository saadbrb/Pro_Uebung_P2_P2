#include "islandpferdt.h"

bool IslandpferdT::istReitbar(int zahl){

    return zahl >= 10;
}
void IslandpferdT::zeigInfo(){

    std::cout<<"Islandpferd";
    std::cout<<" "<<gibName()<<"       "<<gibGeburtsJahr()<<" ";
    if(hatEkzem()){
        std::cout<<"   y \n";
    }
    else {
        std::cout<<"   n \n";
    }
}
unsigned IslandpferdT::getArt(){
    return art;
}

bool IslandpferdT::hatEkzem(){
    return ekzemer;
}
bool IslandpferdT::gibFrage() {
    return ekzemer;
}
