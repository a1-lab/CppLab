#pragma once
#include "wx/wx.h"
#include "wx/docview.h"
#include "wx/splitter.h"
#include "wx/aui/aui.h"
#include "wx/propgrid/propgrid.h"
#include "window/Dashboard.hpp"

//wxmemdbg must be the 
//last one in include list
#include "wxmemdbg.h"

class MainFrame : public wxDocParentFrame {
public:
	MainFrame(wxDocManager* manager, const wxSize& size);
	virtual ~MainFrame();
	// UpdateMainMenu вызывается после смены языка
	void UpdateMainMenu();
	void OnShowDashboardAtRight(wxCommandEvent& event);
	void OnAdd(wxCommandEvent& event);
	void OnPointer(wxCommandEvent& event);
private:
	void CreateMainMenu();
	void CreateToolBar();
	void CreateToolbarSize();

	void CreateMainContent();
	void CreateDashbord(wxPanel* parent);

	//m_auiManager is created on stack.
	//i.e. automatically created and deleted.
	wxAuiManager m_auiManager;
	wxAuiToolBarItemArray prepend_items;
	wxAuiToolBarItemArray append_items;
	wxMenuBar* m_menuBar = new wxMenuBar();
	wxAuiToolBar* m_mainToolBar = nullptr;
	wxAuiToolBar* m_toolbarSize = nullptr;

	Dashboard* m_dashboard = nullptr;
	wxWindow* m_centralWindow = nullptr;

	DECLARE_EVENT_TABLE();
};