#include "MainFrame.hpp"

MainFrame::MainFrame(wxDocManager* manager,
	const wxSize& size) : wxDocParentFrame(manager, nullptr,
		wxID_ANY, MAIN_FRAME_TITLE, wxDefaultPosition, size,
		wxDEFAULT_FRAME_STYLE, wxFrameNameStr)
{
	CreateMenu();
}

void MainFrame::CreateMenu()
{
	auto menuBar = new wxMenuBar;
	auto fileMenu = new wxMenu;
	fileMenu->Append(wxID_OPEN, _("Open\tCtrl+O"));

	menuBar->Append(fileMenu, wxT("File"));
	SetMenuBar(menuBar);
}