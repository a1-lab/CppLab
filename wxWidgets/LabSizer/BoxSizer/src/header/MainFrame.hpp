#pragma once
#include "wx/wx.h"
#include "wx/splitter.h"

class MainFrame : public wxFrame
{
public:
	explicit MainFrame(const wxString& title);
private:
	wxSplitterWindow* m_splitterWindow = nullptr;
};