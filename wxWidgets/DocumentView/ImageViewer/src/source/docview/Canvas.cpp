#include "wx/dcbuffer.h"
#include "Canvas.hpp"
#include "View.hpp"

IMPLEMENT_DYNAMIC_CLASS(Canvas, wxWindow)

BEGIN_EVENT_TABLE(Canvas, wxWindow)
/**/EVT_SCROLLWIN_LINEUP(Canvas::OnScrollLineUp)
/**/EVT_SCROLLWIN_LINEDOWN(Canvas::OnScrollLineDown)
/**/EVT_SCROLLWIN_PAGEUP(Canvas::OnScrollPageUp)
/**/EVT_SCROLLWIN_PAGEDOWN(Canvas::OnScrollPageDown)
/**/EVT_SCROLLWIN_THUMBTRACK(Canvas::OnScrollThumbtrack)
/**/EVT_SCROLLWIN_THUMBRELEASE(Canvas::OnScrollThumbRelease)
/**/EVT_PAINT(Canvas::OnPaintCanvas)
/**/EVT_IDLE(Canvas::OnIdle)
/**/EVT_ERASE_BACKGROUND(Canvas::OnEraseBackground)
/**/EVT_LEFT_DOWN(Canvas::OnLeftDown)
/**/EVT_LEFT_UP(Canvas::OnLeftUp)
/**/EVT_MOTION(Canvas::OnMotion)
END_EVENT_TABLE();

Canvas::Canvas(wxWindow* parent, wxWindowID id,
	const wxPoint& pos, const wxSize& size,
	long style, const wxString& name)
{
	CreateCanvas(parent, id, pos, size, style, name);
}

bool Canvas::CreateCanvas(wxWindow* parent, wxWindowID id,
	const wxPoint& pos, const wxSize& size, long style, const wxString& name)
{
	bool res = wxWindow::Create(parent, id, pos, size, style, name);
	return res;
}

View* Canvas::GetView()
{
	return m_View;
}

void Canvas::SetView(View* view)
{
	m_View = view;
}

const wxRect& Canvas::GetSelection() const
{
	return m_Selection;
}

wxSize Canvas::GetCurrentSize() const
{
	if (!m_View)
	{
		return wxSize(0, 0);
	}
	return wxSize(m_View->GetScaledBitmap().GetWidth(), m_View->GetScaledBitmap().GetHeight());
}

wxPoint Canvas::GetScrollPosition() const
{
	return wxPoint(GetScrollPos(wxHORIZONTAL), GetScrollPos(wxVERTICAL));
}

void Canvas::Scroll(wxPoint pt)
{
	if (pt.x >= 0) {
		SetScrollPos(wxHORIZONTAL, pt.x);
	}

	if (pt.y >= 0) {
		SetScrollPos(wxVERTICAL, pt.y);
	}

	Refresh();
}

void Canvas::Scroll(int x, int y)
{
	Scroll(wxPoint(x, y));
}

void Canvas::FixViewOffset()
{
	if (m_View) {
		wxPoint pt = GetScrollPosition();
		wxRect displayRect = GetImageDisplayRect(pt);
		wxSize offset(displayRect.GetPosition().x, displayRect.GetPosition().y);
		m_View->SetViewOffset(offset);
	}
}

void Canvas::AdjustScrollBars()
{
	// image sampled size
	wxSize imageSize = GetCurrentSize();

	// old scroll position
	wxPoint pt = GetScrollPosition();
	SetScrollbar(wxHORIZONTAL, 0, GetClientSize().x, imageSize.x);
	SetScrollbar(wxVERTICAL, 0, GetClientSize().y, imageSize.y);
	Scroll(pt.x, pt.y);
}

