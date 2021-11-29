#include "DesignerScrolled.hpp"

vgl::DesignerScrolled::DesignerScrolled(wxWindow* parent, wxSizer* sizer)
{
	m_scrolledCanvas = new wxScrolledCanvas(parent, wxID_ANY);
	sizer->Add(m_scrolledCanvas, 1, wxGROW | wxALL, 0);

	m_desiner = new Designer(m_scrolledCanvas);
}

void vgl::DesignerScrolled::SetSize(int width, int height)
{
	m_desiner->SetSize(width, height);
    m_scrolledCanvas->SetScrollbars(SCROLL_STEP, SCROLL_STEP, 
		width / SCROLL_STEP, height / SCROLL_STEP);
}
