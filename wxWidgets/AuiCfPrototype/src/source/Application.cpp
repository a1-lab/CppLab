#include "Application.hpp"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	SetProcessDPIAware();
	m_docManager = new wxDocManager();
	m_docManager->SetMaxDocsOpen(1);

	m_mainFrame = new MainFrame(m_docManager, wxSize(800, 600));
	m_mainFrame->Show(true);
	m_mainFrame->Center();

	return true;
}

int Application::OnExit()
{
	wxDELETE(m_docManager);
	return 0;
}
