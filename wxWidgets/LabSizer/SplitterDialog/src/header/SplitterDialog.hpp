#pragma once
#include "wx/wx.h"
#include "wx/splitter.h"

class wxSplitterWindow;

#define ID_SPLITTERDIALOG 16000
#define ID_SPLITTERDIALOG_SPLITTERWINDOW 16015
#define ID_SPLITTERDIALOG_LISTBOX 16016
#define ID_SPLITTERDIALOG_PANEL 16017
#define ID_SPLITTERDIALOG_TEXTCTRL 16018
#define ID_SPLITTERDIALOG_TEXTCTRL1 16019
#define SYMBOL_SPLITTERDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_SPLITTERDIALOG_TITLE _("SplitterDialog")
#define SYMBOL_SPLITTERDIALOG_IDNAME ID_SPLITTERDIALOG
#define SYMBOL_SPLITTERDIALOG_SIZE wxSize(450, 400)
#define SYMBOL_SPLITTERDIALOG_POSITION wxDefaultPosition


#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

class SplitterDialog : public wxDialog
{
	DECLARE_DYNAMIC_CLASS(SplitterDialog)
	DECLARE_EVENT_TABLE()

public:
	/// Constructors
	SplitterDialog();
	SplitterDialog(wxWindow* parent, wxWindowID id = SYMBOL_SPLITTERDIALOG_IDNAME, const wxString& caption = SYMBOL_SPLITTERDIALOG_TITLE, const wxPoint& pos = SYMBOL_SPLITTERDIALOG_POSITION, const wxSize& size = SYMBOL_SPLITTERDIALOG_SIZE, long style = SYMBOL_SPLITTERDIALOG_STYLE);

	/// Creation
	bool Create(wxWindow* parent, wxWindowID id = SYMBOL_SPLITTERDIALOG_IDNAME, const wxString& caption = SYMBOL_SPLITTERDIALOG_TITLE, const wxPoint& pos = SYMBOL_SPLITTERDIALOG_POSITION, const wxSize& size = SYMBOL_SPLITTERDIALOG_SIZE, long style = SYMBOL_SPLITTERDIALOG_STYLE);

	/// Creates the controls and sizers
	void CreateControls();

	wxBitmap GetBitmapResource(const wxString& name);

	/// Retrieves icon resources
	wxIcon GetIconResource(const wxString& name);
	////@end SplitterDialog member function declarations

	/// Should we show tooltips?
	static bool ShowToolTips();

	////@begin SplitterDialog member variables
	wxSplitterWindow* m_splitter;
	////@end SplitterDialog member variables
};
