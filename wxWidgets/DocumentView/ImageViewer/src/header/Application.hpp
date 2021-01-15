#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class Application : public wxApp {
public:
	bool OnInit() override;
	int OnExit() override;
private:
	wxDocManager* m_DocManager;
};

DECLARE_APP(Application)