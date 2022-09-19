#include "ecran3.h"
#include "park.h"
#include "Application.h"
#include <wx/dcbuffer.h>
#include <wx/textdlg.h>
#include <wx/numdlg.h>
#include <wx/choicdlg.h>
#include <ctype.h>
#include <cmath>
#include <ctime>
#include <time.h>
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
Ecran3::Ecran3() : wxFrame(NULL,-1,_T("Parking Auto"),wxDefaultPosition,wxSize(718,800)/*, wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN*/), Application()
{
    wxBoxSizer *sizer1=new wxBoxSizer(wxVERTICAL);
    wxPanel *zone_im= new wxPanel(this);
    wxFont font1 = wxFont(12,wxDECORATIVE,wxITALIC,wxBOLD);
    zone_im ->SetFont(font1);
    zone_im ->SetBackgroundColour(wxColour(128,128,255));
    wxBoxSizer *sizer2= new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *sizer3= new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *zone_text1= new wxStaticText(this,wxID_ANY,_T("Votre code d'identification : "));
    code = new wxStaticText(this,wxID_ANY,_T(""));
    zone_text1->SetFont(font1);
    code->SetFont(font1);
    code->SetForegroundColour(*wxBLACK);
    zone_text1->SetForegroundColour(*wxBLACK);
    sizer3->Add(zone_text1,1,wxALL | wxEXPAND,20);
    sizer3->Add(code,1,wxALL | wxEXPAND,20);
    //
    wxBoxSizer *sizerB= new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *zone_textB= new wxStaticText(this,wxID_ANY,_T("Numéro de votre Place :"));
    zone_ctrl3= new wxStaticText(this,wxID_ANY,_T(""));
    sizerB ->Add(zone_textB,1,wxALL | wxEXPAND,20);
    sizerB ->Add(zone_ctrl3,1,wxALL | wxEXPAND,20);
    zone_textB->SetFont(font1);
    zone_ctrl3->SetFont(font1);
    zone_ctrl3->SetForegroundColour(*wxBLACK);
    zone_textB->SetForegroundColour(*wxBLACK);
    //
    wxButton *ouvrir=new wxButton(this, ID_OUV, _T("&Garer votre véhicule"), wxDefaultPosition, wxDefaultSize,0 );
    wxButton *retirer=new wxButton(this, ID_RET1, _T("&Retirer votre véhicule"), wxDefaultPosition, wxDefaultSize,0 );
    wxBoxSizer *sizer7=new wxBoxSizer(wxHORIZONTAL);
    sizer7->Add(ouvrir,1,wxALL | wxALIGN_CENTER,10);
    sizer7->Add(retirer,1,wxALL | wxALIGN_CENTER,10);
    payer=new wxButton(this, ID_RET, _T("&Payer Amende"), wxDefaultPosition, wxDefaultSize,0 );
    wxBoxSizer *sizer4=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *zone_text2= new wxStaticText(this,wxID_ANY,_T("Date d'arrivée"));
    wxBoxSizer *sizerC=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *zone_textC= new wxStaticText(this,wxID_ANY,_T("Date de retrait prévue"));
    //wxStaticText *zone_textD= new wxStaticText(this,wxID_ANY,_T("Statut du conducteur"));
    zone_text2->SetForegroundColour(*wxBLACK);
    zone_text2->SetFont(font1);
    zone_textC->SetForegroundColour(*wxBLACK);
    zone_textC->SetFont(font1);
    ctrl1= new wxStaticText(this,wxID_ANY,_T(""));
    ctrlC= new wxStaticText(this,wxID_ANY,_T(""));
    //zone_textD->SetForegroundColour(*wxBLACK);
    //zone_textD->SetFont(font1);
    //ctrlD= new wxStaticText(this,wxID_ANY,_T(""));
    sizer4->Add(zone_text2,1,wxALL | wxEXPAND,10);
    sizer4->Add(ctrl1,1,wxALL | wxEXPAND,10);
    sizerC->Add(zone_textC,1,wxALL | wxEXPAND,10);
    sizerC->Add(ctrlC,1,wxALL | wxEXPAND,10);
    //sizerD->Add(zone_textD,1,wxALL | wxEXPAND,10);
    //sizerD->Add(ctrlD,1,wxALL | wxEXPAND,10);
    ctrl1->SetForegroundColour(*wxBLACK);
    ctrl1->SetFont(font1);
    ctrlC->SetForegroundColour(*wxBLACK);
    ctrlC->SetFont(font1);
    //ctrlD->SetForegroundColour(*wxBLACK);
    //ctrlD->SetFont(font1);
    //Boutons et code
    sizer2->Add(sizer7,1 ,wxALL | wxEXPAND, 0);
    sizer2->Add(sizer3,1 ,wxALL | wxEXPAND, 0);
    sizer2->Add(sizerB,1 ,wxALL | wxEXPAND, 0);

    sizer2->Add(new wxStaticLine(zone_im,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxLI_HORIZONTAL),1,wxALL | wxEXPAND,0);
    //Retrait
    sizer2->Add(sizer4,1 ,wxALL | wxEXPAND, 0);
    sizer2->Add(sizerC,1 ,wxALL | wxEXPAND, 0);
    //sizer2->Add(sizerD,1 ,wxALL | wxEXPAND, 0);
    wxBoxSizer *sizer5=new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *zone_text3= new wxStaticText(this,wxID_ANY,_T("Amende"));
    zone_text3->SetForegroundColour(*wxBLACK);
    zone_text3->SetFont(font1);
    ctrl2= new wxTextCtrl(this,ID_TEXT21,_T(""));
    sizer5->Add(zone_text3,1,wxALL | wxEXPAND,10);
    sizer5->Add(ctrl2,1,wxALL | wxEXPAND,10);
    sizer2->Add(sizer5,1 ,wxALL | wxEXPAND, 0);
    ctrl2->Enable(false);
    wxBoxSizer *sizer6=new wxBoxSizer(wxHORIZONTAL);
    wxButton *annuler=new wxButton(this, ID_AN1, _T("&Annuler"), wxDefaultPosition, wxDefaultSize,0 );
    sizer6->Add(payer,1,wxALL | wxALIGN_CENTER,5);
    sizer6->Add(annuler,1,wxALL | wxALIGN_CENTER,5);
    sizer2->Add(sizer6,1 ,wxALL | wxEXPAND, 0);
    payer->Enable(false);
    wxStaticText *zone_text4= new wxStaticText(this,wxID_ANY,_T("MERCI POUR VOTRE CONFIANCE !"));
    zone_text4->SetForegroundColour(*wxBLACK);
    wxFont font2 = wxFont(14,wxDECORATIVE,wxITALIC,wxBOLD);
    zone_text4->SetFont(font2);
    sizer2->Add(zone_text4,1 ,wxALL | wxALIGN_CENTER, 5);
    zone_im->SetSizer(sizer2);
    sizer1->Add(zone_im ,1,wxALL | wxEXPAND,0);
    SetSizer(sizer1);
    ouvrir->Bind(wxEVT_BUTTON,&Ecran3::onClickOuv,this,ID_OUV);
    retirer->Bind(wxEVT_BUTTON,&Ecran3::onClickRet,this,ID_RET1);
    payer->Bind(wxEVT_BUTTON,&Ecran3::onClickPay,this,ID_RET);
    annuler->Bind(wxEVT_BUTTON,&Ecran3::onClickAn,this,ID_AN1);
}
void Ecran3::onClickAn(wxCommandEvent &event)
{
    Ecran1 *retour=new Ecran1();
    this->Show(false);
    retour->Show(true);
    Destroy();
}
void Ecran3::onClickRet(wxCommandEvent &event)
{
    payer->Enable(true);

    codage=this->recuperer_info();
    multimap <string,string>::iterator im;
    map <string,time_t>::iterator im2;
    int t=0;
    string heure1,heure2;
    for (im=Table_heure.begin();im!=Table_heure.end();im++)
    {
        if (im->first==codage)
        {
            t++;
            if (t==1)
            {
                heure1=im->second;
            }
            else
                heure2=im->second;
        }
    }
    wxString text;
    text.Printf("%s",heure1);
    ctrl1->SetLabel(text);
    text.Printf("%s",heure2);
    ctrlC->SetLabel(text);
    im2=Table_time.find(codage);
    time_t date_prev, date_actu;
    if (im2!=Table_time.end())
    {
        date_prev=im2->second;
        time(&date_actu);
        if (difftime(date_actu,date_prev)<=0)
            amende=0;
        else
            amende=2500;
    }
    else
        std::cout << "erreure au niveau du temps" << '\n';
    text.Printf("%d",amende);
    ctrl2->SetValue(text);
}
void Ecran3::onClickPay(wxCommandEvent &event)
{
    wxMessageBox(wxString::Format(_T("Payement effectué avec succès\nPrésentez votre code ID ou ce message de confirmation au gestionnaire pour vérification")),_T("Retrait validé"),wxOK |wxCENTRE |wxICON_INFORMATION,this);
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
    //this->enregistrer_info("");
}
void Ecran3::onClickOuv(wxCommandEvent &event)
{
    codage=this->recuperer_info();
    multimap <string,string>::iterator im;
    //int t=0;
    string code_num;
    code_num=codage+"Num";
    for (im=Table_code.begin();im!=Table_code.end();im++)
    {
      if (im->first==code_num)
      {
          num=im->second;
      }
    }
    wxString text;
    text.Printf("%s",codage);
    code->SetLabel(text);
    text.Printf("%s",num );
    zone_ctrl3->SetLabel(text);
}
Ecran3::~Ecran3()
{
    this->enregistrer_info("");
}
