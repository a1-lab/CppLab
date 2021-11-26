#include "wx/dcbuffer.h"
#include "BurningWidget.hpp"
#include "MainFrame.hpp"

int num[] = { 75, 150, 225, 300, 375, 450, 525, 600, 675 };
int asize = sizeof(num) / sizeof(num[1]);

BurningWidget::BurningWidget(wxPanel* parent, int id) : 
	wxPanel(parent, id, wxDefaultPosition, wxSize(-1, 30), wxSUNKEN_BORDER), 
	m_parent{parent}
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);
	Connect(wxEVT_PAINT, wxPaintEventHandler(BurningWidget::OnPaint));
	Connect(wxEVT_SIZE, wxSizeEventHandler(BurningWidget::OnSize));
}

void BurningWidget::OnSize(wxSizeEvent& event)
{
    Refresh();
}

void BurningWidget::OnPaint(wxPaintEvent& event)
{
    wxFont font(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
        wxFONTWEIGHT_NORMAL, false, wxT("Courier 10 Pitch"));

    //wxPaintDC dc(this);

    wxAutoBufferedPaintDC dc(this);
    dc.SetBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_FRAMEBK));

    //TODO: get client width and heigt
    dc.DrawRectangle(0, 0, 500, 50);

    dc.SetFont(font);
    wxSize size = GetSize();
    int width = size.GetWidth();

    MainFrame* app = (MainFrame*)m_parent->GetParent();

    int cur_width = app->GetCurWidth();

    int step = (int)round(width / 10.0);


    int till = (int)((width / 750.0) * cur_width);
    int full = (int)((width / 750.0) * 700);


    if (cur_width >= 700) {

        dc.SetPen(wxPen(wxColour(255, 255, 184)));
        dc.SetBrush(wxBrush(wxColour(255, 255, 184)));
        dc.DrawRectangle(0, 0, full, 30);
        dc.SetPen(wxPen(wxColour(255, 175, 175)));
        dc.SetBrush(wxBrush(wxColour(255, 175, 175)));
        dc.DrawRectangle(full, 0, till - full, 30);

    }
    else {

        dc.SetPen(wxPen(wxColour(255, 255, 184)));
        dc.SetBrush(wxBrush(wxColour(255, 255, 184)));
        dc.DrawRectangle(0, 0, till, 30);

    }

    dc.SetPen(wxPen(wxColour(90, 80, 60)));
    for (int i = 1; i <= asize; i++) {

        dc.DrawLine(i * step, 0, i * step, 6);
        wxSize size = dc.GetTextExtent(wxString::Format(wxT("%d"), num[i - 1]));
        dc.DrawText(wxString::Format(wxT("%d"), num[i - 1]),
            i * step - size.GetWidth() / 2, 8);
    }
}
