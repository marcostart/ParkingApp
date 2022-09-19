#include <iostream>
//#include <windows.h>
#include "Application.h"
#include "Clients.h"
#include "Gestionnaire.h"
#include "Vehicule.h"
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    string nom,prenom,nplaque;
   string type;
    double telephone, duree;
    cout << "Test Parking\nVotre nom,prenom,nplaque,telephone,duree,type !" << endl;
    cin.clear();
    getline(cin ,nom);
    while (nom.size()==0)
        getline(cin ,nom);
    cout <<nom<<endl;
    getline(cin ,prenom);
    while (prenom.size()==0)
        getline(cin ,prenom);
    cout <<prenom<<endl;
    getline(cin ,nplaque);
    while (nplaque.size()==0)
        getline(cin ,nplaque);
    cout <<nplaque<<endl;
    cin >>telephone;
    cout <<telephone<<endl;
    cin >>duree;
    cout <<duree<<endl;
    cin>>type;
    cout <<type<<endl;
    getchar();
    Clients boss(nom,prenom,telephone,nplaque,duree,type);
    boss.generer_code();
    cout<< "votre numero de place : "<<boss.num_place<<"\nVotre code est :"<<boss.code_id<<endl;
    getchar();
    getchar();
    boss.lancer_chrono();
    boss.verifier_chrono();
    boss.affiche_date();
    return 0;
}
