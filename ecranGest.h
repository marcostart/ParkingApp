#ifndef ECRANGEST_H
#define ECRANGEST_H

#include "park.h"
#include "Gestionnaire.h"
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
class Ecran5 : public wxFrame, public Application
{
    public:
        Ecran5();
    private:
        string gest_c, code_user;
        wxTextCtrl *codeG;
        wxTextCtrl *codeV;
        wxStaticText *debut, *fin;
        wxTextCtrl *amende;
        wxButton *authentifier;
        void onClickVer(wxCommandEvent &event);
        void onClickAut(wxCommandEvent &event);
        void onClickAn(wxCommandEvent &event);
};
enum
{
    ID_CODG=1,
    ID_VER1,
    ID_CODV,
    ID_QUIT,
    ID_AM,
    ID_AUT
};

#endif
