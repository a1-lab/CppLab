#pragma once
#include "wx/wx.h"

class View;

class DoodleCanvas : public wxScrolledWindow {
	DECLARE_EVENT_TABLE()
public:
	DoodleCanvas(wxWindow* parent, const wxPoint& pos,
		const wxSize& size, const long style);

	void OnDraw(wxDC& dc) override;
	void OnMouseEvent(wxMouseEvent& event);

	void SetView(View* view) { m_view = view; }
	View* GetView() const { return m_view; }
private:
	View* m_view = nullptr;
};