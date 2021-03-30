#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class View : public wxView {
	DECLARE_DYNAMIC_CLASS(View)
public:
	void wxView::OnDraw(wxDC* dc) override;
};