#pragma once
//https://wxwidgets.info/getting_aquainted_with_doc_view_architecture_part_1_en/
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
