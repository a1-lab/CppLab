#pragma once
#include "wx/wx.h"
#include "View.hpp"

#define CanvasStyle wxNO_BORDER|wxHSCROLL|wxVSCROLL|wxTAB_TRAVERSAL
#define CanvasName wxT("Canvas")

class Canvas : public wxWindow {
public:
	Canvas();

	Canvas(wxWindow* parent,
		wxWindowID id = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = CanvasStyle,
		const wxString& name = CanvasName);

	bool Create(wxWindow* parent,
		wxWindowID id = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = CanvasStyle,
		const wxString& name = CanvasName);
private:
	View* m_View;
	void Init();

	DECLARE_DYNAMIC_CLASS(Canvas)
	DECLARE_EVENT_TABLE()
};