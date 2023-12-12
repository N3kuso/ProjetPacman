#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

enum Tuile {SOL, MUR};
enum Direction {HAUT, BAS, GAUCHE, DROITE};

class Map
{
protected:
    vector<vector<Tuile>> _Tab;
    int _lignes;
    int _colonnes;



public:
    void charger(string filename);
    int getLignes() const;
    int getColonnes() const;
    bool estBloque(int ligne, int colonne, Direction d);
    int compterSorties(int ligne, int colonne);

friend ostream& operator<<(ostream& c, Map m);



};

#endif // MAP_H_INCLUDED
