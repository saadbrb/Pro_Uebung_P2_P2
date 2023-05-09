#include <iostream>
#include"ponyhoft.h"
unsigned ponyHufe(unsigned numPonys){
    if(numPonys==1)
        return 4;
    if(numPonys > 1)
        return 4 + ponyHufe(numPonys-1);
}


int main()
{
    //    PonyhofP objkt("ponys.txt");
        PonyhofT obj;
        //kleiner test


        obj.userDialog();
    //    std::cout<<"Der Besitzer hat "<<ponyHufe(4)<<" Hufe die Ponys auf seinem Hof"<<"\n";

    return 0;
}
