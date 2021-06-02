#pragma once
#include "wx/wx.h"
#include "wx/docview.h"
#include "wx/aui/aui.h"
//wxmemdbg must be the 
//last one in include list
#include "wxmemdbg.h"

class MainFrame : public wxDocParentFrame {
public:
	MainFrame(wxDocManager* manager, const wxSize& size);
	virtual ~MainFrame();
	// UpdateMainMenu вызывается после смены языка
	void UpdateMainMenu();
	void OnShowToolbarCaptions(wxCommandEvent& event);
	void OnAdd(wxCommandEvent& event);
	void OnPointer(wxCommandEvent& event);
private:
	void CreateMainMenu();
	void CreateToolBar();
	void CreateToolbarSize();

	//m_auiManager is created on stack.
	//i.e. automatically created and deleted.
	wxAuiManager m_auiManager;
	wxAuiToolBarItemArray prepend_items;
	wxAuiToolBarItemArray append_items;
	wxMenuBar* m_menuBar = new wxMenuBar();
	wxAuiToolBar* m_mainToolBar = nullptr;
	wxAuiToolBar* m_toolbarSize = nullptr;

	DECLARE_EVENT_TABLE();
};