#include "Application.hpp"
#include "MainFrame.hpp"
#include "MenuStrings.h"
#include "Ids.h"
#include "ToolbarStrings.h"
#include "menu/MainMenu.h"
#include "toolbar/MainToolbar.h"
#include "toolbar/ToolbarSize.h"
#include "CFAuiDockArt.hpp"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
/**/EVT_MENU(ID_SHOW_DASHBOARD_RIGHT, MainFrame::OnShowDashboardAtRight)
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
	m_auiManager.SetArtProvider(new CFAuiDockArt());

	CreateMainMenu();
	CreateToolBar();
	CreateToolbarSize();
	CreateMainContent();
	m_auiManager.Update();

	CreateStatusBar(1);
	//TODO: Full screen mode
	//ShowFullScreen(true, wxFULLSCREEN_NOCAPTION);
}

MainFrame::~MainFrame()
{
	m_auiManager.UnInit();
	delete m_dashboard;
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

void MainFrame::OnShowDashboardAtRight(wxCommandEvent& WXUNUSED(event))
{
	auto& dashboardPane = m_auiManager.GetPane(DASHBOARD_PANE_NAME);
	m_dashboard->Right();
	dashboardPane.Right();
	m_auiManager.Update();
}

void MainFrame::OnAdd(wxCommandEvent& WXUNUSED(event))
{

}

void MainFrame::OnPointer(wxCommandEvent& event)
{

}

void MainFrame::CreateToolBar()
{
	const Application& app = wxGetApp();

	// We use 16x17 but not 16x16 because
	//   1. selection highlighting rectangle is the same height as scale control
	//   2. this rect has the same height and width
	m_mainToolBar = createMainToolBar(this, FromDIP(wxSize(16, 17)));
	m_auiManager.AddPane(m_mainToolBar, wxAuiPaneInfo().
		Name("MainToolbar").PaneBorder(false).
		Caption(app.getText(MAIN_TOOLBAR, MAIN_TOOLBAR_CAPTION, MAIN_TOOLBAR_CAPTION_DEF_VALUE)).
		ToolbarPane().Top().Row(1));
}

void MainFrame::CreateToolbarSize()
{
	const Application& app = wxGetApp();

	m_toolbarSize = createToolbarSize(this);
	m_auiManager.AddPane(m_toolbarSize, wxAuiPaneInfo().
		Name("ToolbarSize").PaneBorder(false).
		Caption(app.getText(TOOLBAR_SIZE, TOOLBAR_SIZE_CAPTION, TOOLBAR_SIZE_CAPTION_DEF_VALUE)).
		ToolbarPane().Top().Row(1));
}

void MainFrame::CreateMainContent()
{
	auto centerPanel = new wxPanel(this);
	auto dashboardPanel = new wxPanel(this);

	m_auiManager.AddPane(centerPanel, wxAuiPaneInfo().Name("main_content").
		CenterPane().PaneBorder(false));

	m_auiManager.AddPane(dashboardPanel, wxAuiPaneInfo().Name(DASHBOARD_PANE_NAME).
		Left().TopDockable(false).BottomDockable(false).MinSize(300, -1).
		PaneBorder(false).Caption("Панель управления").
		PinButton(true).CaptionVisible(false)
	);

	auto centralPanelSizer = new wxBoxSizer(wxVERTICAL);
	centerPanel->SetSizerAndFit(centralPanelSizer);
	m_centralWindow = new wxTextCtrl(centerPanel, wxID_ANY, "left text");
	centralPanelSizer->Add(m_centralWindow, 1, wxGROW, 0);

	CreateDashbord(dashboardPanel);
}

void MainFrame::CreateDashbord(wxPanel* parent)
{
	m_dashboard = new Dashboard(parent);
}
