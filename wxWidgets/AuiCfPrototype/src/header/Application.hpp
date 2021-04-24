#pragma once
#include "wx/wx.h"
#include "wx/docview.h"
#include "MainFrame.hpp"

//wxmemdbg must be the last one in include list
#include "wxmemdbg.h"

class Application : public wxApp {
public:
	bool OnInit() override;
	int OnExit() override;
private:
	MainFrame* m_mainFrame = nullptr;
	wxDocManager* m_docManager = nullptr;
};

DECLARE_APP(Application)