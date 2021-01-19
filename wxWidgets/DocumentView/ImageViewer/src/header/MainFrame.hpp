#pragma once
#include "wx/wx.h"
#include "wx/docview.h"
#include "wx/aui/aui.h"

#define MAIN_FRAME_TITLE wxT("Doc view learn app1")

class Canvas;

class MainFrame : public wxDocParentFrame {
public:
	MainFrame() = default;
	MainFrame(wxDocManager* docManager, wxFrame* parent,
		wxWindowID id = wxID_ANY,
		const wxString& title = MAIN_FRAME_TITLE);
	~MainFrame() override;

	bool Create(wxDocManager* docManager, wxFrame* parent,
		wxWindowID id = wxID_ANY,
		const wxString& title = MAIN_FRAME_TITLE);

	void OnExit(wxCommandEvent& event);

	Canvas* GetCanvas();
private:
	wxAuiManager m_AuiManager;
	Canvas* m_Canvas = nullptr;
	void CreateControls();
	wxMenuBar* CreateMenuBar();

	DECLARE_DYNAMIC_CLASS(MainFrame);
	DECLARE_EVENT_TABLE();
};