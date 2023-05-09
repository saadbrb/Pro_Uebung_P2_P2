#include "ponyhoft.h"
using namespace std;
PonyhofT::PonyhofT() {

    ifstream infile("C:/Users/saadb/OneDrive/Dokumente/Pro_Uebung_P2_P2/PonyT.txt"); // Öffnen der Datei "ponys.txt"
    if (!infile.is_open()) {
        throw runtime_error("Datei konnte nicht geoeffnet werden!");
    }

    int geburtsJahr_;
    std::string name_;
    std::string pony_art;

    char frage_zum_y_n;
    int zeilennummer = 0;
    // Einlesen der Ponys und Hinzufügen zum Stall
    while (infile >> pony_art >> name_ >> geburtsJahr_ >> frage_zum_y_n) {
        zeilennummer++;

        if(pony_art == "Islandpferd"){
            bool test = true;
            if(frage_zum_y_n == 'y'){
                test = true;
            }
            else if (frage_zum_y_n == 'n') {
                test = false;
            }
            else {
                throw runtime_error("Falsches Format in Zeile " + to_string(zeilennummer) + "!");
            }
            stallung.pushIsland(geburtsJahr_, name_, test);
        }
        else if (pony_art == "Shetlandpony") {
            bool test =true ;
            if(frage_zum_y_n == 'y'){
                test = true;
            }
            else if (frage_zum_y_n == 'n') {
                test = false;
            }
            else {
                throw runtime_error("Falsches Format in Zeile " + to_string(zeilennummer) + "!");
            }
            stallung.pushSchet(geburtsJahr_, name_, test);
        }
        else {
            std::cout<<"Ponyart ist leider nicht erkannt, daher wurde kein Pony am Pferderbosen reingefuegt!\n";
        }
    }

    infile.close(); // Schließen der Datei "ponys.txt"
}
void PonyhofT::feierabend(){

    for(unsigned i=0; i<beimReiten.size(); i++){

        stallung.feierabend(beimReiten[i]->gibGeburtsJahr(), beimReiten[i]->gibName(), beimReiten[i]->gibFrage(), beimReiten[i]->getArt());
    }
}

void PonyhofT::ponyHolen(){
    if(stallung.belgeteBoxen()>0){
        std::string name;
        std::cout<<"Name des zu holenden Ponys eingeben: ";
        std::cin>>name;
        PonyT* tmpr = stallung.herausholen(name);

        if(tmpr != NULL){
            unsigned art  = tmpr->getArt();
            if(art == 1){
                beimReiten.push_back(new ShetlandponyT(*dynamic_cast<ShetlandponyT*>(tmpr)));

                std::cout<<"Pony wird geritten\n";
            }
            else if (art == 0) {
                beimReiten.push_back(new IslandpferdT(*dynamic_cast<IslandpferdT*>(tmpr)));

                std::cout<<"Pony wird geritten\n";
            }
            else {
                std::cout<<"Fehlermedlung Art!\n";
            }
        }


    }
    else {
        std::cout<<"\nPferdeboxen in Stall ist leider immer noch leer! Daher koennte nichts abgeholt!\n";
    }
}


void PonyhofT::userDialog(){
    std::cout<<"Hallo!\n";
    bool sucess = true;

    while (sucess) {
        std::cout<<"=================Menu=================\n";
        std::cout<<"1 Pony einstellen\n";
        std::cout<<"2 Pony zum Reiten holen\n";
        std::cout<<"3 Ponys kontrollieren\n";
        std::cout<<"4 Ponys auf Weide schicken\n";
        std::cout<<"0 Programm beenden\n";
        std::cout<<"======================================\n";
        std::cout<<"Auswahl (0-3)\n";
        std::string wahl;
        std::cin>>wahl;
        if(wahl=="1"){

            stallung.ponyAnlegen();
        }
        else if(wahl=="2"){

            ponyHolen();
        }
        else if(wahl=="3"){
            stallung.zeigInfo();
            std::cout<<"Ponys, die im Moment geritten werden: "<<beimReiten.size()<<"\n";
            if(weide.size()>0){
            std::cout<<"\nPonys in Weide mit Position ungleich (0, 0) : \n";

            for(unsigned i=0; i<weide.size(); i++){

                if(weide[i] != NULL ){
                    if( weide[i]->gibX()!=0.0 && weide[i]->gibY()!=0.0){
                        weide[i]->zeigInfo();
                        std::cout<<"-> x= "<<weide[i]->gibX()<<" y= "<<weide[i]->gibY()<<"\n";
                    }

                }
            }
            }
            else {
                std::cout<<"Weideboxen sind leer!\n";
            }

        }
        else if (wahl == "4") {
            if(stallung.belgeteBoxen()>0){

                stallung.weidegang(weide);
                std::cout<<"Abholung wurde erfolgreich durchgefuehrt!\n";

            }
            else {
                std::cout<<"Es konnte leider nicht zum Weide abgeholt werden, da pferdeboxen leer ist!\n";
            }
        }
        else if(wahl=="0"){
            std::cout<<"Auf Wiedersehen!\n";
            sucess = false;

        }
        else {
            std::cout<<"Ungueltige Eingabe! Bitte nochmal versuchen.\n";
        }


    }
}
