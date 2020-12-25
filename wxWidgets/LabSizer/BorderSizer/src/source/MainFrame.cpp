#include "MainFrame.hpp"
#include "wx/button.h"

MainFrame::MainFrame(const wxString& title) :
	wxFrame(nullptr, wxID_ANY, title)
{
	SetProcessDPIAware();
	auto* frameSizer = new wxBoxSizer(wxVERTICAL);

	auto* button = new wxButton(this, wxID_ANY,
		wxT("Test"), wxDefaultPosition, wxSize(240, 50));

	frameSizer->Add(button, 0, wxALL, 10);
	//frameSizer->SetSizeHints(this);
	SetSizerAndFit(frameSizer);

	Centre();
}