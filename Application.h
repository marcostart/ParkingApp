#ifndef APPLICATION_H
#define APPLICATION_H
#include <vector>
#include <map>
#include <string>
#include <cstring>
//#include "Clients.h"

using namespace std;
class Application
{
    public:
        Application(){};
        ~Application(){};
        string occuper_place(string num);
        void liberer_place(string type,string num,string code);
        void enregistrer_info(string code);
        string recuperer_info();
    protected:
        static int nbre_place_P;
        static int nbre_place_G;
        static vector <string> Gros_V;
        static vector <string>Petit_V;
        static multimap <string,string> Table_code;
        static map <string,time_t> Table_time;
        static multimap <string,string> Table_heure;
        static multimap <string,string> Table_gest;
};

#endif // APPLICATION_H
