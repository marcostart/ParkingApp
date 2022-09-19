#include "park.h"
#include "Application.h"
#include "ecranRet.h"
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
#endif
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
Ecran4::Ecran4() : wxFrame(NULL,-1,_T("Retrait du véhicule"),wxDefaultPosition,wxSize(718,800)/*, wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN*/), Application()
{
    wxBoxSizer *sizer1=new wxBoxSizer(wxVERTICAL);
    wxPanel *zone_im= new wxPanel(this);
    wxFont font1 = wxFont(12,wxDECORATIVE,wxITALIC,wxBOLD);
    zone_im ->SetFont(font1);
    zone_im ->SetBackgroundColour(wxColour(128,128,255));
    wxBoxSizer *sizer2= new wxBoxSizer(wxVERTICAL);

    wxStaticBoxSizer *sizerStatic= new wxStaticBoxSizer(wxVERTICAL,zone_im,_T("Identifiez-vous !"));
    sizerStatic->GetStaticBox()->SetBackgroundColour(wxTheColourDatabase->Find("White"));
    sizerStatic->GetStaticBox()->SetForegroundColour(wxTheColourDatabase->Find("Black"));
    wxFont font2 = wxFont(14,wxDECORATIVE,wxITALIC,wxBOLD);
    sizerStatic->GetStaticBox()->SetFont(font2);
    wxBoxSizer *sizerBox=new wxBoxSizer(wxVERTICAL);
    //
    wxBoxSizer *sizer3=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *text1= new wxStaticText(this,wxID_ANY,_T("Nom"));
    sizer3 ->Add(text1,1,wxALL | wxEXPAND,5);
    text1->SetForegroundColour(wxColour(*wxBLACK));
    text1 ->SetFont(font1);
    nom =new wxTextCtrl(this,ID_T1,_T(""));
    sizer3->Add(nom,1,wxALL | wxEXPAND,5);
    //
    wxBoxSizer *sizer4=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *text2= new wxStaticText(this,wxID_ANY,_T("Prénom"));
    sizer4 ->Add(text2,1,wxALL | wxEXPAND,5);
    text2->SetForegroundColour(wxColour(*wxBLACK));
    text2 ->SetFont(font1);
    prenom =new wxTextCtrl(this,ID_T2,_T(""));
    sizer4->Add(prenom,1,wxALL | wxEXPAND,5);
    //
    wxBoxSizer *sizer5=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *text3= new wxStaticText(this,wxID_ANY,_T("Téléphone"));
    sizer5 ->Add(text3,1,wxALL | wxEXPAND,5);
    text3->SetForegroundColour(wxColour(*wxBLACK));
    text3 ->SetFont(font1);
    telephone =new wxTextCtrl(this,ID_T3,_T(""));
    sizer5->Add(telephone,1,wxALL | wxEXPAND,5);
    //
    wxBoxSizer *sizer6=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *text4= new wxStaticText(this,wxID_ANY,_T("Code d'identification"));
    sizer6 ->Add(text4,1,wxALL | wxEXPAND,5);
    text4->SetForegroundColour(wxColour(*wxBLACK));
    text4 ->SetFont(font1);
    code =new wxTextCtrl(this,ID_T4,_T(""));
    sizer6->Add(code,1,wxALL | wxEXPAND,5);
    //
    wxButton *verifier=new wxButton(this,ID_VER,_T("&Authentifier"),wxDefaultPosition, wxDefaultSize,0 );
    //
    sizerBox->Add(sizer3,1,wxALL|wxEXPAND,0);
    sizerBox->Add(sizer4,1,wxALL|wxEXPAND,0);
    sizerBox->Add(sizer5,1,wxALL|wxEXPAND,0);
    sizerBox->Add(sizer6,1,wxALL|wxEXPAND,0);
    sizerBox->Add(verifier,1,wxALL | wxALIGN_RIGHT,5);
    sizerStatic->Add(sizerBox,1,wxALL | wxEXPAND,0);
    sizer2->Add(sizerStatic,1 ,wxBOTTOM | wxEXPAND, 5);
    sizer2->Add(new wxStaticLine(zone_im,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxLI_HORIZONTAL),1,wxALL | wxEXPAND,0);
    //
    wxBoxSizer *sizer7=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *zone_text1= new wxStaticText(this,wxID_ANY,_T("Date de d'arrivée :"));
    zone_text1->SetForegroundColour(*wxBLACK);
    zone_text1->SetFont(font1);
    temps= new wxStaticText(this,ID_TEXT,_T(""));
    temps->SetForegroundColour(*wxBLACK);
    temps->SetFont(font1);
    sizer7->Add(zone_text1,1,wxALL | wxEXPAND,10);
    sizer7->Add(temps,1,wxALL ,10);
    sizer2->Add(sizer7,1 ,wxALL | wxEXPAND, 0);
    //=====
    wxBoxSizer *sizerB=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *zone_textB= new wxStaticText(this,wxID_ANY,_T("Date de retrait prévue :"));
    zone_textB->SetForegroundColour(*wxBLACK);
    zone_textB->SetFont(font1);
    tempsB= new wxStaticText(this,ID_TEXT,_T(""));
    tempsB->SetForegroundColour(*wxBLACK);
    tempsB->SetFont(font1);
    sizerB->Add(zone_textB,1,wxALL | wxEXPAND,10);
    sizerB->Add(tempsB,1,wxALL ,10);
    sizer2->Add(sizerB,1 ,wxALL | wxEXPAND, 0);

    //
    wxBoxSizer *sizer9=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *zone_text2= new wxStaticText(this,wxID_ANY,_T("Amende"));
    zone_text2->SetForegroundColour(*wxBLACK);
    zone_text2->SetFont(font1);
    amende= new wxTextCtrl(this,ID_TEXT,_T(""));
    sizer9->Add(zone_text2,1,wxALL | wxEXPAND,10);
    sizer9->Add(amende,1,wxALL,10);
    sizer2->Add(sizer9,1 ,wxALL | wxEXPAND, 0);
    amende->Enable(false);
    //
    wxBoxSizer *sizer8=new wxBoxSizer(wxHORIZONTAL);
    payer=new wxButton(this, ID_PAYE, _T("&Valider payement"), wxDefaultPosition, wxDefaultSize,0 );
    wxButton *annuler=new wxButton(this, ID_ANN, _T("&Annuler"), wxDefaultPosition, wxDefaultSize,0 );
    sizer8->Add(payer,1,wxALL | wxALIGN_CENTER,10);
    sizer8->Add(annuler,1,wxALL | wxALIGN_CENTER,10);
    sizer2->Add(sizer8,1 ,wxALL | wxEXPAND, 0);
    payer->Enable(false);
    //
    zone_im->SetSizer(sizer2);
    sizer1->Add(zone_im ,1,wxALL | wxEXPAND,0);
    SetSizer(sizer1);
    //
    verifier->Bind(wxEVT_BUTTON,&Ecran4::onClickVer,this,ID_VER);
    payer->Bind(wxEVT_BUTTON,&Ecran4::onClickPay,this,ID_PAYE);
    annuler->Bind(wxEVT_BUTTON,&Ecran4::onClickAn,this,ID_ANN);
}

