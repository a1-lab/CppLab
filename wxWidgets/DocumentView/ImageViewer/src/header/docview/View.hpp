#pragma once

#include "wx/wx.h"
#include "wx/docview.h"
#include "Canvas.hpp"

class View : public wxView {
public:
	View();
	void OnDraw(wxDC* dc) override;
	void OnUpdate(wxView* sender, wxObject* hint = NULL) override;
	bool OnClose(bool deleteWindow = true) override;
private:
	double m_Scale;
	wxBitmap m_ScaledBitmap;
	wxSize m_ViewOffset;
	Canvas* m_Canvas;

	void ReCreateScaledBitmap();

	DECLARE_DYNAMIC_CLASS(View)
};