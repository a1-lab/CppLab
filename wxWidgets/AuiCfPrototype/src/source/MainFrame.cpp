#include "wx/artprov.h"
#include "Application.hpp"
#include "MainFrame.hpp"
#include "Strings.h"
#include "Ids.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
//EVT_MENU(ID_SHOW_TOOLBAR_CAPTIONS, MainFrame::OnToggleToolbarCaptions)
END_EVENT_TABLE()

wxMenu* createFileMenu();
void updateFileMenu(wxMenu* menu);
wxMenu* createViewMenu();
void updateViewMenu(wxMenu* menu);
wxMenu* createEditMenu();
void updateEditMenu(wxMenu* menu);
wxMenu* createEffectsMenu();
void updateEffectsMenu(wxMenu* menu);
wxMenu* createConfigurationMenu();
void updateConfigurationMenu(wxMenu* menu);
wxMenu* createHelpMenu();
void updateHelpMenu(wxMenu* menu);
wxMenu* createWindowMenu();
void updateWindowMenu(wxMenu* menu);


MainFrame::MainFrame(wxDocManager* manager,
	const wxSize& size) : wxDocParentFrame(manager, nullptr,
		wxID_ANY, MAIN_FRAME_TITLE, wxDefaultPosition, size,
		wxDEFAULT_FRAME_STYLE, wxFrameNameStr)

{
	SetMinSize(wxSize(800, 600));

	m_auiManager.SetManagedWindow(this);

	CreateMainToolbar();
	//CreateToolbarSizeAndScale();
	m_auiManager.Update();

	CreateMainMenu();
	CreateStatusBar(1);
	//ShowFullScreen(true, wxFULLSCREEN_NOCAPTION);
}

MainFrame::~MainFrame()
{
	m_auiManager.UnInit();
}

void MainFrame::CreateMainMenu()
{
	const Application& app = wxGetApp();

	auto fileMenu = createFileMenu();
	auto viewMenu = createViewMenu();
	auto editMenu = createEditMenu();
	auto effectsMenu = createEffectsMenu();
	auto configurationMenu = createConfigurationMenu();
	auto helpMenu = createHelpMenu();
	auto windowMenu = createWindowMenu();


	m_menuBar->Append(fileMenu, app.getText(MENU_SECTION,
		MENU_FILE_KEY, MENU_FILE_DEF_VALUE));
	m_menuBar->Append(viewMenu, app.getText(MENU_SECTION,
		MENU_VIEW_KEY, MENU_VIEW_DEF_VALUE));
	m_menuBar->Append(editMenu, app.getText(MENU_SECTION,
		MENU_EDIT_KEY, MENU_EDIT_DEF_VALUE));
	m_menuBar->Append(effectsMenu, app.getText(MENU_SECTION,
		MENU_EFFECTS_KEY, MENU_EFFECTS_DEF_VALUE));
	m_menuBar->Append(configurationMenu, app.getText(MENU_SECTION,
		MENU_CONFIGURATION_KEY, MENU_CONFIGURATION_DEF_VALUE));
	m_menuBar->Append(windowMenu, app.getText(MENU_SECTION,
		MENU_WINDOW_KEY, MENU_WINDOW_DEF_VALUE));
	m_menuBar->Append(helpMenu, app.getText(MENU_SECTION,
		MENU_HELP_KEY, MENU_HELP_DEF_VALUE));

	SetMenuBar(m_menuBar);
}

void MainFrame::UpdateMainMenu()
{
	const Application& app = wxGetApp();

	wxMenu* menu = nullptr;
	m_menuBar->SetMenuLabel(ID_MENU_FILE, app.getText(MENU_SECTION,
		MENU_FILE_KEY, MENU_FILE_DEF_VALUE));
	menu = m_menuBar->GetMenu(ID_MENU_FILE);
	updateFileMenu(menu);

	m_menuBar->SetMenuLabel(ID_MENU_VIEW, app.getText(MENU_SECTION,
		MENU_VIEW_KEY, MENU_VIEW_DEF_VALUE));
	menu = m_menuBar->GetMenu(ID_MENU_VIEW);
	updateViewMenu(menu);

	m_menuBar->SetMenuLabel(ID_MENU_EDIT, app.getText(MENU_SECTION,
		MENU_EDIT_KEY, MENU_EDIT_DEF_VALUE));
	menu = m_menuBar->GetMenu(ID_MENU_EDIT);
	updateEditMenu(menu);

	m_menuBar->SetMenuLabel(ID_MENU_EFFECTS, app.getText(MENU_SECTION,
		MENU_EFFECTS_KEY, MENU_EFFECTS_DEF_VALUE));
	menu = m_menuBar->GetMenu(ID_MENU_EFFECTS);
	updateEditMenu(menu);

	m_menuBar->SetMenuLabel(ID_MENU_CONFIGURATION, app.getText(MENU_SECTION,
		MENU_CONFIGURATION_KEY, MENU_CONFIGURATION_DEF_VALUE));
	menu = m_menuBar->GetMenu(ID_MENU_CONFIGURATION);
	updateEditMenu(menu);

	m_menuBar->SetMenuLabel(ID_MENU_WINDOW, app.getText(MENU_SECTION,
		MENU_WINDOW_KEY, MENU_WINDOW_DEF_VALUE));
	menu = m_menuBar->GetMenu(ID_MENU_WINDOW);
	updateEditMenu(menu);

	m_menuBar->SetMenuLabel(ID_MENU_HELP, app.getText(MENU_SECTION,
		MENU_HELP_KEY, MENU_HELP_DEF_VALUE));
	menu = m_menuBar->GetMenu(ID_MENU_HELP);
	updateEditMenu(menu);
}

void MainFrame::OnToggleToolbarCaptions(wxCommandEvent& event)
{
}

void MainFrame::CreateMainToolbar()
{

	auto toolbar = new wxAuiToolBar(this, wxID_ANY,
		wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_TEXT);

	auto artProvider = toolbar->GetArtProvider();
	artProvider->SetFlags(wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);

	toolbar->SetToolBitmapSize(FromDIP(wxSize(16, 16)));
	wxBitmap tb4_bmp1 = wxArtProvider::GetBitmap(wxART_NORMAL_FILE,
		wxART_OTHER, FromDIP(wxSize(16, 16)));

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

	m_auiManager.AddPane(toolbar, wxAuiPaneInfo().
		Name("MainToolbar").Caption("Главная панель инструментов").
		ToolbarPane().Top().Row(1));
}

void MainFrame::CreateToolbarSizeAndScale()
{
}
