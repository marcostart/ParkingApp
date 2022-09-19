#include "Application.h"
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <time.h>
#include "Clients.h"

using namespace std;
int Application::nbre_place_P=0;
int Application::nbre_place_G=0;
vector <string> Application::Gros_V;//push_back(2);
vector <string> Application::Petit_V;//.push_back(2);
multimap <string,string> Application::Table_code;//.insert(make_pair('0','0'));
multimap <string,string> Application::Table_heure;
map <string,time_t> Application::Table_time;
void Application::enregistrer_info(string code)
 {
     ofstream monFichier1("./Fichier/GrosV.dat",ios::out);
     ofstream monFichier2("./Fichier/PetitV.dat",ios::out);
     ofstream monFichier3("./Fichier/code.dat",ios::out);
     ofstream monFichier4("./Fichier/heure.dat",ios::out);
     ofstream monFichier5("./Fichier/time.dat",ios::out);
     if(!monFichier1 || !monFichier2 || !monFichier3 || !monFichier4 || !monFichier5)
     {
         cout<<"erreure ouverture fichier"<<endl;
         exit(EXIT_FAILURE);
     }
     int cpt=1, q=0,cptb=1;
     monFichier1<<nbre_place_G<<"\n";
     string gv="";
     gv+= nbre_place_G;
     if (gv.size()==2)
        cpt=2;
     else if (gv.size()==3)
        cpt=3;
     for (int i=0;i<Gros_V.size();i++)
     {
         for (q=0;q<cpt;q++)
         {
             monFichier1<<Gros_V[i];
             i++;
         }
         i--;
         if( i!=Gros_V.size()-1)
                monFichier1<<"\n";
     }
     monFichier2<<nbre_place_P<<"\n";
     string pv;
     pv+=nbre_place_P;
     if (pv.size()==2)
        cptb=2;
     else if (pv.size()==3)
        cptb=3;
     for (int i=0;i<Petit_V.size();i++)
     {
         for (q=0;q<cptb;q++)
         {
             monFichier2<<Petit_V[i];
             i++;
         }
         i--;
         if( i!=Petit_V.size()-1)
                monFichier2<<"\n";
     }

     multimap <string,string>::iterator im;
     map <string,time_t>::iterator im2;
     monFichier3<<code<<'*';
     for (im=Table_code.begin();im!=Table_code.end();im++)
     {
         monFichier3<<(*im).first<<" "<<(*im).second<<"|";
     }
     for (im=Table_heure.begin();im!=Table_heure.end();im++)
     {
         monFichier4<<(*im).first<<"|"<<(*im).second<<"|";
     }
     for (im2=Table_time.begin();im2!=Table_time.end();im2++)
     {
         monFichier5<<(*im2).first<<" "<<(*im2).second<<" ";
     }
 }
string Application::recuperer_info()
{
    int i=0;
    string code;
    ifstream monFichier1("./Fichier/GrosV.dat",ios::in);
    ifstream monFichier2("./Fichier/PetitV.dat",ios::in);
    ifstream monFichier3("./Fichier/code.dat",ios::in);
    ifstream monFichier4("./Fichier/heure.dat",ios::in);
    ifstream monFichier5("./Fichier/time.dat",ios::in);
     if(!monFichier1 || !monFichier2 || !monFichier3 || !monFichier4 || !monFichier5)
     {
         cout<<"erreure ouverture fichier"<<endl;
         exit(EXIT_FAILURE);
     }
     //monFichier1.ignore();
    Gros_V.clear();
     Petit_V.clear();
     Table_code.erase(Table_code.begin(),Table_code.end());
     Table_heure.erase(Table_heure.begin(),Table_heure.end());
     Table_time.erase(Table_time.begin(),Table_time.end());
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
            Gros_V.push_back(word);
            i++;
            word="";
        }
        else if (t>0)
        {

            word+=car;
        }
        t++;

     }
     if (word.size()!=0)
        Gros_V.push_back(word);
    //cout <<"grands "<<word<<endl;
     monFichier1.clear();
     monFichier2.seekg(0,ios::beg);
     monFichier2>>nbre_place_P;
     t=0;
     i=0;
     word="";
    while (monFichier2.get(car))
     {
        if ((isspace(car)) &&(t>0))
        {
            Petit_V.push_back(word);
            i++;
            word="";
        }
        else if (t>0)
        {
            word+=car;
        }
        t++;

     }
     if (word.size()!=0)
        Petit_V.push_back(word);
     //cout <<"petits "<<word<<endl;
     monFichier2.clear();
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

             if(t==0)
             {
                first=word;
                word="";
                t++;
             }
         }
         else if (car=='|')
         {
             second=word;
             t=0;
             Table_code.insert(make_pair(first,second));
             word="";
         }
         else if (car=='*')
         {
             code =word;
             word="";
         }
         else
         {
             word+=car;
         }
     }
     monFichier3.clear();
     monFichier4.seekg(0,ios::beg);
     t=0;
     i=0;
     int k=0;
     word="";
     while(monFichier4.get(car))
     {
         if (car=='|')
         {
             if(t==0)
             {
                first=word;
                word="";
                t++;
             }
             else
             {
                 second=word;
                 Table_heure.insert(make_pair(first,second));
                 word="";
                 t=0;
             }
         }
         else
         {
             word+=car;
         }
         k++;
     }
     monFichier4.clear();
     monFichier5.seekg(0,ios::beg);
     time_t date;
     t=0;
     while (!monFichier5.eof())
     {
         t++;
         if (t%2!=0)
         {
             monFichier5>>first;
         }
         else
         {
             monFichier5>>date;
             Table_time.insert(make_pair(first,date));
         }
     }
     monFichier5.clear();
     return code;
}
 string Application::occuper_place(string num)
 {
     string var;
     if(num=="1")
     {

         var=Gros_V[Gros_V.size()-1];
         Gros_V.pop_back();
         nbre_place_G--;
         return var;
     }

      else
      {
         var=Petit_V[Petit_V.size()-1];
         Petit_V.pop_back();
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
      enregistrer_info("");
 }
