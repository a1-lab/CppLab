#pragma once
#include "wx/window.h"
#include "wx/dc.h"
/*1*/#include "wx/aui/framemanager.h"
/*2*/#include "wx/aui/dockart.h"

class CFAuiDockArt : public wxAuiDefaultDockArt {
public:
	void DrawBorder(wxDC& dc, wxWindow* window, const
		wxRect& rect, wxAuiPaneInfo& pane) override;

    void DrawBackground(wxDC& dc, wxWindow* window,
        int orientation, const wxRect& rect) override;

	void DrawSash(wxDC& dc, wxWindow* window,
		int orientation, const wxRect& rect);
};
