#include "Clients.h"
#include <ctime>
#include <time.h>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Application.h"
#include "Vehicule.h"

using namespace std;

Clients::Clients(string nom,string prenom,double telephone,string num_plaque,double duree,string type):Application(),Vehicule(num_plaque,type,duree),
            nom(nom),prenom(prenom),telephone(telephone)
{
    //ctor
}

Clients::~Clients()
{
    this->enregistrer_info();
}
void Clients::lancer_chrono()
{
    time_t temps;
    time(&temps);//temps actuel
    temps+=(time_t)(duree*3600);
    date_prevue=*localtime(&temps);
     cout <<"prevu "<<temps<<endl;
}
void Clients::verifier_chrono()
{
    time_t temps, temps_dep;
    time(&temps);//temps d'arrivée
    date_arriv=*localtime(&temps);

    temps_dep=mktime(&date_prevue);
    if (difftime(temps,temps_dep)>0)
        ponct=false;
    else
        ponct=true;
    cout <<"actuel "<<temps<<endl;
}
double Clients::generer_amende(double duree)
{
    time_t temps_dep,temps_ar;
    temps_dep=mktime(&date_prevue);
    temps_ar=mktime(&date_arriv);
    if (difftime(temps_ar,temps_dep)<=0)
        return 0;
    else
        return 2500;
}
void Clients::generer_code()
{
    string code;
    srand(time(NULL));
    code=rand()%26+65;
    code_id+=code;
    cout <<"\n....."<<code_id<<endl;
    code_id+=num_plaque;
    cout <<"\n....."<<code_id<<endl;
    this->recuperer_info();
    num_place=this->occuper_place(type_vehicule);
    code_id+=num_place;
    Table_code.insert(make_pair(code_id.c_str(),nom.c_str()));
    Table_code.insert(make_pair(code_id.c_str(),prenom.c_str()));
    Table_code.insert(make_pair(code_id.c_str(),num_plaque.c_str()));
}
bool Clients::affiche_date()
{
    char format1[128], format2[128];
    strftime(format1,128,"%A %x \n%X %Z\n", &date_prevue);
    strftime(format2,128,"%A %x \n%X %Z\n", &date_arriv);
    cout <<"Date actuelle :\n"<<endl;
    puts(format2);
    cout <<"Date de fin prevue :\n"<<endl;
    puts(format1);

    return ponct;
}
