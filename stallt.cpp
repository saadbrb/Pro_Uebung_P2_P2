#include "stallt.h"

int StallT::belgeteBoxen(){
    int size=0;
    for(PonyT* A: pferdeboxen){
        if(A != nullptr){
            size++;
        }
    }
    return size;
}

void StallT::feierabend(int geburtsJahr_, std::string name_, bool tmpr, unsigned genger){
    // tmpr könnte ekzemer oder kinderlieb variable sein
    //genger ist einfach ein signal, damit ich weiß an welchen art vom Pony handelt es sich

    if(genger == 1){
        PonyT* objkt = new ShetlandponyT(geburtsJahr_,name_,tmpr,0,0);
        einstellen(objkt);

    }
    else if (genger == 0) {
        PonyT* objkt = new IslandpferdT(geburtsJahr_,name_,tmpr,0,0);
        einstellen(objkt);
    }
    else {
        std::cout<<"Fehlermeldung bei genger!\n";
    }
}

int StallT::berechneJahr(){
    time_t seconds = time(NULL); // Aktuelle Zeit in Sekunden seit 01.01.1970
    int days = seconds / (60 * 60 * 24); // Umrechnung in Tage
    int jahre = days / 365.25; // Durchschnittliche Anzahl von Jahren (365,25 Tage pro Jahr)
    int aktuellesJahr = 1970 + jahre; // Aktuelles Jahr berechnen
    return aktuellesJahr;
}
bool StallT::einstellen(PonyT* obkjt_){
    for(unsigned i=0; i<N; i++){
        if(pferdeboxen[i]==nullptr){
            pferdeboxen[i]=obkjt_;

            return true;
        }
    }
    return false;
}
PonyT* StallT::herausholen(std::string name_){
    unsigned counter =0 ;
    for(unsigned i=0; i<N; i++){
        counter++;
        if(pferdeboxen[i] != nullptr){
            int alter;

            if(pferdeboxen[i]->gibName() == name_){
                std::cout<<"Alter des Reiters: "; std::cin>>alter;
                if(pferdeboxen[i]->istReitbar(alter)){
                    PonyT* tmpr = pferdeboxen[i];
                    pferdeboxen[i] = nullptr;
                    return tmpr;
                }
                else {
                    std::cout<<"Pony nicht reitbar\n";
                    return nullptr;
                }
            }
        }

    }

    std::cout<<"Fehlermeldung! Der von Ihnen angegebenen Name ist leider nicht gefunden\n";

    return nullptr;
}
float StallT::durchschnittsalter(){

    float sum=0;
    for(PonyT* A: pferdeboxen){
        if(A != nullptr){
            sum += (berechneJahr()- A->gibGeburtsJahr());
        }
    }
    sum = sum/belgeteBoxen();
    return sum;
}

void StallT::zeigInfo(){

    if(belgeteBoxen()>0){
        std::cout<<"\n";
        std::cout<<"wir sind im Jahr: "<<berechneJahr()<<"\n";
        std::cout<<"Durchschnittsalter betraegt: "<<durchschnittsalter()<<"\n";
        std::cout<<"Ponys, die im Stall gerade untergestellt sind: "<<belgeteBoxen()<<" \n";
        for(PonyT* A: pferdeboxen){
            if(A != nullptr){
                A->zeigInfo();
            }
        }
    }
    else {
        std::cout<<"Keine Info verfuegbar, da Pferdeboxen im Stall leer sind!\n";
    }
    std::cout<<"\n";

}

