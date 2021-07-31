#include "wx/aui/aui.h"
#include "wx/spinctrl.h"
#include "Application.hpp"
#include "Ids.h"
#include "custom_control/TransparentStaticText.hpp"
#include "ToolbarStrings.h"

wxAuiToolBar* createToolbarSize(wxWindow* parent) {
	const Application& app = wxGetApp();

	auto result = new wxAuiToolBar(parent, wxID_ANY,
		wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | //wxAUI_TB_OVERFLOW
		wxAUI_TB_HORZ_TEXT | wxAUI_TB_PLAIN_BACKGROUND
	);


	auto heightText = new TransparentStaticText(result, wxID_ANY,
		app.getText(TOOLBAR_SIZE, HEIGHT_KEY, HEIGHT_DEF_VALUE) + ONE_SPACE);
	auto heightControl = new wxSpinCtrl(result);

	result->AddControl(heightText);
	result->AddControl(heightControl);

	auto widthText = new TransparentStaticText(result, wxID_ANY,
		FOUR_SPACES + app.getText(TOOLBAR_SIZE, WIDTH_KEY, WIDTH_DEF_VALUE) + ONE_SPACE);
	auto widthControl = new wxSpinCtrl(result);
	result->AddControl(widthText);
	result->AddControl(widthControl);

	return result;
}