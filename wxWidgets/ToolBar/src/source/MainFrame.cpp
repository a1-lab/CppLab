#include "../header/MainFrame.hpp"
#include "../header/MainToolBar.h"
#include "../BlueBall.XPM"
#include "wx/msgdlg.h"
#include "wx/toolbar.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
/**/EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
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

	auto menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));
	menuBar->Append(helpMenu, wxT("&Help"));
	SetMenuBar(menuBar);
	CreateMainToolBar();
	Centre();
}

//do not apply sonar rule S995. wx specific code
void MainFrame::OnQuit(wxCommandEvent& event)
{
	Close();
}

//do not apply sonar rules S995, S5817. wx specific code
void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(wxT("wxWidgets Layout learning application"),
		wxT("About"));
}

void MainFrame::CreateMainToolBar()
{
	auto toolbar = CreateToolBar();
	toolbar->AddTool(wxID_EXIT, wxT("Exit application"), exit);
	toolbar->Realize();
	//auto sizer = new wxBoxSizer(wxHORIZONTAL);
	//toolbar->SetSizerAndFit(sizer);
	auto menu = new wxMenu;
	menu->Append(wxID_ANY, "&First dummy item");
	menu->Append(wxID_ANY, "&Second dummy item");
	menu->AppendSeparator();
	menu->Append(wxID_EXIT, "Exit");
	//toolbar->SetDropdownMenu(wxID_NEW, menu);
}