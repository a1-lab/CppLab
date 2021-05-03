#include "wx/artprov.h"
#include "Application.hpp"
#include "MainFrame.hpp"
#include "Strings.h"
#include "Ids.h"

wxMenu* createFileMenu();

MainFrame::MainFrame(wxDocManager* manager,
	const wxSize& size) : wxDocParentFrame(manager, nullptr,
		wxID_ANY, MAIN_FRAME_TITLE, wxDefaultPosition, size,
		wxDEFAULT_FRAME_STYLE, wxFrameNameStr)

{
	SetMinSize(wxSize(800, 600));

	m_auiManager.SetManagedWindow(this);
	m_toolbarArt = new wxAuiDefaultToolBarArt();

	//CreateMainToolbar();
	//CreateToolbarSizeAndScale();
	m_auiManager.Update();

	CreateMainMenu();
	//ShowFullScreen(true, wxFULLSCREEN_NOCAPTION);
}

MainFrame::~MainFrame()
{
	m_auiManager.UnInit();
	wxDELETE(m_toolbarArt);
}

void MainFrame::CreateMainMenu()
{
	Application& app = wxGetApp();

	auto fileMenu = createFileMenu();
	/*auto viewMenu = new wxMenu();
	auto editMenu = new wxMenu();
	auto effectsMenu = new wxMenu();
	auto configurationMenu = new wxMenu();
	auto helpMenu = new wxMenu();*/

	auto menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, app.getText(MENU_SECTION,
		MENU_FILE_KEY, MENU_FILE_DEF_VALUE));

	/*	menuBar->Append(viewMenu, MENU_VIEW_TITLE);
	menuBar->Append(editMenu, MENU_EDIT_TITLE);
	menuBar->Append(effectsMenu, MENU_EFFECTS_TITLE);
	menuBar->Append(configurationMenu, MENU_CONFIGURATION_TITLE);
	menuBar->Append(helpMenu, MENU_HELP_TITLE);*/

	/*
	helpMenu->Append(wxID_ABOUT, wxT("&About\tF1"),
		wxT("About"));
	*/
	SetMenuBar(menuBar);
}

void MainFrame::CreateMainToolbar()
{
	auto toolbar = new wxAuiToolBar(this, wxID_ANY,
		wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | //wxAUI_TB_OVERFLOW |
		wxAUI_TB_TEXT
	);


	toolbar->SetToolBitmapSize(FromDIP(wxSize(16, 16)));

	toolbar->SetArtProvider(m_toolbarArt);
	wxBitmap tb4_bmp1 = wxArtProvider::GetBitmap(wxART_NORMAL_FILE,
		wxART_OTHER, FromDIP(wxSize(16, 16)));

	toolbar->AddTool(ID_NEW, tb4_bmp1, wxNullBitmap,
		false, nullptr, wxT("Новый проект"), wxT("Создать новый проект"));

	toolbar->SetToolSticky(ID_NEW, true);
	toolbar->AddTool(ID_OPEN, "", tb4_bmp1);
	toolbar->SetToolSticky(ID_OPEN, true);
	toolbar->AddTool(ID_SAVE, "Сохранить", tb4_bmp1);
	toolbar->AddSeparator();
	toolbar->AddTool(ID_POINTER, "", tb4_bmp1);
	toolbar->SetToolSticky(ID_POINTER, true);
	toolbar->AddTool(ID_ADD, "", tb4_bmp1);
	toolbar->SetToolSticky(ID_ADD, true);
	toolbar->AddTool(ID_DELETE, "", tb4_bmp1);
	toolbar->AddSeparator();
	toolbar->AddTool(ID_EFFECTS, "", tb4_bmp1);
	toolbar->AddTool(ID_PLAY, "", tb4_bmp1);
	toolbar->AddTool(ID_WRITE_PROGRAM, "", tb4_bmp1);

	toolbar->SetToolDropDown(ID_OPEN, true);
	toolbar->SetToolDropDown(ID_SAVE, true);

	//toolbar->SetCustomOverflowItems(prepend_items, append_items);
	//m_toolbarArt->SetFlags(wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
	toolbar->SetToolBitmapSize(FromDIP(wxSize(24, 24)));

	toolbar->ClearTools();
	toolbar->Realize();

	m_auiManager.AddPane(toolbar, wxAuiPaneInfo().
		Name("MainToolbar").Caption("Главная панель инструментов").
		ToolbarPane().Top().Row(1));

}

void MainFrame::CreateToolbarSizeAndScale()
{
}
