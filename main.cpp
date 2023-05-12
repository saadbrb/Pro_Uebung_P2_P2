#include <iostream>
#include"ponyhoft.h"
unsigned ponyHufe(unsigned numPonys){
    if(numPonys==1)
        return 4;
    if(numPonys > 1)
        return 4 + ponyHufe(numPonys-1);
}


int main(int argc, char* argv[])
{

    std::string file_name;
    if (argc == 1) {
        //std::cerr << "No filename provided." << std::endl;
        file_name = "ponyst.txt";
    }
    else {

        file_name = argv[1];

    }

    std::cout << "Text file name: " << file_name << std::endl;

    PonyhofT obj(file_name);
    //kleiner test

    obj.userDialog();

    //    std::cout<<"Der Besitzer hat "<<ponyHufe(4)<<" Hufe die Ponys auf seinem Hof"<<"\n";

    return 0;
}
