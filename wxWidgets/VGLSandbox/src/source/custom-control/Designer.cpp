#include "Designer.hpp"

vgl::Designer::Designer(wxWindow* parent, int id, 
    int minWidth, int minHeight) : wxPanel(parent, id)
{
    wxSize size = wxSize(minWidth, minHeight);
    SetMinSize(size);
    SetSize(size);

	Connect(wxEVT_PAINT, wxPaintEventHandler(Designer::OnPaint));
    Connect(wxEVT_SIZE, wxSizeEventHandler(Designer::OnSize));
}

void vgl::Designer::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    //wxAutoBufferedPaintDC dc(this);
    dc.SetBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_FRAMEBK));

    wxSize size = this->GetSize();
    for (int i = 1; i < 7; i++) {
        dc.DrawRectangle(10*i, 10 * i, size.x - 2 * 10 * i, size.y - 2 * 10 * i);
    }

    dc.SetBrush(*wxRED_BRUSH);
    dc.DrawRectangle(10 * 8, 10 * 8, size.x - 2 * 10 * 8, size.y - 2 * 10 * 8);

}

void vgl::Designer::OnSize(wxSizeEvent& event)
{
    Refresh();
}
