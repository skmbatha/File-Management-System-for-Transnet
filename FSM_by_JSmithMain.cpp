/***************************************************************
 * Name:      FSM_by_JSmithMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    SK MBATHA (skatlego.mbatha@gmail.com)
 * Created:   2020-12-26
 * Copyright: SK MBATHA ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "FSM_by_JSmithMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


FSM_by_JSmithFrame::FSM_by_JSmithFrame(wxFrame *frame)
    : GUIFrame(frame)
{
    timerObj= new wxTimer(this,wxID_TIMER1);///Initialize timer 1

    statusBar->SetStatusText(_("Welcome to FMS"), 0);
    statusBar->SetStatusText(_(""), 1);


	this->Connect( wxID_kOPEN, wxEVT_BUTTON, wxCommandEventHandler( FSM_by_JSmithFrame::OnOpen) );
	this->Connect( wxID_kNEW, wxEVT_BUTTON, wxCommandEventHandler( FSM_by_JSmithFrame::OnNew) );
	this->Connect( wxID_kEXIT, wxEVT_BUTTON, wxCloseEventHandler( FSM_by_JSmithFrame::OnClose) );
	this->Connect( wxID_TIMER1, wxEVT_TIMER, wxTimerEventHandler( FSM_by_JSmithFrame::OnTimerEvent) );
	myAppPtr=this;

}

FSM_by_JSmithFrame::~FSM_by_JSmithFrame()
{
}

void FSM_by_JSmithFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void FSM_by_JSmithFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void FSM_by_JSmithFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = _("This Software was developed by Katlego Mbatha...a final year at Stellenbosch university. The purspose of this application is to help manage every kind file but currently only focuses on TRANSNET specific spreadsheets.");
    wxMessageBox(msg, _("About Developer"));
}

void FSM_by_JSmithFrame::OnOpen(wxCommandEvent& event)
{
 system("start Repository");
 statusBar->SetStatusText(_("Welcome to FMS."), 0);
}

void FSM_by_JSmithFrame::OnNew(wxCommandEvent& event)
{

    ///Open dialog
    GUIDialog *MyDialog = new GUIDialog(myAppPtr,timerObj,wxID_ANY,wxT("Create a new spreadsheet"),wxDefaultPosition,wxSize(500,300),wxDEFAULT_DIALOG_STYLE);
    MyDialog->Show();

    ///Start the timer
    //timerObj->Start(500);///count/inc every 1 second

}

void FSM_by_JSmithFrame::OnTimerEvent(wxTimerEvent& event)
{
    static int counter=0,counter2=0;
    counter++;

    switch(counter)
    {
       case 1:statusBar->SetStatusText(_("Please wait!"), 0);
        break;
       case 2:statusBar->SetStatusText(_("Please wait!"), 0);
        break;
       case 3:statusBar->SetStatusText(_("Opening file on MS Excel."), 0);
        break;
       case 4:statusBar->SetStatusText(_("Opening file on MS Excel.."), 0);
        break;
       case 5:statusBar->SetStatusText(_("Opening file on MS Excel..."), 0);
        break;

    }

    if(counter==5)
    {
        counter=0;
        counter2++;
    }

    if(counter2==10)///SHOW THE LOADING SCREEN FOR 10 ROUNDS
    {
        timerObj->Stop();
        counter=0;
        counter2=0;
        statusBar->SetStatusText(_("Select an option!"), 0);
    }

}



