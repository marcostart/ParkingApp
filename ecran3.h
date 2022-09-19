#ifndef ECRAN3_H
#define ECRAN3_H

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
class Ecran3 : public wxFrame, public Application
{
    public:
        Ecran3();
        ~Ecran3();
    private:
        string codage,num;
        int amende;
        wxTextCtrl *ctrl2;
        wxStaticText *code,*ctrl1,*ctrlC , *zone_ctrl3, *ctrlD;
        wxButton *payer;
        void onClickOuv(wxCommandEvent &event);
        void onClickRet(wxCommandEvent &event);
        void onClickPay(wxCommandEvent &event);
        void onClickAn(wxCommandEvent &event);
};
enum
{
    ID_OUV=1,
    ID_RET1,
    ID_PAY,
    ID_TEXT,
    ID_TEXT21,
    ID_AN1
};

#endif
