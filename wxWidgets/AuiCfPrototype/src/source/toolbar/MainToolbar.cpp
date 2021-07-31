#include "wx/aui/aui.h"
#include "wx/artprov.h"
#include "Application.hpp"
#include "CFArtId.h"
#include "Ids.h"
#include "ToolbarStrings.h"

constexpr auto SCALE_SPACER_SIZE = 7;

wxChoice* createScale(wxAuiToolBar* toolbar);

wxAuiToolBar* createMainToolBar(wxWindow* parent, const wxSize& iconSize) {
	const Application& app = wxGetApp();

	auto result = new wxAuiToolBar(parent, wxID_ANY,
		wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | //wxAUI_TB_OVERFLOW |
		wxAUI_TB_HORZ_TEXT | wxAUI_TB_PLAIN_BACKGROUND
	);

	result->SetToolBitmapSize(iconSize);

	result->AddTool(ID_NEW,
		//app.getText(MAIN_TOOLBAR, NEW_KEY, NEW_DEF_VALUE),
		"",
		wxArtProvider::GetBitmap(ART_NEW_PROJECT, wxART_OTHER, iconSize),
		wxNullBitmap, wxITEM_NORMAL,
		app.getText(MAIN_TOOLBAR, NEW_SHORT_HELP_KEY, NEW_SHORT_HELP_DEF_VALUE),
		app.getText(MAIN_TOOLBAR, NEW_LONG_HELP_KEY, NEW_LONG_HELP_DEF_VALUE),
		nullptr);

	result->AddTool(ID_OPEN,
		//app.getText(MAIN_TOOLBAR, OPEN_KEY, OPEN_DEF_VALUE) + FOUR_SPACES,
		"",
		wxArtProvider::GetBitmap(ART_OPEN_PROJECT, wxART_OTHER, iconSize),
		wxNullBitmap, wxITEM_NORMAL,
		app.getText(MAIN_TOOLBAR, OPEN_SHORT_HELP_KEY, OPEN_SHORT_HELP_DEF_VALUE),
		app.getText(MAIN_TOOLBAR, OPEN_LONG_HELP_KEY, OPEN_LONG_HELP_DEF_VALUE),
		nullptr);

	result->AddTool(ID_SAVE,
		//app.getText(MAIN_TOOLBAR, SAVE_KEY, SAVE_DEF_VALUE) + FOUR_SPACES,
		"",
		wxArtProvider::GetBitmap(ART_SAVE_PROJECT, wxART_OTHER, iconSize),
		wxNullBitmap, wxITEM_NORMAL,
		app.getText(MAIN_TOOLBAR, SAVE_SHORT_HELP_KEY, SAVE_SHORT_HELP_DEF_VALUE),
		app.getText(MAIN_TOOLBAR, SAVE_LONG_HELP_KEY, SAVE_LONG_HELP_DEF_VALUE),
		nullptr);

	result->AddSeparator();

	result->AddTool(ID_POINTER,
		//app.getText(MAIN_TOOLBAR, POINTER_KEY, POINTER_DEF_VALUE),
		"",
		wxArtProvider::GetBitmap(ART_POINTER, wxART_OTHER, iconSize),
		wxNullBitmap, wxITEM_RADIO,
		app.getText(MAIN_TOOLBAR, POINTER_SHORT_HELP_KEY, POINTER_SHORT_HELP_DEF_VALUE),
		app.getText(MAIN_TOOLBAR, POINTER_LONG_HELP_KEY, POINTER_LONG_HELP_DEF_VALUE),
		nullptr);

	result->ToggleTool(ID_POINTER, true);
	//result->AddSpacer(SPACE_IN_SECTION);

	result->AddTool(ID_ADD,
		app.getText(MAIN_TOOLBAR, ADD_KEY, ADD_DEF_VALUE),
		wxArtProvider::GetBitmap(ART_ADD, wxART_OTHER, iconSize),
		wxNullBitmap, wxITEM_RADIO,
		app.getText(MAIN_TOOLBAR, ADD_SHORT_HELP_KEY, ADD_SHORT_HELP_DEF_VALUE),
		app.getText(MAIN_TOOLBAR, ADD_LONG_HELP_KEY, ADD_LONG_HELP_DEF_VALUE),
		nullptr);

	result->AddTool(ID_DELETE,
		//app.getText(MAIN_TOOLBAR, DELETE_KEY, DELETE_DEF_VALUE),
		"",
		wxArtProvider::GetBitmap(ART_DELETE, wxART_OTHER, iconSize),
		wxNullBitmap, wxITEM_NORMAL,
		app.getText(MAIN_TOOLBAR, DELETE_SHORT_HELP_KEY, DELETE_SHORT_HELP_DEF_VALUE),
		app.getText(MAIN_TOOLBAR, DELETE_LONG_HELP_KEY, DELETE_LONG_HELP_DEF_VALUE),
		nullptr);
	result->AddSeparator();

	result->AddTool(ID_EFFECTS,
		app.getText(MAIN_TOOLBAR, EFFECTS_KEY, EFFECTS_DEF_VALUE),
		wxArtProvider::GetBitmap(ART_EFFECTS,
			wxART_OTHER, iconSize),
		wxNullBitmap, wxITEM_NORMAL,
		app.getText(MAIN_TOOLBAR, EFFECTS_SHORT_HELP_KEY, EFFECTS_SHORT_HELP_DEF_VALUE),
		app.getText(MAIN_TOOLBAR, EFFECTS_LONG_HELP_KEY, EFFECTS_LONG_HELP_DEF_VALUE),
		nullptr);

	result->AddTool(ID_PLAY,
		app.getText(MAIN_TOOLBAR, PLAY_KEY, PLAY_DEF_VALUE),
		wxArtProvider::GetBitmap(ART_PLAY,
			wxART_OTHER, iconSize),
		wxNullBitmap, wxITEM_NORMAL,
		app.getText(MAIN_TOOLBAR, PLAY_SHORT_HELP_KEY, PLAY_SHORT_HELP_DEF_VALUE),
		app.getText(MAIN_TOOLBAR, PLAY_LONG_HELP_KEY, PLAY_LONG_HELP_DEF_VALUE),
		nullptr);

	result->AddTool(ID_WRITE_PROGRAM,
		app.getText(MAIN_TOOLBAR, WRITE_PROGRAM_KEY, WRITE_PROGRAM_DEF_VALUE),
		wxArtProvider::GetBitmap(ART_WRITE,
			wxART_OTHER, iconSize),
		wxNullBitmap, wxITEM_NORMAL,
		app.getText(MAIN_TOOLBAR, WRITE_PROGRAM_SHORT_HELP_KEY, WRITE_PROGRAM_SHORT_HELP_DEF_VALUE),
		app.getText(MAIN_TOOLBAR, WRITE_PROGRAM_LONG_HELP_KEY, WRITE_PROGRAM_LONG_HELP_DEF_VALUE),
		nullptr);

	result->AddSeparator();

	result->SetToolDropDown(ID_OPEN, true);
	result->SetToolDropDown(ID_SAVE, true);

	//result->SetCustomOverflowItems(prepend_items, append_items);

	result->AddSpacer(SCALE_SPACER_SIZE);
	result->AddControl(createScale(result));
	result->AddSpacer(2 * SCALE_SPACER_SIZE);
	result->SetMargins(0, 0, 5, 5);
	result->Realize();

	return result;
}

wxChoice* createScale(wxAuiToolBar* toolbar) {
	auto result = new wxChoice(toolbar, wxID_ANY);
	result->AppendString("10%");
	result->AppendString("20%");
	result->AppendString("30%");
	result->AppendString("40%");
	result->AppendString("50%");
	result->AppendString("60%");
	result->AppendString("70%");
	result->AppendString("80%");
	result->AppendString("90%");
	result->AppendString("100%");

	result->Select(4);
	return result;
}