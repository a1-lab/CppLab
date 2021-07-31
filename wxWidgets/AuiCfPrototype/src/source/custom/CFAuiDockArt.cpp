#include "CFAuiDockArt.hpp"
#include "wx/aui/auibook.h"

void CFAuiDockArt::DrawBorder(wxDC& dc, wxWindow* window, const wxRect& _rect, wxAuiPaneInfo& pane)
{
    dc.SetPen(m_borderPen);
    dc.SetBrush(*wxTRANSPARENT_BRUSH);

    wxRect rect = _rect;
    int i, border_width = GetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE);

    if (pane.IsToolbar())
    {
        for (i = 0; i < border_width; ++i)
        {
            dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE)));
            dc.DrawLine(rect.x, rect.y, rect.x + rect.width, rect.y);
            dc.DrawLine(rect.x, rect.y, rect.x, rect.y + rect.height);
            dc.DrawLine(rect.x, rect.y + rect.height - 1,
                rect.x + rect.width, rect.y + rect.height - 1);
            dc.DrawLine(rect.x + rect.width - 1, rect.y,
                rect.x + rect.width - 1, rect.y + rect.height);
            rect.Deflate(1);
        }
    }
    else
    {
        // notebooks draw the border themselves, so they can use native rendering (e.g. tabartgtk)
        wxAuiTabArt* art = 0;
        wxAuiNotebook* nb = wxDynamicCast(window, wxAuiNotebook);
        if (nb)
            art = nb->GetArtProvider();

        if (art)
            art->DrawBorder(dc, window, rect);
        else
        {
            for (i = 0; i < border_width; ++i)
            {
                dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);
                rect.Deflate(1);
            }
        }
    }
}


void CFAuiDockArt::DrawBackground(wxDC& dc, wxWindow* window, int orientation, const wxRect& rect)
{
    dc.SetPen(*wxTRANSPARENT_PEN);
#ifdef __WXMAC__
    // we have to clear first, otherwise we are drawing a light striped pattern
    // over an already darker striped background
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);
#endif
    dc.SetBrush(wxBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE)));
    dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);
}

void CFAuiDockArt::DrawSash(wxDC& dc, wxWindow* window, int orientation, const wxRect& rect)
{
#if defined( __WXMAC__ ) && wxOSX_USE_COCOA_OR_CARBON
    wxUnusedVar(window);
    wxUnusedVar(orientation);

    if (wxPlatformInfo::Get().CheckOSVersion(10, 14) && wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW).Red() < 128)
    {
        dc.SetPen(*wxTRANSPARENT_PEN);
        dc.SetBrush(m_sashBrush);
        dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);
    }
    else
    {
        HIRect splitterRect = CGRectMake(rect.x, rect.y, rect.width, rect.height);
        CGContextRef cgContext;
        wxGCDCImpl* impl = (wxGCDCImpl*)dc.GetImpl();
        cgContext = (CGContextRef)impl->GetGraphicsContext()->GetNativeContext();

        HIThemeSplitterDrawInfo drawInfo;
        drawInfo.version = 0;
        drawInfo.state = kThemeStateActive;
        drawInfo.adornment = kHIThemeSplitterAdornmentNone;
        HIThemeDrawPaneSplitter(&splitterRect, &drawInfo, cgContext, kHIThemeOrientationNormal);
    }

#elif defined(__WXGTK__)
    // clear out the rectangle first
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.SetBrush(m_sashBrush);
    dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);

#if 0
    GdkRectangle gdk_rect;
    if (orientation == wxVERTICAL)
    {
        gdk_rect.x = rect.x;
        gdk_rect.y = rect.y;
        gdk_rect.width = m_sashSize;
        gdk_rect.height = rect.height;
    }
    else
    {
        gdk_rect.x = rect.x;
        gdk_rect.y = rect.y;
        gdk_rect.width = rect.width;
        gdk_rect.height = m_sashSize;
    }
#endif

    if (!window) return;
    if (!window->m_wxwindow) return;
    if (!gtk_widget_is_drawable(window->m_wxwindow)) return;

#ifdef __WXGTK3__
    cairo_t* cr = static_cast<cairo_t*>(dc.GetGraphicsContext()->GetNativeContext());
    // invert orientation for widget (horizontal GtkPaned has a vertical splitter)
    wxOrientation orient = orientation == wxVERTICAL ? wxHORIZONTAL : wxVERTICAL;
    GtkWidget* widget = wxGTKPrivate::GetSplitterWidget(orient);
    GtkStyleContext* sc = gtk_widget_get_style_context(widget);
    gtk_style_context_save(sc);

    gtk_style_context_add_class(sc, GTK_STYLE_CLASS_PANE_SEPARATOR);
    gtk_render_handle(sc, cr, rect.x, rect.y, rect.width, rect.height);

    gtk_style_context_restore(sc);
#else
    gtk_paint_handle
    (
        gtk_widget_get_style(window->m_wxwindow),
        window->GTKGetDrawingWindow(),
        // flags & wxCONTROL_CURRENT ? GTK_STATE_PRELIGHT : GTK_STATE_NORMAL,
        GTK_STATE_NORMAL,
        GTK_SHADOW_NONE,
        NULL /* no clipping */,
        window->m_wxwindow,
        "paned",
        rect.x,
        rect.y,
        rect.width,
        rect.height,
        (orientation == wxVERTICAL) ? GTK_ORIENTATION_VERTICAL : GTK_ORIENTATION_HORIZONTAL
    );
#endif // !__WXGTK3__

#else
    wxUnusedVar(window);
    wxUnusedVar(orientation);
    dc.SetPen(*wxTRANSPARENT_PEN);
    //dc.SetBrush(m_sashBrush);
    dc.SetBrush(wxBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE)));
    dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);
#endif
}


