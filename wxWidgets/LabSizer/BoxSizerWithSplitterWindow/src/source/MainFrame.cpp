#include "wx/collpane.h"
#include "MainFrame.hpp"

MainFrame::MainFrame(const wxString& title) :
	wxFrame(nullptr, wxID_ANY, title)
{
	auto* frameSizer = new wxBoxSizer(wxVERTICAL);
	this->SetSizerAndFit(frameSizer);

	m_splitterWindow = new wxSplitterWindow(this);
	frameSizer->Add(m_splitterWindow, 1, wxGROW | wxALL, 0);

	auto m_left = new wxTextCtrl(m_splitterWindow, wxID_ANY, "first text");
	auto m_right = new wxTextCtrl(m_splitterWindow, wxID_ANY, "second text");
	m_splitterWindow->SplitVertically(m_left, m_right, 100);

}