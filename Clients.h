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
        string generer_code();
        bool affiche_date();
        double generer_amende(double duree);
        string code_id;
    protected:
        string nom;
        string prenom;
        double telephone;

        string num_place;
        char format1[128];
        char format2[128];
        struct tm date_prevue;
        struct tm date_arriv;
        struct tm date_depart;
        bool ponct;

};

#endif // CLIENTS_H
