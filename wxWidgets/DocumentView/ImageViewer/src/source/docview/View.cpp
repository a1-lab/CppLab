#include "View.hpp"
#include "MainFrame.hpp"

IMPLEMENT_DYNAMIC_CLASS(View, wxView)

View::View()
{
	m_Canvas = nullptr;

	MainFrame* mainFrame = wxDynamicCast(wxTheApp->GetTopWindow(), MainFrame);

	if (mainFrame)
	{
		SetFrame(mainFrame);
		m_Canvas = mainFrame->m_Canvas;
		m_Canvas->SetView(this);
	}
	else
	{
		wxFAIL_MSG(_("Can't retrieve a pointer to main window"));
	}
}

void View::OnDraw(wxDC* dc)
{
	wxLogMessage(wxT("View::OnDraw()"));
}

void View::OnUpdate(wxView* sender, wxObject* hint)
{
	wxLogMessage(wxT("View::onUpdate()"));
}

bool View::OnClose(bool deleteWindow)
{
	wxLogMessage(wxT("View::OnClose"));
	if (!GetDocument()->Close())
	{
		return false;
	}

	SetFrame(NULL);
	Activate(false);
	return true;
}

void View::ReCreateScaledBitmap()
{
}