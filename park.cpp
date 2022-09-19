#include "park.h"
#include "ecran2.h"
#include "ecran3.h"
#include "ecranRet.h"
#include "ecranGest.h"
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
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    Ecran1 *accueil= new Ecran1();
    accueil->Show(true);
    return true;
}
bool wxBackground::ProcessEvent(wxEvent &event)
{
    if (event.GetEventType()==wxEVT_ERASE_BACKGROUND)
    {
        wxEraseEvent &EraseEvent = /*wxDynamicCast(&event,wxEraseEvent)*/ dynamic_cast<wxEraseEvent &>(event);
        wxDC *DC = EraseEvent.GetDC();
        DC->DrawBitmap(Bitmap, 0,0,false);
        return true;
    }
    else
        return Inherited::ProcessEvent(event) ;
    /*if(event.GetEventType() == wxEVT_ERASE_BACKGROUND)
    {
        if(Bitmap.IsOk())
        {
        }
        else
            event.Skip();
    }
    else if(event.GetEventType() == wxEVT_PAINT)
    {
        bool TransactionIsOk = false;
        if(Bitmap.IsOk())
        {
            wxWindow * TempWindow = wxDynamicCast(event.GetEventObject(),wxWindow);
            if(TempWindow)
            {
                wxBufferedPaintDC DC(TempWindow);
                int w, h;
                TempWindow->GetClientSize(&w, &h);
                wxImage TempImage = Bitmap.ConvertToImage();
                TempImage.Rescale(w,h);
                DC.DrawBitmap(wxBitmap(TempImage), 0, 0, false);
                TransactionIsOk = true;
            }
        }
        if(TransactionIsOk == false)
            event.Skip();
    }
    else if(event.GetEventType() ==  wxEVT_SIZE)
    {
        wxWindow * TempWindow = wxDynamicCast(event.GetEventObject(),wxWindow);
        if(TempWindow)
        {
            TempWindow->Refresh();
        }
        event.Skip();
    }
    else
        return Inherited::ProcessEvent(event);
    return true;*/
}
Ecran1::Ecran1() : wxFrame(NULL,-1,_T("Parking Auto"),wxDefaultPosition,wxSize(718,800), wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN |wxRESIZE_BORDER)
{

    wxBoxSizer *sizer1=new wxBoxSizer(wxVERTICAL);
    zone_im= new wxPanel(this);
    /*Arrière plan*/
    wxBitmap TempBitmap;
    TempBitmap.LoadFile("back.jpg",wxBITMAP_TYPE_JPEG);
    image = new wxBackground(TempBitmap,zone_im);
    //zone_im->PushEventHandler(image);
    wxString text1, text2, text3;
    text1.Printf(_T("La solution idéale pour un stationnement simple et securisé"));
    text2.Printf(_T("SERVICE DE PARKING AUTOMOBILE"));
    text3.Printf(_T("Que désirez vous-faire ?"));

    wxStaticText *zoneText1 =new wxStaticText(this,wxID_ANY,text1);
    wxStaticText *zoneText2 =new wxStaticText(this,wxID_ANY,text2,wxDefaultPosition);
    zoneText1->SetForegroundColour(wxTheColourDatabase->Find("Black"));
    zoneText2->SetForegroundColour(wxTheColourDatabase->Find("Black"));
    //zoneText1->SetFont(zoneText1->(GetFont().Scale(2)).SetWeight(wxFONTWEIGHT_BOLD));
    wxFont font = wxFont(14,wxDECORATIVE,wxITALIC,wxBOLD);
    wxFont font1 = wxFont(16,wxDECORATIVE,wxITALIC,wxBOLD);
    zoneText1->SetFont(font);
    zoneText2->SetFont(font1);
    //TExte d'accueil
    wxBoxSizer *sizer2=new wxBoxSizer(wxVERTICAL);
    sizer2->Add(zoneText2,1,wxALL|wxALIGN_CENTER,50);
    sizer2->Add(zoneText1,1, wxALL|wxALIGN_CENTER,5);
    wxStaticBoxSizer *sizerStatic= new wxStaticBoxSizer(wxVERTICAL,zone_im,text3);
    sizerStatic->GetStaticBox()->SetBackgroundColour(wxTheColourDatabase->Find("White"));
    sizerStatic->GetStaticBox()->SetForegroundColour(wxTheColourDatabase->Find("Black"));
    sizerStatic->GetStaticBox()->SetFont(font);
    wxButton* resButton = new wxButton( this, ID_RES, _T("&Réserver une place"), wxDefaultPosition, wxDefaultSize,0 );
    wxButton* retButton = new wxButton (this, ID_RET, _T("&Retirer votre véhicule"), wxDefaultPosition,wxDefaultSize,0);
    wxButton* gestButton = new wxButton( this, ID_GEST, _T("&Je suis un gestionnaire"), wxDefaultPosition, wxDefaultSize,0 );
    wxButton* exitButton = new wxButton( this, ID_EXIT, _T("&Annuler"), wxDefaultPosition, wxDefaultSize,0 );
    wxBoxSizer* sizer3=new wxBoxSizer(wxHORIZONTAL);
    //Bouton à l'acceuil
    sizer3->Add(resButton,1, wxALL|wxALIGN_CENTER,20);
    sizer3->Add(retButton,1, wxALL|wxALIGN_CENTER,20);
    sizerStatic->Add(sizer3,1,wxEXPAND);
    sizerStatic->Add(gestButton,1 ,wxALL|wxALIGN_CENTER,20);
    sizerStatic->Add(exitButton,1 ,wxALL|wxALIGN_CENTER,20);
    sizer2->Add(sizerStatic,1 , wxALL|wxEXPAND ,0);
    zone_im->SetSizer(sizer2);
    sizer1->Add(zone_im ,1,wxALL | wxEXPAND,0);
    SetSizer(sizer1);
    exitButton->Bind(wxEVT_BUTTON, &Ecran1::onExit,this,ID_EXIT);
    resButton->Bind(wxEVT_BUTTON, &Ecran1::onClickRes,this,ID_RES);
    gestButton->Bind(wxEVT_BUTTON, &Ecran1::onClickGest,this,ID_GEST);
    retButton->Bind(wxEVT_BUTTON, &Ecran1::onClickRet,this,ID_RET);

}
Ecran1::~Ecran1()
        {
            delete image;
        }

void Ecran1::onExit(wxCommandEvent& event)
{
    Destroy();
}
void Ecran1::onClickRes(wxCommandEvent& event)
{
    Ecran2 *reservation =new Ecran2();
    this->Show(false);
    reservation->Show(true);
    Destroy();
}
void Ecran1::onClickRet(wxCommandEvent &event)
{
    Ecran4 *retrait= new Ecran4();
    this->Show(false);
    retrait->Show(true);
    Destroy();
}
void Ecran1::onClickGest(wxCommandEvent &event)
{
    Ecran5 *gestion= new Ecran5();
    this->Show(false);
    gestion->Show(true);
    Destroy();
}
