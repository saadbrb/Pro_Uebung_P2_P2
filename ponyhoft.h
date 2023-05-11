#ifndef PONYHOFT_H
#define PONYHOFT_H
#define WRITE_BIN
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
    void dateiEinlesen();
    ~PonyhofT(){

        feierabend();

        //hier hendelt es um neueu version: of binöre bzw. ASCI
        #ifdef WRITE_BIN
        std::cout << "Binary writer called...\n";
        std::ofstream outfile("C:/Users/saadb/OneDrive/Desktop/Pro_Uebung_P2_P2/ponyst.bin", std::ios::out | std::ios::binary);
        // Hier öffnen wir eine binäre Datei zum Schreiben mit dem Namen "ponys.bin"
        if (!outfile.is_open()) {
            std::cout << "Datei ponys.bin  konnte nicht geöffnet werden. Also wurde wegen dieser Fehler nichts gespeichert" << std::endl;
            return;
        }

        else {
            // Umleiten der cout-Ausgabe in die Textdatei
            std::streambuf* cout_stream = std::cout.rdbuf();
            std::cout.rdbuf(outfile.rdbuf());

            // Hier kommt der Code aus der ursprünglichen display-Methode hin


            for (PonyT* pony : beimReiten) {
                pony->zeigInfo();
            }

            // Zurücksetzen der cout-Ausgabe auf den ursprünglichen Buffer
            std::cout.rdbuf(cout_stream);

            // Schließe die Datei
            outfile.close();

            std::cout << "Ponys wurden erfolgreich in ponys.bin gespeichert." << std::endl;
        }
        #else
        std::cout << "ASCII writer called...\n";
        // std::ofstream outfile("ponyst.txt");
          std::ofstream file("C:/Users/saadb/OneDrive/Desktop/Pro_Uebung_P2_P2/PonyT.txt");

        if (!file.is_open()) {
            std::cout << "Datei ponys.txt konnte nicht geöffnet werden. Also wurde wegen dieser Fehler nichts gespeichert" << std::endl;
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
        #endif


        for(PonyT* A: beimReiten){
            delete A;
        }


    }
};

#endif // PONYHOFT_H
