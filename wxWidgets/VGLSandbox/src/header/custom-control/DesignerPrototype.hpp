#pragma once

#include "wx/wx.h"

class DesignerPrototype : public wxPanel {
public:
	explicit DesignerPrototype(wxWindow* parent, int id = wxID_ANY);

	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);
private:
};