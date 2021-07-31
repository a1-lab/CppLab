#include "wx/msgdlg.h"
#include "wx/artprov.h"

#include "../header/MainFrame.hpp"
#include "../header/Ids.h"
#include "../BlueBall.XPM"
#include "../header/customization/CustomAuiDockArt.hpp"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
/**/EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
/**/EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) :
	wxFrame(nullptr, wxID_ANY, title,
		wxDefaultPosition, wxSize(800, 600))
{
	SetProcessDPIAware();
	SetIcon(wxIcon(main_icon_xpm));
	SetMinSize(wxSize(800, 600));
	m_mgr.SetManagedWindow(this);
	m_mgr.SetArtProvider(new CustomAuiDockArt());

	CreateMainToolbar();
	//CreateToolbarSizeAndScale();
	CreateSeveralPanes();
	m_mgr.Update();

	CreateMainMenu();
	CentreOnScreen();
}

//do not apply sonar rule S995. wx specific code
void MainFrame::OnQuit(wxCommandEvent& event)
{
	Close();
}

//do not apply sonar rules S995, S5817. wx specific code
void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(wxT("Advanced user interface learning application"),
		wxT("About"));
}

void MainFrame::CreateMainMenu()
{
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
}

void MainFrame::CreateMainToolbar()
{
	wxAuiToolBar* toolbar = new wxAuiToolBar(this, wxID_ANY,
		wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW |
		wxAUI_TB_TEXT | wxAUI_TB_HORZ_TEXT | wxAUI_TB_PLAIN_BACKGROUND);

	toolbar->SetToolBitmapSize(FromDIP(wxSize(16, 16)));
	wxBitmap tb4_bmp1 = wxArtProvider::GetBitmap(wxART_NORMAL_FILE,
		wxART_OTHER, FromDIP(wxSize(16, 17)));

	wxBitmap tb4_bmp2 = wxArtProvider::GetBitmap(wxART_NORMAL_FILE,
		wxART_OTHER, FromDIP(wxSize(16, 16)));

	toolbar->AddTool(ID_NEW, tb4_bmp1, wxNullBitmap,
		false, nullptr, wxT("Новый проект"), wxT("Создать новый проект"));

	toolbar->SetToolSticky(ID_NEW, true);
	toolbar->AddTool(ID_OPEN, "", tb4_bmp1);
	toolbar->SetToolSticky(ID_OPEN, true);
	toolbar->AddTool(ID_SAVE, "", tb4_bmp1);
	toolbar->AddSeparator();
	toolbar->AddTool(ID_POINTER, "", tb4_bmp2);
	toolbar->SetToolSticky(ID_POINTER, true);
	toolbar->AddTool(ID_ADD, "Добавить", tb4_bmp2);
	toolbar->SetToolSticky(ID_ADD, true);
	toolbar->AddTool(ID_DELETE, "", tb4_bmp1);
	toolbar->AddSeparator();
	toolbar->AddTool(ID_EFFECTS, "Эффекты", tb4_bmp2);
	toolbar->AddTool(ID_PLAY, "", tb4_bmp2);
	toolbar->AddTool(ID_WRITE_PROGRAM, "Записать", tb4_bmp2);

	toolbar->SetToolDropDown(ID_OPEN, true);
	toolbar->SetToolDropDown(ID_SAVE, true);

	toolbar->SetCustomOverflowItems(prepend_items, append_items);
	toolbar->Realize();

	m_mgr.AddPane(toolbar, wxAuiPaneInfo().
		Name("MainToolbar").Caption("Главная панель инструментов").
		ToolbarPane().Top().Row(1));
}

void MainFrame::CreateToolbarSizeAndScale()
{
	wxAuiToolBar* toolbar = new wxAuiToolBar(this, wxID_ANY,
		wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW |
		wxAUI_TB_TEXT | wxAUI_TB_HORZ_TEXT);

	wxChoice* choice = new wxChoice(toolbar, ID_SCALE);
	choice->AppendString("One choice");
	choice->AppendString("Another choice");
	toolbar->AddControl(choice);

	m_mgr.AddPane(toolbar, wxAuiPaneInfo().
		Name("SizeAndScale").Caption("Размеры и масштаб").
		ToolbarPane().Top().Row(1));
}

void MainFrame::CreateSeveralPanes()
{
	// create several text controls
	wxTextCtrl* text1 = new wxTextCtrl(this, -1, _("Pane 1 - sample text"),
		wxDefaultPosition, wxSize(200, 150),
		wxNO_BORDER | wxTE_MULTILINE);

	wxTextCtrl* text2 = new wxTextCtrl(this, -1, _("Pane 2 - sample text"),
		wxDefaultPosition, wxSize(200, 150),
		wxNO_BORDER | wxTE_MULTILINE);

	wxTextCtrl* text21 = new wxTextCtrl(this, -1, _("Pane 21 - sample text"),
		wxDefaultPosition, wxSize(200, 150),
		wxNO_BORDER | wxTE_MULTILINE);

	wxTextCtrl* text3 = new wxTextCtrl(this, -1, _("Main content window"),
		wxDefaultPosition, wxSize(200, 150),
		wxNO_BORDER | wxTE_MULTILINE);


	// add the panes to the manager
	m_mgr.AddPane(text1, wxLEFT, wxT("Pane Number One"));
	m_mgr.AddPane(text21, wxLEFT, wxT("Pane Number Two 1"));
	m_mgr.AddPane(text2, wxBOTTOM, wxT("Pane Number Two"));
	m_mgr.AddPane(text3, wxCENTER);

}
