#include "MainFrame.hpp"
#include "DoodleCanvas.hpp"

MainFrame::MainFrame(wxDocManager* manager,
	const wxSize& size) : wxDocParentFrame(manager, nullptr,
		wxID_ANY, MAIN_FRAME_TITLE, wxDefaultPosition, size,
		wxDEFAULT_FRAME_STYLE, wxFrameNameStr)
{
	CreateMenu();
	CreateCanvas();
}

void MainFrame::CreateMenu()
{
	auto menuBar = new wxMenuBar;
	auto fileMenu = new wxMenu;
	fileMenu->Append(wxID_OPEN, _("Open\tCtrl+O"));

	menuBar->Append(fileMenu, wxT("File"));
	SetMenuBar(menuBar);
}

void MainFrame::CreateCanvas()
{
	m_canvas = new DoodleCanvas(this, wxDefaultPosition,
		wxDefaultSize, 0);
	//m_canvas->SetCursor(wxCursor(wxCURSOR_PENCIL));
	m_canvas->SetScrollbars(20, 20, 50, 50);
	m_canvas->SetBackgroundColour(*wxWHITE);
	m_canvas->ClearBackground();
}