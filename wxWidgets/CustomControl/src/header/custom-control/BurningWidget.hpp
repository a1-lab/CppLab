#pragma once

#include "wx/wx.h"

class BurningWidget : public wxPanel {
public:
	BurningWidget(wxPanel* parent, int id);

	void OnSize(wxSizeEvent& event);
	void OnPaint(wxPaintEvent& event);

private:
	wxPanel* m_parent;
};