#include "MainFrame.hpp"

IMPLEMENT_DYNAMIC_CLASS(MainFrame, wxDocParentFrame)
BEGIN_EVENT_TABLE(MainFrame, wxDocParentFrame)
EVT_MENU(wxID_EXIT, MainFrame::OnExit)
END_EVENT_TABLE()

MainFrame::MainFrame()
{
}

MainFrame::MainFrame(wxDocManager* docManager, wxFrame* parent, wxWindowID id, const wxString& title)
{
	Create(docManager, parent, id, title);
}

MainFrame::~MainFrame()
{
	m_AuiManager.UnInit();
}

bool MainFrame::Create(wxDocManager* docManager, wxFrame* parent, wxWindowID id, const wxString& title)
{
	bool res = wxDocParentFrame::Create(docManager, parent, id, title,
		wxDefaultPosition, wxSize(650, 450));
	if (res)
	{
		CreateControls();
	}
	return res;
}

void MainFrame::OnExit(wxCommandEvent& event)
{
	Close();
}

void MainFrame::CreateControls()
{
	SetMenuBar(CreateMenuBar());
	m_AuiManager.SetManagedWindow(this);

	m_Editor = new wxTextCtrl(this, ID_EDITOR, wxEmptyString, wxDefaultPosition,
		wxDefaultSize, wxTE_MULTILINE);

	m_AuiManager.AddPane(m_Editor,
		wxAuiPaneInfo().CenterPane().Name(_("Canvas")));

	m_AuiManager.Update();
}

wxMenuBar* MainFrame::CreateMenuBar()
{
	wxMenuBar* result = new wxMenuBar;

	wxMenu* fileMenu = new wxMenu;
	fileMenu->Append(wxID_NEW, _("New\tCtrl+N"));
	fileMenu->Append(wxID_OPEN, _("Open\tCtrl+O"));
	fileMenu->AppendSeparator();
	fileMenu->Append(wxID_SAVE, _("Save\tCtrl+S"));
	fileMenu->Append(wxID_SAVEAS, _("Save as..."));
	fileMenu->AppendSeparator();
	fileMenu->Append(wxID_EXIT, _("Exit\tAlt+F4"));

	wxMenu* helpMenu = new wxMenu;
	helpMenu->Append(wxID_ABOUT, _("About..."));

	result->Append(fileMenu, _("File"));
	result->Append(helpMenu, _("Help"));

	return result;
}
