#include "Application.hpp"
#include "MainFrame.hpp"
#include "Document.hpp"
#include "View.hpp"
//wxmemdbg.h must be the last one in include list
#include "wxmemdbg.h"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	SetProcessDPIAware();

	m_docManager = new wxDocManager();
	m_docManager->SetMaxDocsOpen(1);

	m_docTemplate = new wxDocTemplate(m_docManager,
		wxT("Text files"), wxT("*.txt"), wxEmptyString,
		wxT("txt"), wxT("Document"), wxT("Template"),
		CLASSINFO(Document),
		CLASSINFO(View));

	m_mainFrame = new MainFrame(m_docManager, wxSize(800, 600));
	SetTopWindow(m_mainFrame);
	m_mainFrame->Show(true);
	m_mainFrame->Centre();

	return true;
}

int Application::OnExit()
{
	wxDELETE(m_docManager);
	return 0;
}

MainFrame* Application::GetMainFrame() const
{
	return m_mainFrame;
}