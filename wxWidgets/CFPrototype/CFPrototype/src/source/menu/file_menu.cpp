#include "wx/wx.h"
#include "Application.hpp"
#include "MenuStrings.h"
#include "Ids.h"

wxMenu* createFileMenu() {

	auto result = new wxMenu();
	const Application& app = wxGetApp();

	result->Append(wxID_EXIT,
		app.getText(FILE_SECTION,
			FILE_EXIT_KEY, FILE_EXIT_DEF_VALUE),
		app.getText(FILE_SECTION,
			FILE_EXIT_HELP_KEY, FILE_EXIT_HELP_DEF_VALUE));

	return result;
}

void updateFileMenu(wxMenu* menu) {
	const Application& app = wxGetApp();

	menu->SetLabel(wxID_EXIT, app.getText(FILE_SECTION,
		FILE_EXIT_KEY, FILE_EXIT_DEF_VALUE));
	menu->SetHelpString(wxID_EXIT, app.getText(FILE_SECTION,
		FILE_EXIT_HELP_KEY, FILE_EXIT_HELP_DEF_VALUE));
}