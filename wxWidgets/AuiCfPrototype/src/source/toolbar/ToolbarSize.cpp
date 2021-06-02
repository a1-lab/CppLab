#include "wx/aui/aui.h"
#include "wx/spinctrl.h"
#include "Application.hpp"
#include "Ids.h"

wxAuiToolBar* createToolbarSize(wxWindow* parent, const wxColour& bgColor) {
	const Application& app = wxGetApp();

	auto result = new wxAuiToolBar(parent, wxID_ANY,
		wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | //wxAUI_TB_OVERFLOW
		wxAUI_TB_HORZ_TEXT
	);

	auto widthText = new wxStaticText(result, wxID_ANY, "Высота");
	widthText->SetBackgroundColour(wxNullColour);
	auto widthControl = new wxSpinCtrl(result);
	result->AddControl(widthText);
	result->AddControl(widthControl, "Высота");

	return result;
}