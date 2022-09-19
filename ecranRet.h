#ifndef ECRANRET_H
#define ECRANRET_H

#include "park.h"
#include "Application.h"
#include <wx/textdlg.h>
#include <wx/numdlg.h>
#include <wx/choicdlg.h>
#include <ctype.h>
#include <cmath>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/frame.h>
#endif

#include <wx/app.h>
class Ecran4 : public wxFrame, public Application
{
    public:
        Ecran4();
        ~Ecran4();
    private:
        int prix;
        string codage,num;
        wxTextCtrl *nom;
        wxTextCtrl *prenom;
        wxTextCtrl *telephone;
        wxTextCtrl *code;
        wxStaticText *temps, *tempsB;
        wxTextCtrl *amende;
        wxButton *payer;
        void onClickVer(wxCommandEvent &event);
        void onClickPay(wxCommandEvent &event);
        void onClickAn(wxCommandEvent &event);
};
enum
{
    ID_T1=1,
    ID_T2,
    ID_T3,
    ID_T4,
    ID_VER,
    ID_PAYE,
    ID_ANN
};

#endif