void Ecran4::onClickAn(wxCommandEvent &event)
{
    Ecran1 *retour=new Ecran1();
    this->Show(false);
    retour->Show(true);
    Destroy();
}
void Ecran4::onClickPay(wxCommandEvent &event)
{
    wxMessageBox(wxString::Format(_T("Payement effectué avec succès\nPrésentez votre code ID ou ce message de confirmation au gestionnaire pour vérification")),_T("Retrait validé"),wxOK |wxCENTRE |wxICON_INFORMATION,this);
    this->recuperer_info();
    //
    multimap <string,string>::iterator im;
    string code_num;
    code_num=codage+"Num";
    for (im=Table_code.begin();im!=Table_code.end();im++)
    {
      if (im->first==code_num)
      {
          num=im->second;
      }
    }
    string type;
    if (num.at(num.size()-1)== 'p')
    {
        type="0";
    }
    else
    {
        type="1";
    }
    this->liberer_place(type,num,codage);
}
void Ecran4::onClickVer(wxCommandEvent &event)
{
    wxString tmp1,tmp2,tmp3,tmp4;
        tmp1=nom->GetValue();
        tmp2=prenom->GetValue();
        tmp3=telephone->GetValue();
        tmp4=code->GetValue();

    bool ret;
    ret= wxFrame::Validate();
    if (ret)
    {
        if (tmp1.IsEmpty() || tmp2.IsEmpty() || tmp3.IsEmpty() || tmp4.IsEmpty())
        {
            wxMessageBox(wxString::Format("Veuillez remplir tous les champs !"),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            ret=false;
        }
        unsigned long int m=0,t1=0,t2=0,t3=0;

        for (m=0;m<tmp1.size();m++)
        {
            if (isdigit(tmp1[m]))
                t1++;
        }
        for (m=0;m<tmp2.size();m++)
        {
            if (isdigit(tmp2[m]))
                t2++;
        }
        for (m=0;m<tmp3.size();m++)
        {
            if (!isdigit(tmp3[m]))
                t3++;
        }
        if (t1>0 || t2>0)
        {
            wxMessageBox(wxString::Format(_T("Le nom et le prénom ne doivent pas contenir de chiffres")),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            //wxMessageBox(wxString::Format("Veuiller saisir des entiers dans tous les champs !"),"ERREURE",wxOK | wxICON_ERROR,this);
            ret=false;
        }
        if (t3>0)
        {
            wxMessageBox(wxString::Format(_T("Le numéro de téléphone ne doit pas contenir de caractère")),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            ret=false;
        }
        if (ret)
        {
            string nom,prenom;
            int t=0;
            this->recuperer_info();
            nom=tmp1.ToStdString();
            prenom=tmp2.ToStdString();
            codage =tmp4.ToStdString();
            multimap <string,string>::iterator im, im2;
            for (im=Table_code.begin();im!=Table_code.end();im++)
            {
                if (im->first==codage)
                    t++;
            }
            if (t==0)
                wxMessageBox(wxString::Format(_T("Code d'identification Incorrect\nVeuiller rééssayez")),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            else
            {
                im=Table_code.find(codage+"Nom");
                im2=Table_code.find(codage+"Prenom");
                if (im==Table_code.end() || im->second!=nom || im2==Table_code.end() || im2->second!=prenom )
                {
                    wxMessageBox(wxString::Format(_T("Information d'identification Incorrect\nVeuiller rééssayer")),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
                }
                else
                {
                    map <string,time_t>::iterator im2;
                    this->recuperer_info();
                    payer->Enable(true);
                    im2=Table_time.find(codage);
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
                    string heure1,heure2;
                    t=0;
                    for (im=Table_heure.begin();im!=Table_heure.end();im++)
                    {
                        if (im->first==codage)
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
                    wxString text;
                    text.Printf("%s",heure1);
                    temps->SetLabel(text);
                    text.Printf("%s",heure2);
                    tempsB->SetLabel(text);
                    text.Printf("%d",prix);
                    amende->SetValue(text);
                }
            }

            //Inclure les méthodes pour calculer le prix
        }
    }
}
Ecran4::~Ecran4()
{
    enregistrer_info("");
}
