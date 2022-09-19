#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include "Application.h"
#include "Clients.h"


using namespace std;
class Gestionnaire : public Application
{
    public:
        Gestionnaire();
        ~Gestionnaire();

    protected:

    private:
        string code_gest;
};

#endif // GESTIONNAIRE_H
