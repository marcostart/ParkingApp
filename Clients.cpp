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

}

Clients::~Clients()
{
    this->enregistrer_info(this->code_id);
}
void Clients::lancer_chrono()
{
    time_t temps;
    time(&temps);//temps actuel
    date_depart=*localtime(&temps);
    temps+=(time_t)(duree*3600);
    date_prevue=*localtime(&temps);
}
void Clients::verifier_chrono()
{
    time_t temps, temps_dep;
    time(&temps);//temps d'arrivee
    date_arriv=*localtime(&temps);

    temps_dep=mktime(&date_prevue);
    if (difftime(temps,temps_dep)>0)
        ponct=false;
    else
        ponct=true;
}
double Clients::generer_amende(double duree)
{
    time_t temps_prev,temps_ar;
    temps_prev=mktime(&date_prevue);
    temps_ar=time(NULL);
    if (difftime(temps_ar,temps_prev)<=0)
        return 0;
    else
        return 2500;
}
string Clients::generer_code()
{
    time_t temps_prev;
    temps_prev=mktime(&date_prevue);
    string code;
    srand(time(NULL));
    code=rand()%26+65;
    code_id+=code;
    code_id+=num_plaque;
    num_place=this->occuper_place(type_vehicule);
    code_id+=num_place;

    strftime(format2,128,"%A %d %B %Y %H:%M:%S %Z", &date_prevue);
    strftime(format1,128,"%A %d %B %Y %H:%M:%S %Z", &date_depart);
    string code_num,code_nom,code_prenom;
    code_num=code_id+"Num";
    code_nom=code_id+"Nom";
    code_prenom=code_id+"Prenom";
    Table_time.insert(make_pair(code_id.c_str(),temps_prev));
    Table_code.insert(make_pair(code_nom.c_str(),nom.c_str()));
    Table_code.insert(make_pair(code_prenom.c_str(),prenom.c_str()));
    Table_code.insert(make_pair(code_num.c_str(),num_place.c_str()));
    Table_code.insert(make_pair(code_id.c_str(),num_plaque.c_str()));
    Table_heure.insert(make_pair(code_id.c_str(),format1));
    Table_heure.insert(make_pair(code_id.c_str(),format2));
    return code_id;
}
