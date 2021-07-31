#pragma once
#include "wx/window.h"
#include "wx/aui/framemanager.h"
#include "wx/aui/dockart.h"

class CustomAuiDockArt : public wxAuiDefaultDockArt {
public:
    void DrawBorder(wxDC& dc, wxWindow* window, const wxRect& rect,
        wxAuiPaneInfo& pane) override;
};
