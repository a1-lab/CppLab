#include "DoodleCanvas.hpp"
#include "View.hpp"

BEGIN_EVENT_TABLE(DoodleCanvas, wxScrolledWindow)
END_EVENT_TABLE()

DoodleCanvas::DoodleCanvas(wxWindow* parent, const wxPoint& pos,
	const wxSize& size, const long style) :
	wxScrolledWindow(parent, wxID_ANY, pos, size, style)
{
}

void DoodleCanvas::OnDraw(wxDC& dc)
{
	if (m_view) {
		m_view->OnDraw(&dc);
	}
}

void DoodleCanvas::OnMouseEvent(wxMouseEvent& event)
{
}