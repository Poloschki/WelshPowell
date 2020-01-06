#include <iostream>

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Sommet
{
private:
    int couleur;
    char nom;
    vector<Sommet> voisin;


public:

    Sommet(char nom){
        this->couleur=0;
        this->nom = nom;
    }
    void ajoutVoisin(Sommet voisin){
        this->voisin.push_back(voisin);
    }

    char getNom() const;
    void setNom(char value);
};

class Graphe {
public:
    vector<Sommet>sommetDuGraphe;
    Graphe();

    void ajoutSommet(char sommet){
        Sommet newSommet = *new Sommet(sommet);
        this->sommetDuGraphe.push_back(newSommet);
    }

    bool verifSommet(Sommet s)
    {
        for (Sommet s1 : sommetDuGraphe){
            if (s1.getNom()==s.getNom()) return false;
        }
        this->sommetDuGraphe.push_back(s);
        return true;
    }

    void lectureFichier(string fileName)
    {
        char caractere;
        bool voisin = false;
        fstream fin(fileName, fstream::in);
        while (fin >> caractere) {
            if(caractere == '-'){voisin = true; continue; }
            if(caractere == '\n'){voisin = false; continue; }
            if(caractere == ' ')continue;
            Sommet tmp = *new Sommet(caractere);
            if(!this->verifSommet(tmp))
                this->ajoutSommet(caractere);
            if(voisin)
            {
            }
        }
        fin.close();
    }

};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

char Sommet::getNom() const
{
return nom;
}

void Sommet::setNom(char value)
{
nom = value;
}
