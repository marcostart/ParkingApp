#ifndef PARK_H
#define PARK_H
#include "ecran2.h"
#include "ecran3.h"
#include "ecranRet.h"
#include <wx/textdlg.h>
#include <wx/numdlg.h>
#include <wx/choicdlg.h>
#include <ctype.h>
#include <cmath>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/frame.h>
	#include <wx/bitmap.h>
	#include <wx/event.h>
#else
	#include <wx/wxprec.h>
#endif
#include <wx/app.h>
//#include <wx/aui/aui.h>
class MyApp : public wxApp
{
    public:
	    virtual bool OnInit();
};
DECLARE_APP(MyApp) ;
class wxBackground : public wxEvtHandler
{
    typedef wxEvtHandler Inherited;
    public :
        wxBackground(const wxBitmap &B,wxWindow *target) : wxEvtHandler(), Bitmap(B), window(target)
        {
            window->PushEventHandler(this);
        }
        virtual bool ProcessEvent(wxEvent &event);
        virtual ~wxBackground()
        {
            /*if(window && GetEvtHandlerEnabled())
            {*/
                window->RemoveEventHandler(this);
                window->Unlink();
           // }
            //SetEvtHandlerEnabled(false);
        }
        //void Stop();
    protected :
        //wxAuiManager manager;
        wxBitmap Bitmap;
        wxWindow *window;

};
class Ecran1 : public wxFrame
{
    public:

        wxPanel *zone_im;
        wxBackground *image;
        Ecran1();
        virtual ~Ecran1();
    private:
        void onClickRes(wxCommandEvent &event);
        void onClickRet(wxCommandEvent &event);
        void onClickGest(wxCommandEvent &event);
        void onExit(wxCommandEvent &event);

     //   DECLARE_EVENT_TABLE();
};
enum
{
    ID_EXIT=1,
    ID_RES,
    ID_GEST,
    ID_RET
};
#endif
