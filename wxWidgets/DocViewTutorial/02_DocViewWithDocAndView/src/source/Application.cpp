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

	auto templ = new wxDocTemplate(m_docManager,
		wxT("Text files"), wxT("*.txt"), wxEmptyString,
		wxT("txt"), wxT("Document"), wxT("Template"),
		CLASSINFO(Document),
		CLASSINFO(View));

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