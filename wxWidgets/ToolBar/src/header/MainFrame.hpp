#pragma once
#include "wx/wx.h"

class MainFrame : public wxFrame
{
public:
	explicit MainFrame(const wxString& title);
	void OnQuit(wxCommandEvent&);
	void OnAbout(wxCommandEvent&);
private:
	DECLARE_EVENT_TABLE()
	void CreateMainToolBar();
};