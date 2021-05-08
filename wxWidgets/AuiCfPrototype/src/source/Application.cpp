#include "wx/artprov.h"
#include "wx/stdpaths.h"
#include "wx/filefn.h"

#include "Application.hpp"
#include "CFArtProvider.hpp"
#include "Strings.h"
#include "Settings.h"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	/*1*/SetProcessDPIAware();
	/*2*/wxArtProvider::Push(new CFArtProvider);
	/*3*/loadSettingsFile();
	/*4*/loadLanguage(getLang());

	m_docManager = new wxDocManager();
	m_docManager->SetMaxDocsOpen(1);

	m_mainFrame = new MainFrame(m_docManager, wxSize(800, 600));
	m_mainFrame->Maximize(true);
	m_mainFrame->Show(true);
	m_mainFrame->Center();
	SetTopWindow(m_mainFrame);

	return true;
}

int Application::OnExit()
{
	wxDELETE(m_docManager);
	wxDELETE(langFile);
	wxDELETE(appSettingsFile);
	return 0;
}

void Application::loadLanguage(const Lang lang, bool updateText)
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

	if (updateText) {
		m_mainFrame->UpdateMainMenu();
	}
}

wxString Application::getText(wxString groupId, wxString textId,
	wxString defValue) const
{
	if (nullptr == langFile) {
		return defValue;
	}

	langFile->SetPath("/" + groupId);
	return langFile->Read(textId, defValue);
}

void Application::loadSettingsFile()
{
	wxString fullLangFileName =
		wxPathOnly(wxStandardPaths::Get().GetExecutablePath()) +
		APP_SETTINGS_FILE;

	if (wxFileExists(fullLangFileName)) {
		appSettingsFile = new wxFileConfig(wxEmptyString,
			wxEmptyString, fullLangFileName);
	}
}

Lang Application::getLang()
{
	if (nullptr == appSettingsFile) {
		return Lang::ENG;
	}

	appSettingsFile->SetPath(wxString("/") + GENERAL_SECTION);
	wxString langName = appSettingsFile->Read(LANG_KEY, LANG_DEF_VALUE);

	if ("ENG" == langName) {
		return Lang::ENG;
	}
	else if ("UKR" == langName) {
		return Lang::UKR;
	}
	else if ("RUS" == langName) {
		return Lang::RUS;
	}
	else {
		return Lang::ENG;
	}
}
