#include "wx/splitter.h"
#include "wx/propgrid/advprops.h"
#include "wx/propgrid/manager.h"
#include "wx/treectrl.h"
#include "wx/treelist.h"
#include "Dashboard.hpp"
#include "Ids.h"

Dashboard::Dashboard(wxPanel* parent) : m_parent{ parent }
{
	CreateDashboard(m_parent);
}

void Dashboard::Left()
{
}

void Dashboard::Right()
{
	auto sizerItem = m_propertyControlSizer->GetItem(m_propertyControl);	
	sizerItem->SetFlag(wxGROW | wxALL);
    sizerItem->SetBorder(0);
	m_propertyControlSizer->Layout();
}

void Dashboard::CreateDashboard(wxPanel* parent)
{
	auto dashboardPanelSizer = new wxBoxSizer(wxHORIZONTAL);
	parent->SetSizerAndFit(dashboardPanelSizer);

	auto splitterWindow = new wxSplitterWindow(parent, wxID_ANY,
		wxDefaultPosition, wxDefaultSize,
		wxSP_LIVE_UPDATE | wxCLIP_CHILDREN /* | wxSP_3D | wxSP_NO_XP_THEME */);

	splitterWindow->SetMinimumPaneSize(150);

	dashboardPanelSizer->Add(splitterWindow, 1, wxGROW | wxLEFT, 2);

	auto dashboardTopPanel = new wxAuiNotebook(splitterWindow, wxID_ANY,
			wxDefaultPosition, wxDefaultSize,
		    wxAUI_NB_TOP | wxNO_BORDER);
	auto propertyGridPanel = new wxPanel(splitterWindow);

	splitterWindow->SplitHorizontally(dashboardTopPanel, propertyGridPanel, -150);

	CreateDashboardTopPanel(dashboardTopPanel);
	CreatePropertyGrid(propertyGridPanel);
}

void Dashboard::CreatePropertyGrid(wxPanel* panel)
{
	m_propertyControlSizer = new wxBoxSizer(wxHORIZONTAL);
	panel->SetSizerAndFit(m_propertyControlSizer);

	m_propertyControl = new wxPropertyGridManager(panel,
		ID_DASHBOARD_PROPERTY_GRID, wxDefaultPosition, wxDefaultSize,
		wxPG_DEFAULT_STYLE | wxPG_SPLITTER_AUTO_CENTER |
		wxPG_NO_INTERNAL_BORDER);

	m_propertyControlSizer->Add(m_propertyControl, 1, wxGROW | wxLEFT, 4);

	m_propertyControl->Append(new wxPropertyCategory("Main"));
	m_propertyControl->Append(new wxStringProperty("Label", "Name", "Initial Value"));
	m_propertyControl->Append(new wxStringProperty("Caption", "Caption", "Caption1"));

	wxColourProperty* colorProperty = new wxColourProperty("My Colour 1",
		wxPG_LABEL, wxColour(242, 109, 0));

	m_propertyControl->Append(colorProperty);
}

void Dashboard::CreateDashboardTopPanel(wxAuiNotebook* auiNotebook)
{
	auiNotebook->Freeze();

	auto templetes = new wxTreeListCtrl(auiNotebook, wxID_ANY, 
		wxDefaultPosition, wxDefaultSize, wxTL_DEFAULT_STYLE | wxTL_NO_HEADER | wxNO_BORDER);
	auiNotebook->AddPage(templetes, "Templates");
	auiNotebook->SetPageToolTip(0, "List of templates");

	auto devices = new wxTreeListCtrl(auiNotebook, wxID_ANY);
	auiNotebook->AddPage(devices, "Devices");
	auiNotebook->SetPageToolTip(1, "List of devices");

	auto test = new wxTreeCtrl(auiNotebook, wxID_ANY, 
		wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	auiNotebook->AddPage(test, "test");
	auiNotebook->SetPageToolTip(2, "test");


	auiNotebook->Thaw();
}
