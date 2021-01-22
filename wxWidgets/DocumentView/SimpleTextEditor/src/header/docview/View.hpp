#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class View : public wxView {
public:
	View();

	wxTextCtrl* GetEditor();
	void OnDraw(wxDC* dc) override;
	void OnUpdate(wxView* sender, wxObject* hint) override;
	bool OnClose(bool deleteWindow = true) override;

	DECLARE_DYNAMIC_CLASS(View)
};