#pragma once
#include "wx/wx.h"
#include "wx/docview.h"
#include "wx/aui/aui.h"

#define MAIN_FRAME_TITLE wxT("Doc view learn app1")

class MainFrame : public wxDocParentFrame {
public:
	enum
	{
		ID_EDITOR = wxID_HIGHEST + 1
	};

	MainFrame();
	MainFrame(wxDocManager* docManager, wxFrame* parent,
		wxWindowID id = wxID_ANY,
		const wxString& title = MAIN_FRAME_TITLE);
	~MainFrame();

	bool Create(wxDocManager* docManager, wxFrame* parent,
		wxWindowID id = wxID_ANY,
		const wxString& title = MAIN_FRAME_TITLE);

	wxTextCtrl* GetEditor();

	void OnExit(wxCommandEvent& event);
private:
	wxAuiManager m_AuiManager;
	void CreateControls();
	wxMenuBar* CreateMenuBar();

	wxTextCtrl* m_Editor;

	DECLARE_DYNAMIC_CLASS(MainFrame);
	DECLARE_EVENT_TABLE();
};
