#include "ecran2.h"
#include "ecran3.h"
#include "park.h"
#include "Clients.h"
#include "Application.h"
#include <wx/msgdlg.h>
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
#include <cstring>
#endif
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

using namespace std;
Ecran2::Ecran2() : wxFrame(NULL,-1,_T("Réservation"),wxDefaultPosition,wxSize(718,800)/*, wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN*/), Application()
{
    client1->recuperer_info();
    wxBoxSizer *sizer1=new wxBoxSizer(wxVERTICAL);
    wxPanel *zone_im= new wxPanel(this);
    wxFont font1 = wxFont(12,wxDECORATIVE,wxITALIC,wxBOLD);
    //zone_im ->SetBackgroundColour(wxTheColourDatabase->Find("White"));
    zone_im ->SetFont(font1);
    wxBoxSizer *sizer2= new wxBoxSizer(wxVERTICAL);
    wxStaticText *zone_text1= new wxStaticText(this,wxID_ANY,_T("IDENTIFICATION"));
    wxBoxSizer *sizer3= new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *sizerB= new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *zone_text2= new wxStaticText(this,wxID_ANY,_T("Places diponibles \"gros vehicules\""));
    wxStaticText *zone_textB= new wxStaticText(this,wxID_ANY,_T("Places diponibles \"petits vehicules\""));
    zone_text1 ->SetFont(font1);
    zone_text2 ->SetFont(font1);
    zone_textB ->SetFont(font1);
    zone_ctrl=new wxTextCtrl(this, ID_TEXT1,_T(""));
    zone_ctrlB=new wxTextCtrl(this, ID_TEXTB,_T(""));
    wxString text;
    text.Printf("%d",Application::nbre_place_G);
    zone_ctrl->SetValue(text);
    text.Printf("%d",Application::nbre_place_P);
    zone_ctrlB->SetValue(text);
    sizer3 ->Add(zone_text2,1,wxALL | wxEXPAND,5);
    sizer3->Add(zone_ctrl,1,wxALL | wxEXPAND,5);
    zone_ctrl->Enable(false);
    sizerB ->Add(zone_textB,1,wxALL | wxEXPAND,5);
    sizerB->Add(zone_ctrlB,1,wxALL | wxEXPAND,5);
    zone_ctrlB->Enable(false);
    sizer2 ->Add(zone_text1,1,wxALL| wxALIGN_CENTER,5);
    sizer2->Add(sizer3,1,wxALL | wxEXPAND,0);
    sizer2->Add(sizerB,1,wxALL | wxEXPAND,0);
    /*Champs à remplir*/
    wxStaticBoxSizer *static_sizer=new wxStaticBoxSizer(wxVERTICAL,zone_im,_T("Informations client"));
    wxBoxSizer *sizer4= new wxBoxSizer(wxHORIZONTAL);
    sizer4 ->Add(new wxStaticText(this,wxID_ANY,_T("Nom")),1,wxALL | wxEXPAND,5);
    text1=new wxTextCtrl(this,ID_TEXT2,_T(""));
    sizer4 ->Add(text1,1,wxALL | wxEXPAND,5);
    wxBoxSizer *sizer5= new wxBoxSizer(wxHORIZONTAL);
    sizer5 ->Add(new wxStaticText(this,wxID_ANY,_T("Prénom")),1,wxALL | wxEXPAND,5);
    text2=new wxTextCtrl(this,ID_TEXT3,_T(""));
    sizer5 ->Add(text2,1,wxALL | wxEXPAND,5);
    wxBoxSizer *sizer6= new wxBoxSizer(wxHORIZONTAL);
    sizer6 ->Add(new wxStaticText(this,wxID_ANY,_T("Téléphone")),1,wxALL | wxEXPAND,5);
    text3=new wxTextCtrl(this,ID_TEXT4,_T(""));
    sizer6 ->Add(text3,1,wxALL | wxEXPAND,5);
    wxBoxSizer *sizer7= new wxBoxSizer(wxHORIZONTAL);
    sizer7 ->Add(new wxStaticText(this,wxID_ANY,_T("Plaque d'immatriculation")),1,wxALL | wxEXPAND,5);
    text4=new wxTextCtrl(this,ID_TEXT5,_T(""));
    sizer7 ->Add(text4,1,wxALL | wxEXPAND,5);
    wxBoxSizer *sizer8= new wxBoxSizer(wxHORIZONTAL);
    sizer8 ->Add(new wxStaticText(this,wxID_ANY,_T("Durée de stationnement(en heure)")),1,wxALL | wxEXPAND,5);
    text5=new wxTextCtrl(this,ID_TEXT6,_T(""));
    sizer8 ->Add(text5,1,wxALL | wxEXPAND,5);
    static_sizer ->Add(sizer4,1,wxALL | wxEXPAND,0);
    static_sizer ->Add(sizer5,1,wxALL | wxEXPAND,0);
    static_sizer ->Add(sizer6,1,wxALL | wxEXPAND,0);
    static_sizer ->Add(sizer7,1,wxALL | wxEXPAND,0);
    static_sizer ->Add(sizer8,1,wxALL | wxEXPAND,0);
    static_sizer->GetStaticBox()->SetFont(font1);
    sizer2->Add(static_sizer,1,wxALL | wxEXPAND,0);
    wxArrayString choix;
    choix.Add(_T("Limousine/Pick-up/\"mini\"Bus/fourgonnette"));
    choix.Add(_T("Berline/SUV/Véhicule coupé"));

    /*Bouton radio et prix*/
    wxBoxSizer *sizer10= new wxBoxSizer(wxHORIZONTAL);
    wxButton *prixButton= new wxButton(zone_im,ID_PRIX,_("&Prix"),wxDefaultPosition,wxSize(20,20),0);
    radio = new wxRadioBox(this,-1,_("Type de véhicule (Faites un choix)"),wxDefaultPosition,wxDefaultSize,choix,1);
    sizer10 ->Add(radio,1,wxALL | wxEXPAND,40);
    sizer10 ->Add(prixButton,1,wxALL | wxEXPAND,10);
    sizer2->Add(sizer10,1,wxALL | wxEXPAND,0);

    sizer2->Add(new wxStaticLine(zone_im,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxLI_HORIZONTAL),1,wxALL | wxEXPAND,0);
    wxBoxSizer *sizer9= new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *sizer11= new wxBoxSizer(wxHORIZONTAL);
    zone_ctrl2= new wxTextCtrl(this,ID_TEXT6,_T(""));
    sizer9 ->Add(new wxStaticText(this,wxID_ANY,_T("Prix de stationnement :")),1,wxALL | wxEXPAND,5);
    sizer9 ->Add(zone_ctrl2,1,wxALL | wxEXPAND,5);
    //
    zone_ctrl2 -> Enable(false);
    valButton= new wxButton(zone_im,ID_VAL,_("&Valider le payement"),wxDefaultPosition,wxDefaultSize,0);
    wxButton *annuler=new wxButton(zone_im,ID_AN,_T("Annuler"),wxDefaultPosition,wxDefaultSize,0);
    wxBoxSizer *sizer12= new wxBoxSizer(wxHORIZONTAL);
    sizer12->Add(valButton,1,wxALL | wxALIGN_CENTER,20);
    sizer12->Add(annuler,1,wxALL | wxALIGN_CENTER,10);
    sizer2->Add(sizer9,1,wxALL | wxEXPAND,0);
    sizer2->Add(sizer11,1,wxALL | wxEXPAND,0);
    sizer2->Add(sizer12,1,wxALL | wxEXPAND,0);
    //////////////
    valButton->Enable(false);
    ///////////////
    zone_im->SetSizer(sizer2);
    sizer1->Add(zone_im ,1,wxALL | wxEXPAND,0);
    SetSizer(sizer1);
    prixButton->Bind(wxEVT_BUTTON,&Ecran2::onClickPrix,this,ID_PRIX);
    valButton->Bind(wxEVT_BUTTON,&Ecran2::onClickVald,this,ID_VAL);
    annuler->Bind(wxEVT_BUTTON,&Ecran2::onClickAn,this,ID_AN);
}

