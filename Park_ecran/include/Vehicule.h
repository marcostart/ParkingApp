#ifndef VEHICULE_H
#define VEHICULE_H
#include <string>

using namespace std;
class Vehicule
{
    public:
        Vehicule(string plaque, string type, double duree);
        ~Vehicule();
        void generer_prix();

   // protected:
        string num_plaque;
        string type_vehicule;
        int prix_place;
        double duree;
    private:
};

#endif // VEHICULE_H
