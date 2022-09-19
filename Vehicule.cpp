#include "Vehicule.h"

#include <string>

using namespace std;
Vehicule::Vehicule(string plaque, string type,double duree): num_plaque(plaque),type_vehicule(type), duree(duree)
{

}

Vehicule::~Vehicule()
{
    //dtor
}
int Vehicule::generer_prix()
{
    if (type_vehicule=="1" && duree<12)
        prix_place=2000;
    else if (type_vehicule=="1" && duree<24)
        prix_place=3000;
    else if (type_vehicule=="1" && duree>24)
        prix_place=5000;
    else if (type_vehicule=="0" && duree<12)
        prix_place=1000;
    else if (type_vehicule=="0" && duree<24)
        prix_place=2000;
    else if (type_vehicule=="0" && duree>24)
        prix_place=3000;
    return prix_place;
}
