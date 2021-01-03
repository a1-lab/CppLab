#include "View.hpp"

IMPLEMENT_DYNAMIC_CLASS(View, wxView)

View::View()
{
    wxLogMessage(wxT("View::View()")); 
    SetFrame(wxTheApp->GetTopWindow());
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
