#include "wx/wx.h"
#include "Application.hpp"
#include "MenuStrings.h"
#include "Ids.h"

wxMenu* createViewMenu() {

	auto result = new wxMenu();
	const Application& app = wxGetApp();

	result->Append(ID_SHOW_DASHBOARD_RIGHT,
		app.getText(VIEW_SECTION, SHOW_DASHBOARD_RIGHT_KEY, SHOW_DASHBOARD_RIGHT_DEF_VALUE),
		app.getText(VIEW_SECTION, SHOW_DASHBOARD_RIGHT_HELP_KEY, SHOW_DASHBOARD_RIGHT_HELP_DEF_VALUE),
		wxITEM_NORMAL);

	return result;
}

void updateViewMenu(wxMenu* menu) {
	const Application& app = wxGetApp();
	/*
	menu->SetLabel(wxID_EXIT, app.getText(FILE_SECTION,
		FILE_EXIT_KEY, FILE_EXIT_DEF_VALUE));
	menu->SetHelpString(wxID_EXIT, app.getText(FILE_SECTION,
		FILE_EXIT_HELP_KEY, FILE_EXIT_HELP_DEF_VALUE));
	*/
}