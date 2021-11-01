#pragma once
#include "wx/wx.h"
#include "BurningWidget.hpp"

class MainFrame : public wxFrame
{
public:
	explicit MainFrame(const wxString& title);

	int GetCurWidth();

	void OnQuit(wxCommandEvent&);
	void OnAbout(wxCommandEvent&);
	void OnScroll(wxScrollEvent& event);
private:
	int cur_width;
	wxSlider* m_slider;
	BurningWidget* m_wid;

	DECLARE_EVENT_TABLE()
};