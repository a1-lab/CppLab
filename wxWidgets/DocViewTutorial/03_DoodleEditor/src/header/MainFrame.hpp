#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

#define MAIN_FRAME_TITLE wxT("Doc view learn app1")

class DoodleCanvas;

class MainFrame : public wxDocParentFrame {
public:
	MainFrame(wxDocManager* manager, const wxSize& size);
	DoodleCanvas* GetCanvas() const { return m_canvas; }
private:
	void CreateMenu();
	void CreateCanvas();
	DoodleCanvas* m_canvas;
};