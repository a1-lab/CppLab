#include "Application.hpp"
#include "MainFrame.hpp"
//wxmemdbg.h must be the last one in include list
#include "wxmemdbg.h"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	SetProcessDPIAware();

	m_docManager = new wxDocManager();
	m_docManager->SetMaxDocsOpen(1);

	auto frame = new MainFrame(m_docManager, wxSize(800, 600));
	frame->Show(true);
	frame->Centre();

	return true;
}

int Application::OnExit()
{
	wxDELETE(m_docManager);
	return 0;
}