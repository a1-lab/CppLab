#include "wx/collpane.h"
#include "MainFrame.hpp"

MainFrame::MainFrame(const wxString& title) :
	wxFrame(nullptr, wxID_ANY, title)
{
	SetProcessDPIAware();
	auto* frameSizer = new wxBoxSizer(wxVERTICAL);
	this->SetSizerAndFit(frameSizer);
	auto* containerSizer = new wxBoxSizer(wxVERTICAL);
	frameSizer->Add(containerSizer, 1, wxGROW | wxALL, 5);
	m_splitterWindow = new wxSplitterWindow(this);
	auto collapsiblePane = new wxCollapsiblePane(this, wxID_ANY,
		wxT("Test collapsible pane"));
	auto testButton = new wxButton();
	collapsiblePane->AddChild(testButton);

	Centre();
}