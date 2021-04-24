#pragma once
#include "wx/wx.h"
#include "wx/docview.h"
//wxmemdbg must be the 
//last one in include list
#include "wxmemdbg.h"

#define MAIN_FRAME_TITLE wxT("AUI CF Prototype Application")

class MainFrame : public wxDocParentFrame {
public:
	MainFrame(wxDocManager* manager, const wxSize& size);
};