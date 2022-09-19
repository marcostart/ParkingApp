#ifndef APPLICATION_H
#define APPLICATION_H
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;
class Application
{
    public:
        Application(){};
        ~Application(){};
        string occuper_place(string num);
        void liberer_place(string type,string num,string code);
        void enregistrer_info();
        void recuperer_info();
        bool verifier_code(string code);
        bool verifier_gest(string pseudo,string code);
   // protected:
        static int nbre_place_P;
        static int nbre_place_G;
        static vector <string> Gros_V;
        static vector <string>Petit_V;
        static multimap <string,string> Table_code;
        static multimap <string,string> Table_gest;
};

#endif // APPLICATION_H
