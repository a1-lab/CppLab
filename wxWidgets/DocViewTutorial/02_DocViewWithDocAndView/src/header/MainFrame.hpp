#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

#define MAIN_FRAME_TITLE wxT("Doc view learn app1")

class MainFrame : public wxDocParentFrame {
public:
	MainFrame(wxDocManager* manager, const wxSize& size);
};