#pragma once
#include "wx/wx.h"
#include "wx/docview.h"
#include "wx/fileconf.h"
#include "MainFrame.hpp"
//wxmemdbg must be the last one in include list
#include "wxmemdbg.h"

#define MAIN_FRAME_TITLE wxT("AUI CF Prototype Application")

enum class Lang { NONE, ENG, RUS, UKR };

class Application : public wxApp {
public:
	bool OnInit() override;
	int OnExit() override;
	void loadLanguage(const Lang lang, bool updateText = false);
	wxString getText(wxString groupId, wxString textId,
		wxString defValue) const;
	void loadSettingsFile();
private:
	MainFrame* m_mainFrame = nullptr;
	wxDocManager* m_docManager = nullptr;
	wxFileConfig* langFile = nullptr;
	Lang currentLanguage = Lang::NONE;
	wxFileConfig* appSettingsFile = nullptr;

	Lang getLang();
};

DECLARE_APP(Application)