#include "wx/app.h"
#include "View.hpp"
#include "MainFrame.hpp"
#include "Application.hpp"
#include "DoodleCanvas.hpp"

IMPLEMENT_DYNAMIC_CLASS(View, wxView)

void View::OnDraw(wxDC* dc) {
}

bool View::OnCreate(wxDocument* doc, long flags)
{
	const Application& app = wxGetApp();
	m_mainFrame = app.GetMainFrame();
	SetFrame(m_mainFrame);
	m_mainFrame->GetCanvas()->SetView(this);

	Activate(true);
	return true;
}