void StallT::ponyAnlegen(){


    bool sucess=true;
    while (sucess) {

        std::string  wahl;
        int geburtsjahr;
        std::string name;
        std::cout<<"Welche Rasse soll eingestellt werden? [0 - Isi | 1 - Shetty]: ";
        std::cin>>wahl; std::cout<<"\n";

        if(wahl=="0"){
            bool ekzemer=false;
            int i=0;
            std::cout<<"Geburtsjahr:";
            geburtsjahr=checkInt(); std::cout<<"\n";
            std::cout<<"Name eingeben: "; std::cin>>name;
            while (i==0) {
                std::cout<<"Ekzemer [y/n]: ";
                std::string wahl_;
                std::cin>>wahl_;
                if(wahl_=="y"){
                    ekzemer=true;
                    i++;
                }
                else if (wahl_=="n") {
                    ekzemer=false;
                    i++;
                }
                else {
                    std::cout<<"Falsche Eingabe! Bitte nochmal versuchen\n";
                }
            }
            PonyT* objkt = new IslandpferdT(geburtsjahr,name,ekzemer,0,0);
            if(einstellen(objkt)) {
                std::cout<<"\n++++++++++++++++++++++++++++++++\n";
                std::cout<<"Pony wurde erfolgreich eingefuegt\n";
                std::cout<<"++++++++++++++++++++++++++++++++\n";
            }
            else {
                std::cout<<"Pferdeboxen ist leider ganz voll!\n";
            }
            return;

        }
        else if (wahl=="1") {
            bool kinderlieb=false;
            int i=0;
            std::cout<<"Geburtsjahr:";
            geburtsjahr=checkInt(); std::cout<<"\n";
            std::cout<<"Name eingeben: "; std::cin>>name;
            while (i==0) {
                std::cout<<"kinderlieb [y/n]: ";
                std::string wahl_;
                std::cin>>wahl_;
                if(wahl_=="y"){
                    kinderlieb=true;
                    i++;
                }
                else if (wahl_=="n") {
                    kinderlieb=false;
                    i++;
                }
                else {
                    std::cout<<"Falsche Eingabe! Bitte nochmal versuchen\n";
                }
            }
            PonyT* objkt = new ShetlandponyT(geburtsjahr,name,kinderlieb,0,0);
            if(einstellen(objkt)) {
                std::cout<<"\n++++++++++++++++++++++++++++++++\n";
                std::cout<<"Pony wurde erfolgreich eingefuegt\n";
                std::cout<<"++++++++++++++++++++++++++++++++\n";
            }
            else {
                std::cout<<"Pferdeboxen ist leider ganz voll!\n";
            }
            return;
        }
        else {
            std::cout<<"Falsche Eingabe! Bitte nochmal versuchen\n";
        }

    }



}


int  StallT::checkInt(){

    int zahl=0;
    bool success = false;
    while (!success) {
        std::string inputStr;
        std::cin >> inputStr;
        char* end;
        zahl = strtod(inputStr.c_str(), &end);
        if (end != inputStr.c_str() + inputStr.size()) {
            std::cout << "Ungueltige Eingabe" << std::endl;
        } else {
            success = true;
        }
    }
    return zahl;
}

void StallT::pushSchet(int geburtsjahr,std::string name,bool kinderlieb){

    PonyT* objkt = new ShetlandponyT(geburtsjahr,name,kinderlieb,0,0);
    if(einstellen(objkt)) {
//        std::cout<<"\n++++++++++++++++++++++++++++++++\n";
//        std::cout<<"Pony wurde erfolgreich eingefuegt\n";
//        std::cout<<"++++++++++++++++++++++++++++++++\n";
    }
    else {
        std::cout<<"Pferdeboxen ist leider ganz voll!\n";
    }

}
void StallT::pushIsland(int geburtsjahr,std::string name,bool ekzemer){
    PonyT* objkt = new IslandpferdT(geburtsjahr,name,ekzemer,0,0);
    if(einstellen(objkt)) {
//        std::cout<<"\n++++++++++++++++++++++++++++++++\n";
//        std::cout<<"Pony wurde erfolgreich eingefuegt\n";
//        std::cout<<"++++++++++++++++++++++++++++++++\n";
    }
    else {
        std::cout<<"Pferdeboxen ist leider ganz voll!\n";
    }
}


void StallT::weidegang(std::vector<PonyT*> &weide){

    const int breite = 30;
    const int laenge = 40;
    srand(time(NULL)); // Zufallszahlengenerator einmalig initialisieren

    for(unsigned i=0; i<N; i++){
        if(pferdeboxen[i] != nullptr){
            float zx = (float)rand() / RAND_MAX;
            float zy = (float)rand() / RAND_MAX;
            float x = zx * breite;
            float y = zy * laenge;
            pferdeboxen[i]->ortXY(x,y);
            weide.push_back(pferdeboxen[i]);
            pferdeboxen[i] = nullptr; // auf nullptr setzen, damit wir keine unbeabsichtigten Zugriffe auf gelöschte Objekte haben
        }
    }
}

void StallT::deletAllElemnt(){
    for(unsigned i=0; i<N; i++){
        pferdeboxen[i] = nullptr;
    }
}
