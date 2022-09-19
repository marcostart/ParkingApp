#include "ecranGest.h"
#include "park.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <time.h>
#include <wx/dcbuffer.h>
#include <wx/textdlg.h>
#include <wx/numdlg.h>
#include <wx/choicdlg.h>
#include <ctype.h>
#include <cmath>
#include <wx/statline.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/frame.h>
	#include <wx/bitmap.h>
	#include <wx/event.h>
#else
	#include <wx/wxprec.h>
#endif
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
Ecran5::Ecran5() : wxFrame(NULL,-1,_T("Interface Gestionnaire"),wxDefaultPosition,wxSize(718,800)/*, wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN*/), Application()
{
    wxBoxSizer *sizer1=new wxBoxSizer(wxVERTICAL);
    wxPanel *zone_im= new wxPanel(this);
    wxFont font1 = wxFont(12,wxDECORATIVE,wxITALIC,wxBOLD);
    zone_im ->SetFont(font1);
    zone_im ->SetBackgroundColour(wxColour(128,128,255));
    wxBoxSizer *sizer2= new wxBoxSizer(wxVERTICAL);
    //
    wxBoxSizer *sizer3=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *text1= new wxStaticText(this,wxID_ANY,_T("Code de gestionnaire"));
    sizer3 ->Add(text1,1,wxALL | wxEXPAND,5);
    text1->SetForegroundColour(wxColour(*wxBLACK));
    text1 ->SetFont(font1);
    codeG =new wxTextCtrl(this,ID_CODG,_T(""));
    sizer3->Add(codeG,1,wxALL | wxEXPAND,5);
    wxButton *verifier=new wxButton(this,ID_VER1,_T("&Se connecter..."),wxDefaultPosition, wxDefaultSize,0 );
    //
    wxStaticText *text2= new wxStaticText(this,wxID_ANY,_T("Authentifier un véhicule"));
    text2->SetForegroundColour(wxColour(*wxBLACK));
    text2 ->SetFont(font1);
    //
    wxBoxSizer *sizer4=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *text3= new wxStaticText(this,wxID_ANY,_T("Code id du véhicule"));
    sizer4 ->Add(text3,1,wxALL | wxEXPAND,5);
    text3->SetForegroundColour(wxColour(*wxBLACK));
    text3 ->SetFont(font1);
    codeV =new wxTextCtrl(this,ID_CODV,_T(""));
    sizer4->Add(codeV,1,wxALL | wxEXPAND,5);
    codeV->Enable(false);
    authentifier=new wxButton(this,ID_AUT,_T("&Authentifier"),wxDefaultPosition, wxDefaultSize,0 );
    authentifier->Enable(false);
    //
    wxBoxSizer *sizer5=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *text4= new wxStaticText(this,wxID_ANY,_T("Début du stationnement"));
    sizer5 ->Add(text4,1,wxALL | wxEXPAND,5);
    text4->SetForegroundColour(wxColour(*wxBLACK));
    text4 ->SetFont(font1);
    debut= new wxStaticText(this,wxID_ANY,_T(";;;;;;"));
    sizer5 ->Add(debut,1,wxALL | wxEXPAND,5);
    debut->SetForegroundColour(wxColour(*wxBLACK));
    debut ->SetFont(font1);
    //
    wxBoxSizer *sizer6=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *text5= new wxStaticText(this,wxID_ANY,_T("Fin du stationnement"));
    sizer6 ->Add(text5,1,wxALL | wxEXPAND,5);
    text5->SetForegroundColour(wxColour(*wxBLACK));
    text5 ->SetFont(font1);
    fin= new wxStaticText(this,wxID_ANY,_T(";;;;;;"));
    sizer6 ->Add(fin,1,wxALL | wxEXPAND,5);
    fin->SetForegroundColour(wxColour(*wxBLACK));
    fin->SetFont(font1);
    //
    wxBoxSizer *sizer7=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *text6= new wxStaticText(this,wxID_ANY,_T("Amende du véhicule"));
    sizer7->Add(text6,1,wxALL | wxEXPAND,5);
    text6->SetForegroundColour(wxColour(*wxBLACK));
    text6->SetFont(font1);
    amende= new wxTextCtrl(this,ID_AM,_T(""));
    sizer7 ->Add(amende,1,wxALL | wxEXPAND,5);
    amende->Enable(false);
    wxButton *annuler=new wxButton(this,ID_QUIT,_T("&Annuler"),wxDefaultPosition, wxDefaultSize,0 );
    //
    sizer2->Add(sizer3,1,wxALL | wxEXPAND,0);
    sizer2->Add(verifier,1,wxALL | wxALIGN_RIGHT,5);
    sizer2->Add(new wxStaticLine(zone_im,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxLI_HORIZONTAL),1,wxALL | wxEXPAND,0);
    sizer2->Add(text2,1,wxALL | wxALIGN_CENTER,5);
    sizer2->Add(sizer4,1,wxALL | wxEXPAND,0);
    sizer2->Add(authentifier,1,wxALL | wxALIGN_RIGHT,5);
    sizer2->Add(sizer5,1,wxALL | wxEXPAND,0);
    sizer2->Add(sizer6,1,wxALL | wxEXPAND,0);
    sizer2->Add(sizer7,1,wxALL | wxEXPAND,0);
    sizer2->Add(annuler,1,wxALL | wxALIGN_RIGHT,5);
    zone_im->SetSizer(sizer2);
    sizer1->Add(zone_im ,1,wxALL | wxEXPAND,0);
    SetSizer(sizer1);
    verifier->Bind(wxEVT_BUTTON,&Ecran5::onClickVer,this,ID_VER1);
    authentifier->Bind(wxEVT_BUTTON,&Ecran5::onClickAut,this,ID_AUT);
    annuler->Bind(wxEVT_BUTTON,&Ecran5::onClickAn,this,ID_QUIT);
}

