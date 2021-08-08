#include "wx/splitter.h"
#include "wx/propgrid/advprops.h"
#include "wx/propgrid/manager.h"
#include "wx/aui/aui.h"
#include "CheckTree.hpp"
#include "Dashboard.hpp"
#include "Ids.h"
#include "CFAuiDockArt.hpp"

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
		wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE | wxCLIP_CHILDREN);

	splitterWindow->SetMinimumPaneSize(150);

	dashboardPanelSizer->Add(splitterWindow, 1, wxGROW | wxALL, 0);

	auto topPanel = new wxPanel(splitterWindow);
	auto propertyGridPanel = new wxPanel(splitterWindow);

	splitterWindow->SplitHorizontally(topPanel, propertyGridPanel, -150);

	CreateDashboardTopPanel(topPanel);
	CreatePropertyGrid(propertyGridPanel);
}

void Dashboard::CreatePropertyGrid(wxPanel* panel)
{
	m_propertyControlSizer = new wxBoxSizer(wxHORIZONTAL);
	panel->SetSizerAndFit(m_propertyControlSizer);

	m_propertyControl = new wxPropertyGridManager(panel,
		ID_DASHBOARD_PROPERTY_GRID, wxDefaultPosition, wxDefaultSize,
		wxPG_DEFAULT_STYLE | wxPG_SPLITTER_AUTO_CENTER |
		wxPG_NO_INTERNAL_BORDER //| wxPG_HIDE_CATEGORIES
	);

	//m_propertyControlSizer->Add(m_propertyControl, 1, wxGROW | wxRIGHT, 2);
	m_propertyControlSizer->Add(m_propertyControl, 1, wxGROW | wxALL, 0);

	m_propertyControl->Append(new wxPropertyCategory("Main"));
	m_propertyControl->Append(new wxStringProperty("Label", "Name", "Initial Value"));
	m_propertyControl->Append(new wxStringProperty("Caption", "Caption", "Caption1"));

	wxColourProperty* colorProperty = new wxColourProperty("My Colour 1",
		wxPG_LABEL, wxColour(242, 109, 0));

	m_propertyControl->Append(colorProperty);
}


void Dashboard::PopulateTemplatesTest(wxTreeCtrl* templates)
{
	auto root = templates->AddRoot("root");
	templates->SetItemState(root, 0);
	auto item1 = templates->AppendItem(root, "item1");
	templates->SetItemState(item1, 0);

	auto sub1 = templates->AppendItem(item1, "sub1");
	auto sub2 = templates->AppendItem(item1, "sub2");
	auto sub3 = templates->AppendItem(item1, "sub3");
	templates->SetItemState(sub1, 0);
	templates->SetItemState(sub2, 0);
	templates->SetItemState(sub3, 0);


	auto item2 = templates->AppendItem(root, "item2");
	auto item3 = templates->AppendItem(root, "item3");
	templates->SetItemState(item2, 0);
	templates->SetItemState(item3, 0);
}


void Dashboard::CreateDashboardTopPanel(wxPanel* panel)
{

	auto sizer = new wxBoxSizer(wxHORIZONTAL);
	panel->SetSizerAndFit(sizer);

	auto auiNotebook = new wxAuiNotebook(panel, wxID_ANY,
		wxDefaultPosition, wxDefaultSize, wxAUI_NB_TOP | wxAUI_NB_TAB_MOVE | wxNO_BORDER);

	sizer->Add(auiNotebook, 1, wxGROW | wxALL, 0);

	//TODO: wxAuiSimpleTabArt
	auiNotebook->SetArtProvider(new wxAuiSimpleTabArt());

	auiNotebook->Freeze();

	auto templates = new wxCheckTree(auiNotebook, wxID_ANY,
		wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT |
		wxTR_HIDE_ROOT | wxTR_TWIST_BUTTONS | wxTR_NO_LINES | 
		wxTR_FULL_ROW_HIGHLIGHT | wxNO_BORDER);

	auiNotebook->AddPage(templates, "Templates");
	auiNotebook->SetPageToolTip(0, "List of templates");

	auto devices = new wxCheckTree(auiNotebook, wxID_ANY,
		wxDefaultPosition, wxDefaultSize, wxTR_HIDE_ROOT | wxTR_HAS_BUTTONS |
		wxTR_LINES_AT_ROOT | wxNO_BORDER);

	auiNotebook->AddPage(devices, "Devices");
	auiNotebook->SetPageToolTip(1, "List of devices");

	auiNotebook->Thaw();

	PopulateTemplatesTest(templates);
	PopulateTemplatesTest(devices);
}
