#pragma once
#include "wx/wx.h"
#include "wx/aui/aui.h"

class MainFrame : public wxFrame
{
public:
	explicit MainFrame(const wxString& title);
	void OnQuit(wxCommandEvent&);
	void OnAbout(wxCommandEvent&);
private:
	wxAuiManager m_mgr;
	DECLARE_EVENT_TABLE();
};