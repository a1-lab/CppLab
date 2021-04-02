#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class MainFrame;

class View : public wxView {
	DECLARE_DYNAMIC_CLASS(View)
public:
	void OnDraw(wxDC* dc) override;
	bool OnCreate(wxDocument* doc, long flags) override;
private:
	MainFrame* m_mainFrame = nullptr;
};