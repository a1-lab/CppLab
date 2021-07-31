#include "../header/MainFrame.hpp"
#include "../BlueBall.XPM"
#include "wx/msgdlg.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
/*OnAbout handler is bound dynamically*/
/*Connect(wxID_ABOUT,....*/
/**///EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
/**/EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) :
	wxFrame(nullptr, wxID_ANY, title)
{
	SetProcessDPIAware();
	SetIcon(wxIcon(main_icon_xpm));

	auto fileMenu = new wxMenu();
	fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"),
		wxT("Quit Application"));

	auto helpMenu = new wxMenu();
	helpMenu->Append(wxID_ABOUT, wxT("&About\tF1"),
		wxT("About"));

	auto menuBar = new wxMenuBar(wxMB_DOCKABLE);
	menuBar->Append(fileMenu, wxT("&File"));
	menuBar->Append(helpMenu, wxT("&Help"));
	SetMenuBar(menuBar);
	SetBackgroundColour(*wxRED);
	/*It is also possible to bind handler dynamically*/
	Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(MainFrame::OnAbout));

	Centre();
}

//do not apply sonar rule S995. wx specific code
void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close();
}

//do not apply sonar rules S995, S5817. wx specific code
void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(wxT("Simple Hello App"),
		wxT("About Information"));
}