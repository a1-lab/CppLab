#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class MainFrame;

class Application : public wxApp {
public:
	bool OnInit() override;
	int OnExit() override;
	MainFrame* GetMainFrame() const;
private:
	wxDocManager* m_docManager = nullptr;
	wxDocTemplate* m_docTemplate = nullptr;
	MainFrame* m_mainFrame = nullptr;
};

DECLARE_APP(Application)