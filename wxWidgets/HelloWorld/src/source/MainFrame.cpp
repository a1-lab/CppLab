#include "../header/MainFrame.hpp"
#include "../BlueBall.XPM"

MainFrame::MainFrame(const wxString& title) :
	wxFrame(nullptr, wxID_ANY, title)
{
	SetIcon(wxIcon(main_icon_xpm));
	Centre();
}