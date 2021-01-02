#include "Application.hpp"
#include "MainFrame.hpp"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	m_DocManager = new wxDocManager();
	m_DocManager->SetMaxDocsOpen(1);

	MainFrame* frame = new MainFrame(m_DocManager, nullptr);
	SetTopWindow(frame);
	frame->Centre();
	frame->Show();

	return true;
}

int Application::OnExit()
{
	wxDELETE(m_DocManager);
	return 0;
}
