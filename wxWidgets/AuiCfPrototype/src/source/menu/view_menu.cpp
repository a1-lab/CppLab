#include "wx/wx.h"
#include "Application.hpp"
#include "MenuStrings.h"
#include "Ids.h"

wxMenu* createViewMenu() {

	auto result = new wxMenu();
	const Application& app = wxGetApp();

	result->Append(ID_SHOW_TOOLBAR_CAPTIONS,
		app.getText(VIEW_SECTION,
			VIEW_SHOW_TOOLBAR_CAPTIONS_KEY, VIEW_SHOW_TOOLBAR_CAPTIONS_DEF_VALUE),
		app.getText(FILE_SECTION,
			VIEW_SHOW_TOOLBAR_CAPTIONS_HELP_KEY, VIEW_SHOW_TOOLBAR_CAPTIONS_HELP_DEF_VALUE),
		wxITEM_CHECK);

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