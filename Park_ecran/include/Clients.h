#ifndef CLIENTS_H
#define CLIENTS_H
#include <string>
#include <cstring>
#include "Application.h"
#include "Vehicule.h"
#include <ctime>


using namespace std;
class Clients : public Application, public Vehicule
{
    public:
        Clients(string nom,string prenom,double telephone,string num_plaque,double duree,string type);
        ~Clients();
        void lancer_chrono();
        void verifier_chrono();
        void generer_code();
        bool affiche_date();
        double generer_amende(double duree);
   // protected:
        string nom;
        string prenom;
        double telephone;
        string code_id;
        //string num_plaque;
        string num_place;
        //double duree;
        struct tm date_prevue;
        struct tm date_arriv;
        bool ponct;

};

#endif // CLIENTS_H
