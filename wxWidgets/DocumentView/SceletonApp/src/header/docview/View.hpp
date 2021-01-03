#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class View : public wxView {
public:
	View();
	void OnDraw(wxDC* dc) override;
	void OnUpdate(wxView* sender, wxObject* hint = NULL) override;
	bool OnClose(bool deleteWindow = true) override;
private:
	DECLARE_DYNAMIC_CLASS(View)
};