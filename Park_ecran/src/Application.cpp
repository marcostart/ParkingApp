#include "Application.h"
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int Application::nbre_place_P=0;
int Application::nbre_place_G=0;
vector <string> Application::Gros_V;//push_back(2);
vector <string> Application::Petit_V;//.push_back(2);
multimap <string,string> Application::Table_code;//.insert(make_pair('0','0'));
void Application::enregistrer_info()
 {
     ofstream monFichier1("C:/Programmation/Mon_Projet/Gui_wx/Park_ecran/src/Fichier/GrosV.dat",ios::out);
     ofstream monFichier2("C:/Programmation/Mon_Projet/Gui_wx/Park_ecran/src/Fichier/PetitV.dat",ios::out);
     ofstream monFichier3("C:/Programmation/Mon_Projet/Gui_wx/Park_ecran/src/Fichier/code.dat",ios::out);
     if(!monFichier1 || !monFichier2 || !monFichier3)
     {
         cout<<"erreure ouverture fichier"<<endl;
         exit(EXIT_FAILURE);
     }
     monFichier1<<nbre_place_G<<"\n";
     for (int i=0;i<Gros_V.size();i++)
     {
         monFichier1<<Gros_V[i];
         if( i!=Gros_V.size()-1)
            monFichier1<<"\n";
     }
     monFichier2<<nbre_place_P<<"\n";
     for (int i=0;i<Petit_V.size();i++)
     {
          monFichier2<<Petit_V[i];
          if( i!=Petit_V.size()-1)
            monFichier2<<"\n";
     }

     multimap <string,string>::iterator im;
     for (im=Table_code.begin();im!=Table_code.end();im++)
     {
         monFichier3<<(*im).first<<" "<<(*im).second;
         if (im!= --Table_code.end())
            monFichier3<<"\n";
     }

 }
void Application::recuperer_info()
{
    int i=0, taille=0,actu=0;
    ifstream monFichier1("C:/Programmation/Mon_Projet/Gui_wx/Park_ecran/src/Fichier/GrosV.dat",ios::in);
    ifstream monFichier2("C:/Programmation/Mon_Projet/Gui_wx/Park_ecran/src/Fichier/PetitV.dat",ios::in);
    ifstream monFichier3("C:/Programmation/Mon_Projet/Gui_wx/Park_ecran/src/Fichier/code.dat",ios::in);
     if(!monFichier1 || !monFichier2 || !monFichier3)
     {
         cout<<"erreure ouverture fichier"<<endl;
         exit(EXIT_FAILURE);
     }
     //monFichier1.ignore();
     monFichier1.seekg(0,ios::beg);
     monFichier1>>nbre_place_G;
     char car;
     string word;
     int t=0;
     i=0;
     while (monFichier1.get(car))
     {
        if ((isspace(car)) &&(t>0))
        {
            cout<<"un caractere entre espace et saut de ligne "<<car<<endl;
            Gros_V.push_back(word);
            cout<<Gros_V[i]<<endl;
            i++;
            word="";
        }
        else if (t>0)
        {
            cout<<"un caractere "<<car<<endl;
            word+=car;
        }
        t++;

     }
    Gros_V.push_back(word);
    cout<<Gros_V[i]<<endl;
    monFichier1.clear();
     cout <<"salaud"<<endl;
     monFichier2.seekg(0,ios::beg);
     monFichier2>>nbre_place_P;
     t=0;
     i=0;
     word="";
    while (monFichier2.get(car))
     {
        if ((isspace(car)) &&(t>0))
        {
            cout<<"un caractere entre espace et saut de ligne "<<car<<endl;
            Petit_V.push_back(word);
            cout<<Petit_V[i]<<endl;
            i++;
            word="";
        }
        else if (t>0)
        {
            cout<<"un caractere "<<car<<endl;
            word+=car;
        }
        t++;

     }
     Petit_V.push_back(word);
     cout<<Petit_V[i]<<endl;
     multimap <string,string>::iterator im;

     Table_code.erase(Table_code.begin(),Table_code.end());
     monFichier3.seekg(0,ios::beg);
     string first, second;
     t=0;
     i=0;
     word="";
     while(monFichier3.get(car))
     {
         if (isspace(car))
         {
             cout<<"un caractere entre espace "<<car<<endl;
             if(t==0)
             {
                first=word;
                word="";
                t++;
             }

             else
             {
                 second=word;
                 t=0;
                 Table_code.insert(make_pair(first,second));
                 word="";
             }
         }
         else
         {
             word+=car;
         }
     }
     second=word;
     Table_code.insert(make_pair(first,second));
}
 string Application::occuper_place(string num)
 {
     string var;
     if(num=="1")
     {
         cout<<"c'est a dire : "<<Gros_V[Gros_V.size()-1]<<endl;
         var=Gros_V[Gros_V.size()-1];
         cout<<"on a retranche "<<var<<endl;
         cout<<"c'est a dire : "<<Gros_V[Gros_V.size()-1]<<endl;
         Gros_V.pop_back();
         nbre_place_G--;
         return var;
     }

      else
      {
         var=Petit_V[Petit_V.size()-1];
         Petit_V.pop_back();
         cout<<"on a retranche "<<var<<endl;
         nbre_place_P--;
         return var;
      }
 }
 void Application::liberer_place(string type,string num,string code)
 {
    if(type=="1")
     {
         Gros_V.push_back(num);
         nbre_place_G++;
     }

      else
      {
         Petit_V.push_back(num);
         nbre_place_P++;
      }
      Table_code.erase(code.c_str());
 }
 bool Application::verifier_code(string code)
 {
     multimap <string,string>::iterator im;
     int t=0;
     for (im=Table_code.begin();im!=Table_code.end();im++)
     {
         if (im->first==code)
         {
             t++;
             if(t==1 && im->second!=nom)
                return false;
             else if (t==2 && im->second!=prenom)
                return
         }
     }
 }
 bool Application::verifier_gest(string pseudo,string code)
 {
     string ligne;
     ifstream monFichier("C:/Programmation/Mon_Projet/Gui_wx/Park_ecran/src/Fichier/Gestionnaire.dat",ios::in);
     monFichier.seekg(0,ios::beg);
     while (getline(monFichier,ligne))
     {
         if(ligne==code)
         {
             return true;
         }
     }
     return false;
 }