wxRect Canvas::GetImageDisplayRect(const wxPoint& scrollPosition) const
{
	wxSize currentSize = GetCurrentSize();

	// calculate actual image position if it is centered
	wxPoint ptTest(
		(GetClientSize().x - currentSize.GetWidth()) <= 0 ?
		-scrollPosition.x :
		static_cast<int>(static_cast<float>(GetClientSize().GetWidth() -
			currentSize.GetWidth()) * 0.5F),

		(GetClientSize().y - currentSize.GetHeight()) <= 0 ?
		-scrollPosition.y :
		static_cast<int>(static_cast<float>(GetClientSize().GetHeight() -
			currentSize.GetHeight()) * 0.5F));

	// calculate actual image display rectangle if centered
	return wxRect(ptTest, currentSize);
}

wxPoint Canvas::ClientToImage(const wxPoint& position) const
{
	wxPoint scrollPos = GetScrollPosition();
	wxRect imageRect = GetImageDisplayRect(scrollPos);
	return wxPoint(position.x - imageRect.GetLeft(),
		position.y - imageRect.GetTop());
}

bool Canvas::AutoScroll(wxPoint currentPosition, wxPoint scrollPosition)
{
	bool res = false;

	// If mouse is captured set rectangle coordinates if inside 
	// the image and auto-scroll if possible  get image display rectangle
	wxRect displayRect = GetImageDisplayRect(scrollPosition);

	wxSize oldSelection(m_TR.x - m_BL.x, m_TR.y - m_BL.y);

	// check if the current drag position is inside the image - do not allow to draw rectangle out of the image
	m_TR.x =
		wxMin(wxMax(currentPosition.x, displayRect.GetLeft()), displayRect.GetRight());
	m_TR.y =
		wxMin(wxMax(currentPosition.y, displayRect.GetTop()), displayRect.GetBottom());

	// Check current drag position and update scroll regularly
	if (currentPosition.x <= 0)
	{
		Scroll(wxMax(scrollPosition.x - Canvas::ScrollingIncrement.GetWidth(), 0), -1);
		m_BL.x += (scrollPosition.x - GetScrollPosition().x);
		res = true;
	}

	if (currentPosition.y <= 0)
	{
		Scroll(-1, wxMax(scrollPosition.y - Canvas::ScrollingIncrement.GetHeight(), 0));
		m_BL.y += (scrollPosition.y - GetScrollPosition().y);
		res = true;
	}

	if (currentPosition.x >= GetClientSize().GetWidth())
	{
		Scroll(scrollPosition.x + Canvas::ScrollingIncrement.GetWidth(), -1);
		m_BL.x -= (GetScrollPosition().x - scrollPosition.x);
		res = true;
	}

	if (currentPosition.y >= GetClientSize().y)
	{
		Scroll(-1, scrollPosition.y + Canvas::ScrollingIncrement.GetHeight());
		m_BL.y -= (GetScrollPosition().y - scrollPosition.y);
		res = true;
	}

	m_Selection = wxRect(wxMin(m_TR.x, m_BL.x), wxMin(m_TR.y, m_BL.y),
		abs(m_TR.x - m_BL.x), abs(m_TR.y - m_BL.y));

	return res;
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnScrollLineUp(wxScrollWinEvent& event)
{
	int increment = (event.GetOrientation() == wxHORIZONTAL ?
		Canvas::ScrollingIncrement.GetWidth() :
		Canvas::ScrollingIncrement.GetHeight());

	SetScrollPos(event.GetOrientation(),
		GetScrollPos(event.GetOrientation()) - increment);

	FixViewOffset();
	Refresh();
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnScrollLineDown(wxScrollWinEvent& event)
{
	int increment = (event.GetOrientation() == wxHORIZONTAL ?
		Canvas::ScrollingIncrement.GetWidth() :
		Canvas::ScrollingIncrement.GetHeight());

	SetScrollPos(event.GetOrientation(), GetScrollPos(event.GetOrientation()) + increment);
	FixViewOffset();
	Refresh();
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnScrollPageUp(wxScrollWinEvent& event)
{
	SetScrollPos(event.GetOrientation(),
		GetScrollPos(event.GetOrientation()) -
		GetScrollThumb(event.GetOrientation()));

	FixViewOffset();
	Refresh();
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnScrollPageDown(wxScrollWinEvent& event)
{
	SetScrollPos(event.GetOrientation(),
		GetScrollPos(event.GetOrientation()) +
		GetScrollThumb(event.GetOrientation()));

	FixViewOffset();
	Refresh();
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnScrollThumbtrack(wxScrollWinEvent& event)
{
	SetScrollPos(event.GetOrientation(), event.GetPosition());

	FixViewOffset();
	Refresh();
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnScrollThumbRelease(wxScrollWinEvent& event)
{
	FixViewOffset();
	Refresh();
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnPaintCanvas(wxPaintEvent& event)
{
	wxBufferedPaintDC dc(this);

	dc.SetBackground(wxBrush(GetBackgroundColour()));
	dc.Clear();
	if (m_View)
	{
		m_View->OnDraw(&dc);
		if (HasCapture() && !m_Selection.IsEmpty())
		{
			dc.SetBrush(*wxTRANSPARENT_BRUSH);
			dc.SetLogicalFunction(wxXOR);
			dc.SetPen(wxPen(*wxWHITE, 3));
			dc.DrawRoundedRectangle(m_Selection.GetPosition(), m_Selection.GetSize(), 1.0f);
		}
	}
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnIdle(wxIdleEvent& event)
{
	do
	{
		if (!HasCapture()) break;

		// get scroll position
		wxPoint scrollPos = GetScrollPosition();
		// get mouse in client coordinates
		wxPoint currentPos = ScreenToClient(wxGetMousePosition());

		// auto scroll
		// check current drag position and update scroll regularly
		if (AutoScroll(currentPos, scrollPos))
		{
			event.RequestMore();
		}
		FixViewOffset();
	} while (false);
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnEraseBackground(wxEraseEvent& event)
{
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnLeftDown(wxMouseEvent& event)
{
	SetFocus();
	wxRect imageRect = GetImageDisplayRect(GetScrollPosition());
	do
	{
		if (!m_View) {
			break;
		}

		wxPoint cursorPosOnImage = ClientToImage(event.GetPosition());

		if (!imageRect.Contains(event.GetPosition())) {
			break;
		}

		CaptureMouse();
		Refresh();

		m_TR = m_BL = event.GetPosition();
		m_Selection.SetPosition(event.GetPosition());
		m_Selection.SetSize(wxSize(0, 0));
	} while (false);
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnLeftUp(wxMouseEvent& event)
{
	if (HasCapture())
	{
		ReleaseMouse();
		Refresh();

		wxMessageBox(wxString::Format(
			_("Selection rectangle\r\nScreen coordinates:\r\nPosition=(%i,%i);\r\nSize=(%i,%i)\r\nLogical coordinates:\r\nPosition=(%i,%i);\r\nSize=(%i,%i)"),
			m_Selection.GetLeft(), m_Selection.GetTop(),
			m_Selection.GetWidth(), m_Selection.GetHeight(),
			ClientToImage(m_Selection.GetTopLeft()).x,
			ClientToImage(m_Selection.GetTopLeft()).y,
			m_Selection.GetWidth(), m_Selection.GetHeight()));

		m_TR = m_BL = wxPoint(0, 0);
		m_Selection.SetPosition(m_TR);
		m_Selection.SetSize(wxSize(0, 0));
	}
}

//no Sonar rule due to wxWidgets restriction for function signature
void Canvas::OnMotion(wxMouseEvent& event)
{
	if (HasCapture())
	{
		// current point
		wxPoint currentPos = event.GetPosition();
		// get scroll position
		wxPoint scrollPos = GetScrollPosition();

		AutoScroll(currentPos, scrollPos);
		FixViewOffset();
		Refresh();
	}
}
