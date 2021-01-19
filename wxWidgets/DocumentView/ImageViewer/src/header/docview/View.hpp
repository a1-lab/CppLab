#pragma once

#include "wx/wx.h"
#include "wx/docview.h"

class Canvas;

class View : public wxView {
public:
	View();
	void OnDraw(wxDC* dc) override;
	void OnUpdate(wxView* sender, wxObject* hint = nullptr) override;
	bool OnClose(bool deleteWindow = true) override;

	wxBitmap& GetScaledBitmap();

	const wxSize& GetViewOffset() const;
	void SetViewOffset(const wxSize& value);
private:
	double m_Scale{ 1.0 };
	wxBitmap m_ScaledBitmap;
	wxSize m_ViewOffset;
	Canvas* m_Canvas = nullptr;

	void RecreateScaledBitmap();

	DECLARE_DYNAMIC_CLASS(View)
};