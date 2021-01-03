#pragma once
#include "wx/wx.h"
#include "wx/docview.h"
#include "wx/aui/aui.h"

#define MAIN_FRAME_TITLE wxT("Doc view learn app1")

class MainFrame : public wxDocParentFrame {
public:
	MainFrame();
	MainFrame(wxDocManager* docManager, wxFrame* parent,
		wxWindowID id = wxID_ANY,
		const wxString& title = MAIN_FRAME_TITLE);
	~MainFrame();
	bool Create(wxDocManager* docManager, wxFrame* parent,
		wxWindowID id = wxID_ANY,
		const wxString& title = MAIN_FRAME_TITLE);
	void OnExit(wxCommandEvent& event);
private:
	wxAuiManager m_AuiManager;
	void CreateControls();
	wxMenuBar* CreateMenuBar();
	DECLARE_DYNAMIC_CLASS(MainFrame);
	DECLARE_EVENT_TABLE();
};
