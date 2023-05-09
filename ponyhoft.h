#ifndef PONYHOFT_H
#define PONYHOFT_H
#include<iostream>
#include<vector>
#include<stdbool.h>
#include<cmath>
#include<algorithm>
#include<limits>
#include<string>
#include<fstream>
#include"shetlandponyt.h"
#include"islandpferdt.h"
#include"ponyt.h"
#include"stallt.h"


class PonyhofT
{
private:
    StallT stallung;
    std::vector<PonyT*> beimReiten;
    std::vector<PonyT*> weide;
public:
    //    PonyhofT(const std::string& datei);
    PonyhofT();
    void userDialog();
    void ponyHolen();
    void feierabend();
    ~PonyhofT(){

        feierabend();

        // Öffne eine Textdatei zum Schreiben
        std::ofstream file("C:/Users/saadb/OneDrive/Dokumente/Pro_Uebung_P2_P2/PonyT.txt#");
        if (!file.is_open()) {
            std::cout << "Datei konnte nicht geöffnet werden. Also wurde wegen dieser Fehler nichts gespeichert" << std::endl;
            return;
        }

        else {
            // Umleiten der cout-Ausgabe in die Textdatei
            std::streambuf* cout_stream = std::cout.rdbuf();
            std::cout.rdbuf(file.rdbuf());

            // Hier kommt der Code aus der ursprünglichen display-Methode hin


            for (PonyT* pony : beimReiten) {
                pony->zeigInfo();
            }

            // Zurücksetzen der cout-Ausgabe auf den ursprünglichen Buffer
            std::cout.rdbuf(cout_stream);

            // Schließe die Datei
            file.close();

            std::cout << "Ponys wurden erfolgreich in ponys.txt gespeichert." << std::endl;
        }

        for(PonyT* A: beimReiten){
            delete A;
        }


    }
};

#endif // PONYHOFT_H
