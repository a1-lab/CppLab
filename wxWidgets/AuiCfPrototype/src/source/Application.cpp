#include "wx/artprov.h"
#include "wx/stdpaths.h"
#include "wx/filefn.h"

#include "Application.hpp"
#include "CFArtProvider.hpp"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	/*1*/SetProcessDPIAware();
	/*2*/wxArtProvider::Push(new CFArtProvider);
	/*3*/loadLanguage(Lang::RUS);

	m_docManager = new wxDocManager();
	m_docManager->SetMaxDocsOpen(1);

	m_mainFrame = new MainFrame(m_docManager, wxSize(800, 600));
	m_mainFrame->Maximize(true);
	m_mainFrame->Show(true);
	m_mainFrame->Center();

	return true;
}

int Application::OnExit()
{
	wxDELETE(m_docManager);
	wxDELETE(langFile);
	return 0;
}

void Application::loadLanguage(const Lang lang)
{
	if (lang == currentLanguage) {
		return;
	}

	wxDELETE(langFile);

	wxString langFileName = wxEmptyString;
	switch (lang) {
	case Lang::ENG: langFileName = "en.txt"; break;
	case Lang::RUS: langFileName = "ru.txt"; break;
	case Lang::UKR: langFileName = "ua.txt"; break;
	default: langFileName = "ua.txt"; break;
	}

	wxString fullLangFileName = wxPathOnly(wxStandardPaths::Get().GetExecutablePath()) +
		wxT("\\lang\\") + langFileName;

	if (wxFileExists(fullLangFileName)) {
		langFile = new wxFileConfig(wxEmptyString,
			wxEmptyString, fullLangFileName);
	}
}

wxString Application::getText(wxString groupId, wxString textId,
	wxString defValue)
{
	if (nullptr == langFile) {
		return defValue;
	}

	langFile->SetPath("/" + groupId);
	return langFile->Read(textId);
}
