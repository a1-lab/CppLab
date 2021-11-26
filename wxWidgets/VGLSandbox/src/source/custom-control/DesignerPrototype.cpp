#include "DesignerPrototype.hpp"

DesignerPrototype::DesignerPrototype(wxWindow* parent, int id) :
	wxPanel(parent, id, wxDefaultPosition, wxSize(600, 300), wxNO_BORDER)
{
    SetMinSize(wxSize(640, 480));
	Connect(wxEVT_PAINT, wxPaintEventHandler(DesignerPrototype::OnPaint));
    Connect(wxEVT_SIZE, wxSizeEventHandler(DesignerPrototype::OnSize));
}

void DesignerPrototype::OnPaint(wxPaintEvent& event) 
{
    wxPaintDC dc(this);

    //wxAutoBufferedPaintDC dc(this);
    dc.SetBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_FRAMEBK));

    wxSize size = this->GetSize();
    dc.DrawRectangle(10, 10, size.x - 2 * 10, size.y - 2 * 10);
}

void DesignerPrototype::OnSize(wxSizeEvent& event)
{
    Refresh();
}
