#include "Canvas.hpp"

IMPLEMENT_DYNAMIC_CLASS(Canvas, wxWindow)

BEGIN_EVENT_TABLE(Canvas, wxWindow)
END_EVENT_TABLE();

Canvas::Canvas()
{
	Init();
}

Canvas::Canvas(wxWindow* parent, wxWindowID id,
	const wxPoint& pos, const wxSize& size,
	long style, const wxString& name)
{
	Init();
	Create(parent, id, pos, size, style, name);
}

bool Canvas::Create(wxWindow* parent, wxWindowID id,
	const wxPoint& pos, const wxSize& size, long style, const wxString& name)
{
	bool res = wxWindow::Create(parent, id, pos, size, style, name);
	if (res) {
	}

	return res;
}

void Canvas::Init()
{
	m_View = nullptr;
}