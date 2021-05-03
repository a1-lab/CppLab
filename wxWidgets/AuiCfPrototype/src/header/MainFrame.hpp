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
private:
	//m_auiManager is created on stack.
	//i.e. automatically created and deleted.
	wxAuiManager m_auiManager;
	wxAuiDefaultToolBarArt* m_toolbarArt = nullptr;
	wxAuiToolBarItemArray prepend_items;
	wxAuiToolBarItemArray append_items;

	void CreateMainMenu();
	void CreateMainToolbar();
	void CreateToolbarSizeAndScale();
};