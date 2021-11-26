#include "../header/MainFrame.hpp"
#include "BurningWidget.hpp"
#include "DesignerPrototype.hpp"
#include "../BlueBall.XPM"
#include "wx/msgdlg.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
/*OnAbout handler is bound dynamically*/
/*Connect(wxID_ABOUT,....*/
/**///EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
/**/EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
END_EVENT_TABLE()

int ID_SLIDER = 1;

MainFrame::MainFrame(const wxString& title) :
	wxFrame(nullptr, wxID_ANY, title)
{
	SetProcessDPIAware();
	SetIcon(wxIcon(main_icon_xpm));

	CreateMenuBar();

	/*It is also possible to bind handler dynamically*/
	Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(MainFrame::OnAbout));

	//AddBurningWidget();
	AddDesignerPrototype();

	Centre();
}

int MainFrame::GetCurWidth()
{
	return cur_width;
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

void MainFrame::OnScroll(wxScrollEvent& event)
{
	cur_width = m_slider->GetValue();
	m_wid->Refresh();
}

void MainFrame::CreateMenuBar()
{
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
}

void MainFrame::AddBurningWidget()
{
	cur_width = 75;

	auto panel = new wxPanel(this, wxID_ANY);
	auto centerPanel = new wxPanel(panel, wxID_ANY);

	m_slider = new wxSlider(centerPanel, ID_SLIDER, 75, 0, 750, wxPoint(-1, -1),
		wxSize(150, -1), wxSL_LABELS);

	auto vbox = new wxBoxSizer(wxVERTICAL);
	auto hbox = new wxBoxSizer(wxHORIZONTAL);
	auto hbox2 = new wxBoxSizer(wxHORIZONTAL);
	auto hbox3 = new wxBoxSizer(wxHORIZONTAL);

	m_wid = new BurningWidget(panel, wxID_ANY);
	hbox->Add(m_wid, 1, wxEXPAND);

	hbox2->Add(centerPanel, 1, wxEXPAND);
	hbox3->Add(m_slider, 0, wxTOP | wxLEFT, 35);

	centerPanel->SetSizer(hbox3);

	vbox->Add(hbox2, 1, wxEXPAND);
	vbox->Add(hbox, 0, wxEXPAND);

	panel->SetSizer(vbox);
	m_slider->SetFocus();

	Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED,
		wxScrollEventHandler(MainFrame::OnScroll));

}

void MainFrame::AddDesignerPrototype()
{
	auto frameSizer = new wxBoxSizer(wxVERTICAL);
	auto centerSizer = new wxBoxSizer(wxVERTICAL);
	frameSizer->Add(centerSizer, 1, wxGROW | wxALL, 5);

	auto desiner = new DesignerPrototype(this);
	centerSizer->Add(desiner, 1, wxGROW | wxALL, 0);

	SetSizerAndFit(frameSizer);
}
