#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class Application : public wxApp {
public:
	bool OnInit() override;
	int OnExit() override;
private:
	wxDocManager* m_docManager = nullptr;
};

DECLARE_APP(Application)