#include "wx/wx.h"
#include "Application.hpp"
#include "Strings.h"
#include "Ids.h"

wxMenu* createFileMenu() {

	auto result = new wxMenu();
	Application& app = wxGetApp();

	result->Append(wxID_EXIT,
		app.getText(FILE_SECTION,
			FILE_EXIT_KEY, FILE_EXIT_DEF_VALUE),
		app.getText(FILE_SECTION,
			FILE_EXIT_HELP_KEY, FILE_EXIT_HELP_DEF_VALUE));

	return result;

}