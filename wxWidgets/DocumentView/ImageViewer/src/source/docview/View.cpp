#include "Application.hpp"
#include "MainFrame.hpp"
#include "View.hpp"
#include "Document.hpp"
#include "Canvas.hpp"

IMPLEMENT_DYNAMIC_CLASS(View, wxView)

View::View()
{
	MainFrame* mainFrame = wxDynamicCast(wxGetApp().GetTopWindow(),
		MainFrame);

	if (mainFrame)
	{
		SetFrame(mainFrame);
		m_Canvas = mainFrame->GetCanvas();
		m_Canvas->SetView(this);
	}
	else
	{
		wxFAIL_MSG(_("Can't retrieve a pointer to main window"));
	}
}

void View::OnDraw(wxDC* dc)
{
	if (m_ScaledBitmap.IsOk()) {
		dc->DrawBitmap(m_ScaledBitmap,
			m_ViewOffset.GetWidth(), m_ViewOffset.GetHeight());
	}
}

void View::OnUpdate(wxView* sender, wxObject* hint)
{
	RecreateScaledBitmap();
	if (m_Canvas) {
		m_Canvas->AdjustScrollBars();
		m_Canvas->Refresh();
	}
}

bool View::OnClose(bool deleteWindow)
{
	if (!GetDocument()->Close())
	{
		return false;
	}

	if (m_Canvas) {
		m_Canvas->ClearBackground();
		m_Canvas->SetView(nullptr);
		m_Canvas = nullptr;
	}

	wxFrame* frame = wxDynamicCast(GetFrame(), wxFrame);
	if (frame) {
		frame->SetTitle(MAIN_FRAME_TITLE);
	}

	SetFrame(nullptr);
	Activate(false);
	return true;
}

wxBitmap& View::GetScaledBitmap()
{
	return m_ScaledBitmap;
}

const wxSize& View::GetViewOffset() const
{
	return m_ViewOffset;
}

void View::SetViewOffset(const wxSize& value)
{
	m_ViewOffset = value;
}

void View::RecreateScaledBitmap()
{
	Document* document = wxDynamicCast(GetDocument(), Document);
	if (document) {
		int width = document->GetImage().GetWidth();
		int height = document->GetImage().GetHeight();
		wxSize scaledSize(width * m_Scale, height * m_Scale);

		m_ScaledBitmap = wxBitmap(document->GetImage().
			Scale(scaledSize.GetWidth(), scaledSize.GetHeight()));
	}
	else {
		m_ScaledBitmap = wxNullBitmap;
	}
}