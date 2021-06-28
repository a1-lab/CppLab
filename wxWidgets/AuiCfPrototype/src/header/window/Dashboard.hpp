#pragma once
#include "wx/wx.h"
#include "wx/aui/aui.h"

#define DASHBOARD_PANE_NAME wxT("dashboard")

class Dashboard {
public:
	Dashboard(wxPanel* parent);
	void Left();
	void Right();
private:
	void CreateDashboard(wxPanel* parent);
	void CreateDashboardTopPanel(wxAuiNotebook* auiNotebook);
	void CreatePropertyGrid(wxPanel* panel);

	wxPanel* m_parent;
	wxPropertyGridManager* m_propertyControl = nullptr;
	wxSizer* m_propertyControlSizer = nullptr;
};