void Ecran5::onClickVer(wxCommandEvent &event)
{
	ifstream monFichierG("/home/marcolin/Documents/Mon_Projet/wx_widget/parking_auto/Fichier/gest.dat",ios::in);
	wxString tmp1;
	string code_enter="";
    bool ret;
    ret= wxFrame::Validate();
    tmp1=codeG->GetValue();
    if (ret)
    {
        if (tmp1.IsEmpty())
        {
            wxMessageBox(wxString::Format("Veuillez remplir correctement tous les champs"),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            ret=false;
        }
		else
		{
			code_enter=tmp1.ToStdString();
			string mot;
			int t=0;
			if(!monFichierG)
			{
				cout<<"erreure ouverture fichier"<<endl;
	            exit(EXIT_FAILURE);
			}
			ret=false;
			while (!monFichierG.eof())
			{
				monFichierG>>mot;
				if (mot==code_enter)
				{
					ret=true;
					gest_c=mot;
					t++;
				}

			}
			if (t==0)
				wxMessageBox(wxString::Format("Le mot de passe de ce gestionnaire n'existe pas !"),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
		}
        if (ret /*&& ...*/)
        {

            codeV->Enable(true);
            authentifier->Enable(true);
        }
   }
}
void Ecran5::onClickAut(wxCommandEvent &event)
{
    wxString tmp1;
    bool ret;
    ret= wxFrame::Validate();
    tmp1=codeV->GetValue();
    if (ret)
    {
        if (tmp1.IsEmpty())
        {
            wxMessageBox(wxString::Format("Veuillez remplir correctement le champs !"),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            ret=false;
        }
        if (ret /*&& ...*/)
        {
			int t=0, prix;
            this->recuperer_info();
			multimap <string,string>::iterator im;
			code_user=tmp1.ToStdString();
            for (im=Table_code.begin();im!=Table_code.end();im++)
            {
                if (im->first==code_user)
                    t++;
            }
            if (t==0)
                wxMessageBox(wxString::Format(_T("Ce code d'identification n'existe pas\nVeuiller réessayer !")),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            else
            {
				string heure1,heure2;
				t=0;
				for (im=Table_heure.begin();im!=Table_heure.end();im++)
				{
					if (im->first==code_user)
					{
						t++;
						if (t==1)
						{
							heure1=im->second;
						}
						else if (t==2)
						{
							heure2=im->second;
						}
					}
				}
				map <string,time_t>::iterator im2;
				im2=Table_time.find(code_user);
				time_t date_prev, date_actu;
				if (im2!=Table_time.end())
				{
					date_prev=im2->second;
					time(&date_actu);
					if (difftime(date_actu,date_prev)<=0)
						prix=0;
					else
						prix=2500;
				}
				else
					std::cout << "erreure au niveau du temps" << '\n';
				wxString text;
				text.Printf("%s",heure1);
				debut->SetLabel(text);
				text.Printf("%s",heure2);
				fin->SetLabel(text);
				text.Printf("%d",prix);
				amende->SetValue(text);
				Table_code.erase(code_user);
				Table_code.erase(code_user+"Nom");
				Table_code.erase(code_user+"Prenom");
				Table_code.erase(code_user+"Num");
				Table_time.erase(code_user);
				Table_heure.erase(code_user);
				this->enregistrer_info("");
			}
        }
    }

}
void Ecran5::onClickAn(wxCommandEvent &event)
{
    Ecran1 *retour=new Ecran1();
    this->Show(false);
    retour->Show(true);
    Destroy();
}
