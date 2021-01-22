#include "Application.hpp"
#include "MainFrame.hpp"
#include "Document.hpp"
#include "View.hpp"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	m_DocManager = new wxDocManager();
	m_DocManager->SetMaxDocsOpen(1);
	wxDocTemplate* docTemplate = new
		wxDocTemplate(m_DocManager, _("Simple Text Editor Document"),
			wxT("*.txt"), wxEmptyString,
			wxT("txt"), wxT("SimpleTextEditor Doc"), wxT("SimpleTextEditor View"),
			CLASSINFO(Document), CLASSINFO(View));

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
