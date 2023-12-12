#include "Map.h"
#include <iostream>

using namespace std;


//permet de charger une map grâce à un fichier texte
void Map::charger(string filename)
{
    // Déclaration des dimensions de la map en brut ( amélioration en cours)
    _lignes = 31;
    _colonnes = 28;
    _Tab.resize(_lignes, vector<Tuile>(_colonnes,SOL));//redimensionnement d'un tableau de type vector 2D initialisé à sol (=0)

    //traitement du fichier txt
    ifstream fichier(filename);

    string temp;//varaible temp de type pour stocker une ligne

    if(fichier)//l'ouverture du fichier c'est bien passé
    {
        //scrute chaque ligne du fichier
        for(int i=0;i<_lignes;i++)
        {
            //recupère la ligne et la stocke dans temp
            getline(fichier,temp);
            //scrute les éléments de la ligne (=temp)
            for(int j=0;j<temp.length();j++)
            {

                cout<<temp[j];
                //rajouter la valeur enum MUR ou SOL en fonction du caractère lu
                switch(temp[j])
                {
                    case '#':
                        _Tab[i][j]= MUR;
                        break;
                    case '.':
                        _Tab[i][j]= SOL;
                        break;
                    default:
                        cerr<<"erreur : caractere inconnu"<<endl;
                        break;
                }
            }
            cout<<endl;
        }
    }
    else
    {
        cerr<<"erreur"<<endl;
    }
}

//Retourne le nmb de lignes
int Map::getLignes() const
{
    return _lignes;
}

//Retourne le nmb de colonnes
int Map::getColonnes() const
{
    return _colonnes;
}

//indique s'il est possible de se déplacer dans la case de direction d
bool Map::estBloque(int ligne, int colonne, Direction d)
{
    // return true si l'element du tableau est égal à 0(=SOL)
    switch(d)
    {
        case HAUT:
            cout<<"haut"<<endl;
            return (_Tab[ligne-1][colonne] == 0);

        case BAS:
            cout<<"bas"<<endl;
            return (_Tab[ligne+1][colonne] == 0);

        case GAUCHE:
            cout<<"gauche"<<endl;
            return (_Tab[ligne][colonne-1] == 0);

        case DROITE:
            cout<<"droite"<<endl;
            return (_Tab[ligne][colonne+1] == 0);

        default:
            cerr<<"erreur : direction non reconnue"<<endl;
            return false;
    }
}

//indiquer le nombre de SOL autour d'une case Map
int Map::compterSorties(int ligne, int colonne)
{
    //variable compteur
    int compteur =0;
    //boucle qui scrute les élements du tableau autour d'une case dans un rayon de 1
    // a a a
    // a x a
    // a a a
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            //cout<<_Tab[ligne+i][colonne+j];
            //si l'élement scruté est un sol ET différent de la case où on se situe (càd le cas _Tab[0][0]) ET différent d'un coin du rayon scruté
            if(_Tab[ligne+i][colonne+j]==SOL && !(i==0 && j==0) && !(i==-1 && j==-1) && !(i==-1 && j==1) && !(i==1 && j==-1) && !(i==1 && j==1))
            {
                //on augmente le compteur de 1
                compteur++;
            }
        }
    }
    //on retourne le nombre de compteur
    return compteur;
}


//Surcharge de l'opérateur<<
ostream& operator<<(ostream& c, Map m)
{
    for (int i = 0; i < m._lignes; ++i)
    {
        for (int j = 0; j < m._colonnes; ++j)
        {
            c<<m._Tab[i][j];
        }
        c<<endl;
    }
    return c;
}
