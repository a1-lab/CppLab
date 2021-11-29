#include "../header/MainFrame.hpp"
#include "BurningWidget.hpp"
#include "../BlueBall.XPM"
#include "wx/msgdlg.h"
#include "../wxmemdbg.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
/*OnAbout handler is bound dynamically*/
/*Connect(wxID_ABOUT,....*/
/**///EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
/**/EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
/**/EVT_MENU(wxID_BUTTON1, MainFrame::OnButton1)
END_EVENT_TABLE()

int ID_SLIDER = 1;

MainFrame::MainFrame(const wxString& title) :
	wxFrame(nullptr, wxID_ANY, title)
{
	SetProcessDPIAware();
	SetIcon(wxIcon(main_icon_xpm));

	CreateMenuBar();
	//CreateMainToolBar();

	/*It is also possible to bind handler dynamically*/
	Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(MainFrame::OnAbout));

	//AddBurningWidget();
	//AddDesignerPrototype();
	AddScrollWindow();

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

void MainFrame::OnButton1(wxCommandEvent&)
{
	m_desiner->SetSize(844, 600);
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
	//m_wid->Refresh();
}

void MainFrame::CreateMenuBar()
{
	auto fileMenu = new wxMenu();
	fileMenu->Append(wxID_BUTTON1, wxT("Increase size"),
		wxT("Increase size"));

	auto helpMenu = new wxMenu();
	helpMenu->Append(wxID_ABOUT, wxT("&About\tF1"),
		wxT("About"));

	auto menuBar = new wxMenuBar(wxMB_DOCKABLE);
	menuBar->Append(fileMenu, wxT("&File"));
	menuBar->Append(helpMenu, wxT("&Help"));
	SetMenuBar(menuBar);
}

void MainFrame::CreateMainToolBar()
{
	auto toolBar = CreateToolBar();

	toolBar->AddTool(wxID_BUTTON1, wxT("Increase size"),
		wxNullBitmap, wxNullBitmap, wxITEM_DROPDOWN,
		wxT("New file"), wxT("This is help for new file tool"));

	SetToolBar(toolBar);
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

//	m_wid = new BurningWidget(panel, wxID_ANY);
//	hbox->Add(m_wid, 1, wxEXPAND);

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
	wxScrolledWindow* scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, 
		wxSize(400, 350), wxSUNKEN_BORDER);
	// Set up virtual window dimensions. It will be 1000x1000
    // and will scroll 10 pixels at a time
	//int pixelsPerUnixX = 10;
	//int pixelsPerUnixY = 10;
	//int noUnitsX = 1000;
	//int noUnitsY = 1000;
	//scrolledWindow->SetScrollbars(pixelsPerUnixX, pixelsPerUnixY, noUnitsX, noUnitsY);

	//auto frameSizer = new wxBoxSizer(wxVERTICAL);
	//frameSizer->Add(scrolledWindow, 1, wxGROW | wxALL, 0);

	//auto centerSizer = new wxBoxSizer(wxVERTICAL);

	//m_desiner = new vgl::DesignerScrolled(this);
	//centerSizer->Add(m_desiner, 1, wxGROW | wxALL, 0);
	//SetSizerAndFit(frameSizer);
}

void MainFrame::AddScrollWindow()
{
	//m_scrolledCanvas = new wxScrolledCanvas(this, wxID_ANY, wxPoint(0, 0), wxSize(400, 300),
	//	wxVSCROLL | wxHSCROLL);

	//m_scrolledCanvas = new wxScrolledCanvas(this, wxNewId(), wxDefaultPosition, wxDefaultSize, wxVSCROLL);
	//m_scrolledCanvas = new wxScrolledCanvas(this, wxID_ANY);
	//m_scrolledCanvas->SetMinSize(wxSize(-1, 200));
	//m_scrolledCanvas->SetScrollRate(10, 10);
	// Set up virtual window dimensions. It will be 1000x1000
	// and will scroll 10 pixels at a time
	int pixelsPerUnitX = 10;
	int pixelsPerUnitY = 10;
	int noUnitsX = 800;
	int noUnitsY = 600;
	//m_scrolledCanvas->SetScrollbars(pixelsPerUnitX, pixelsPerUnitY, noUnitsX, noUnitsY);

	auto frameSizer = new wxBoxSizer(wxVERTICAL);
	//frameSizer->Add(m_scrolledCanvas, 1, wxGROW | wxALL, 0);
	
	m_desiner = new vgl::DesignerScrolled(this, frameSizer);

	SetSizerAndFit(frameSizer);
}
