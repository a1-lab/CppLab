#include "View.hpp"
#include "MainFrame.hpp"

IMPLEMENT_DYNAMIC_CLASS(View, wxView)

View::View()
{
	wxLogMessage(wxT("View::View()"));
	SetFrame(wxTheApp->GetTopWindow());
}

wxTextCtrl* View::GetEditor()
{
	do
	{
		MainFrame* frame = wxDynamicCast(GetFrame(), MainFrame);
		if (!frame) {
			break;
		}

		return frame->GetEditor();
	} while (false);

	return nullptr;
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