void Ecran2::onClickPrix(wxCommandEvent &event)
{
    wxString tmp1,tmp2,tmp3,tmp4,tmp5,var;
    int tmp6,tmp7;
    var.Printf(".");
        tmp1=text1->GetValue();
        tmp2=text2->GetValue();
        tmp3=text3->GetValue();
        tmp4=text4->GetValue();
        tmp5=text5->GetValue();
        tmp6=wxAtoi(zone_ctrl->GetValue());
        tmp7=wxAtoi(zone_ctrlB->GetValue());
    bool ret;
    ret= wxFrame::Validate();
    if (tmp6==0 && tmp7==0)
    {
        wxMessageBox(wxString::Format("Plus aucune place disponible sur le parking actuellement\n""Essayez ailleur"),_T("Désolé !"),wxOK |wxCENTRE |wxICON_INFORMATION,this);
        ret=false;
    }
    if (ret)
    {
        if (tmp1.IsEmpty() || tmp2.IsEmpty() || tmp3.IsEmpty() || tmp4.IsEmpty() || tmp5.IsEmpty())
        {
            wxMessageBox(wxString::Format("Veuillez remplir tous les champs !"),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            ret=false;
        }
        unsigned long int m=0,t1=0,t2=0,t3=0,t4=0;

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
        int q=0;
        for (m=0;m<tmp5.size();m++)
        {
            if (tmp5[m]==var)
                q++;
            if ((!isdigit(tmp5[m]) && tmp5[m]!=var) || q>1 )
                t4++;
        }
        if (t1>0 || t2>0)
        {
            wxMessageBox(wxString::Format(_T("Le nom et le prénom ne doivent pas contenir de chiffres")),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            ret=false;
        }
        if (t3>0)
        {
            wxMessageBox(wxString::Format(_T("Le numéro de téléphone ne doit pas contenir de caractère")),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            ret=false;
        }
        if (t4>0)
        {
            wxMessageBox(wxString::Format(_T("Saisissez une durée en chiffre (en heure)")),_T("ERREURE !"),wxOK |wxCENTRE |wxICON_ERROR,this);
            ret=false;
        }
    }
    wxString choix1=_T("Limousine/Pick-up/\"mini\"Bus/fourgonnette"), choix2=_T("Berline/SUV/Véhicule coupé"), text="";
    if ((radio->GetStringSelection()==choix1 && tmp6==0 &&tmp7!=0) || (radio->GetStringSelection()==choix2 && tmp6!=0 && tmp7==0))
    {
        wxMessageBox(wxString::Format("Plus aucune place disponible sur le parking pour ce type de vehicule\n""Essayez ailleur"),_T("Désolé !"),wxOK |wxCENTRE |wxICON_INFORMATION,this);
        ret=false;
    }

    if (ret)
    {
        valButton->Enable(true);

        string typeV="";
        if (radio->GetStringSelection()==choix1)
            text.Printf("1");
        else
            text.Printf("0");
        client1=new Clients(tmp1.ToStdString(),tmp2.ToStdString(),wxAtof(tmp3),tmp4.ToStdString(),wxAtof(tmp5),text.ToStdString());
        text.Printf("%d",client1->generer_prix());
        zone_ctrl2->SetValue(text);
    }
}
void Ecran2::onClickVald(wxCommandEvent &event)
{
    client1->lancer_chrono();
    client1->generer_code();
    client1->enregistrer_info(client1->code_id);
    wxMessageBox(wxString::Format(_T("Réservation effectuée avec succès.\nVous êtes autorisés à garer votre véhicule avec votre code d'identification")),_T("Réservation confirmée"),wxOK |wxCENTRE |wxICON_INFORMATION,this);
    Ecran3 *validation =new Ecran3();
    this->Show(false);
    validation->Show(true);
    Destroy();
}
void Ecran2::onClickAn(wxCommandEvent &event)
{
    Ecran1 *retour = new Ecran1();
    this->Show(false);
    retour->Show(true);
    Destroy();
}
