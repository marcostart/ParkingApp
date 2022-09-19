
#ifndef ECRAN2_H
#define ECRAN2_H

#ifndef PTOTOTY_H_INCLUDED
#define PTOTOTY_H_INCLUDED
#ifndef PROTOTYPAGE_H_INCLUDED
#define PROTOTYPAGE_H_INCLUDED
#include "ecran3.h"
#include "Clients.h"
#include <wx/textdlg.h>
#include <wx/numdlg.h>
#include <wx/choicdlg.h>
#include <ctype.h>
#include <cmath>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/msgdlg.h>
#include <wx/frame.h>
#endif

#include <wx/app.h>


class Ecran2 : public wxFrame, public Application
{
    public:
        Ecran2();
    private:
        wxTextCtrl *zone_ctrl2, *zone_ctrl ,*text1, *text2, *text3, *text4, *text5, *nbrePlace, *zone_ctrlB;
        wxRadioBox *radio;
        wxButton *valButton;
        Clients *client1;
        void onClickPrix(wxCommandEvent &event);
        void onClickVald(wxCommandEvent &event);
        void onClickAn(wxCommandEvent &event);

};


enum
{
    ID_TEXT1=1,
    ID_TEXT2,
    ID_TEXTB,
    ID_TEXT3,
    ID_TEXT4,
    ID_TEXT5,
    ID_TEXT6,
    ID_TEXT7,
    ID_VAL,
    ID_AN,
    ID_PRIX
};
#endif
#endif
#endif
