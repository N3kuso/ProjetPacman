#include <iostream>
#include "Map.h"

using namespace std;
#include <SFML/Graphics.hpp>

int main()
{

    Map toto;
    toto.charger("map.txt");
    cout<<"lignes : "<<toto.getLignes()<<endl;
    cout<<"colonnes : "<<toto.getColonnes()<<endl;
    cout<<toto<<endl;

    if(toto.estBloque(1,1,DROITE))
    {
        cout<<"je peux me déplacer"<<endl;
    }
    cout<<"sorties possibles : "<<toto.compterSorties(1,6)<<endl;
}
