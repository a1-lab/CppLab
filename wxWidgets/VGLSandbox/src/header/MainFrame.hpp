#pragma once
#include "wx/wx.h"
#include "DesignerScrolled.hpp"
//#include "BurningWidget.hpp"

enum wxAppID
{
	wxID_BUTTON1
};

class MainFrame : public wxFrame
{
public:
	explicit MainFrame(const wxString& title);

	int GetCurWidth();

	void OnQuit(wxCommandEvent&);
	void OnButton1(wxCommandEvent&);
	void OnAbout(wxCommandEvent&);
	void OnScroll(wxScrollEvent& event);
private:
	int cur_width;
	wxSlider* m_slider;
	//BurningWidget* m_wid;
	vgl::DesignerScrolled* m_desiner;
	//wxScrolledCanvas* m_scrolledCanvas;

	void CreateMenuBar();
	void CreateMainToolBar();
	void AddBurningWidget();
	void AddDesignerPrototype();
	void AddScrollWindow();

	DECLARE_EVENT_TABLE()
};