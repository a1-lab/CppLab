#include "wx/collpane.h"
#include "Application.hpp"
#include "MainFrame.hpp"
#include "MenuStrings.h"
#include "Ids.h"
#include "ToolbarStrings.h"
#include "menu/MainMenu.h"
#include "toolbar/ToolBar.h"
#include "toolbar/ToolBarSize.h"


BEGIN_EVENT_TABLE(MainFrame, wxFrame)
/**/EVT_MENU(ID_SHOW_TOOLBAR_CAPTIONS, MainFrame::OnShowToolbarCaptions)
/**/EVT_TOOL(ID_POINTER, MainFrame::OnPointer)
/**/EVT_TOOL(ID_ADD, MainFrame::OnAdd)
END_EVENT_TABLE()

MainFrame::MainFrame(wxDocManager* manager,
	const wxSize& size) : wxDocParentFrame(manager, nullptr,
		wxID_ANY, MAIN_FRAME_TITLE, wxDefaultPosition, size,
		wxDEFAULT_FRAME_STYLE, wxFrameNameStr)
{
	SetMinSize(wxSize(1024, 768));
	SetThemeEnabled(true);

	m_auiManager.SetManagedWindow(this);

	CreateMainMenu();
	CreateToolBar();
	CreateToolbarSize();
	m_auiManager.Update();

	CreateStatusBar(1);
	//ShowFullScreen(true, wxFULLSCREEN_NOCAPTION);

	auto pane = new wxPanel();
	auto text = new wxStaticText(pane, wxID_ANY, "test text");
	m_auiManager.AddPane(pane, wxAuiPaneInfo().
		Name("test8").Caption("Tree Pane").
		Left().Layer(1).Position(1).
		CloseButton(true).MaximizeButton(true));
	m_auiManager.Update();
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

void MainFrame::OnShowToolbarCaptions(wxCommandEvent& WXUNUSED(event))
{
	auto artProvider = m_mainToolBar->GetArtProvider();
	unsigned int flags = artProvider->GetFlags();
	unsigned int showText = flags & wxAUI_TB_TEXT;
	if (showText) {
		flags = flags & (~wxAUI_TB_TEXT);
	}
	else {
		flags = flags | wxAUI_TB_TEXT;
	}

	artProvider->SetFlags(flags);
	m_mainToolBar->Realize();
	m_toolbarSize->Realize();
}

void MainFrame::OnAdd(wxCommandEvent& WXUNUSED(event))
{
	//	m_mainToolBar->ToggleTool(ID_POINTER, false);
	//	m_mainToolBar->ToggleTool(ID_ADD, true);
	//	m_mainToolBar->Realize();
}

void MainFrame::OnPointer(wxCommandEvent& event)
{
	//	m_mainToolBar->ToggleTool(ID_POINTER, true);
	//	m_mainToolBar->ToggleTool(ID_ADD, false);
	//	m_mainToolBar->Realize();
}

void MainFrame::CreateToolBar()
{
	const Application& app = wxGetApp();

	auto color = m_menuBar->GetBackgroundColour();
	// We use 16x17 but not 16x16 because
	//   1. selection highlighting rectangle is the same height as scale control
	//   2. this rect has the same height and width
	m_mainToolBar = createMainToolBar(this, FromDIP(wxSize(16, 17)));

	m_auiManager.AddPane(m_mainToolBar, wxAuiPaneInfo().
		Name("MainToolbar").
		Caption(app.getText(MAIN_TOOLBAR, MAIN_TOOLBAR_CAPTION, MAIN_TOOLBAR_CAPTION_DEF_VALUE)).
		ToolbarPane().Top().Row(1));

}

void MainFrame::CreateToolbarSize()
{
	const Application& app = wxGetApp();
	m_toolbarSize = createToolbarSize(this, m_menuBar->GetBackgroundColour());
	m_auiManager.AddPane(m_toolbarSize, wxAuiPaneInfo().
		Name("ToolbarSize").
		Caption(app.getText(TOOLBAR_SIZE, TOOLBAR_SIZE_CAPTION, TOOLBAR_SIZE_CAPTION_DEF_VALUE)).
		ToolbarPane().Top().Row(1));
}
