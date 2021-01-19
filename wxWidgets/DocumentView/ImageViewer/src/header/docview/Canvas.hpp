#pragma once
#include "wx/wx.h"

#define CanvasStyle wxNO_BORDER|wxHSCROLL|wxVSCROLL|wxTAB_TRAVERSAL
#define CanvasName wxT("Canvas")

class View;
class Canvas : public wxWindow {
public:
	Canvas() = default;

	Canvas(wxWindow* parent,
		wxWindowID id = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = CanvasStyle,
		const wxString& name = CanvasName);

	bool CreateCanvas(wxWindow* parent,
		wxWindowID id = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = CanvasStyle,
		const wxString& name = CanvasName);

	View* GetView();
	void SetView(View* view);
	const wxRect& GetSelection() const;
	wxSize GetCurrentSize() const;

	wxPoint GetScrollPosition() const;
	void Scroll(wxPoint);
	void Scroll(int x, int y);

	void FixViewOffset();
	void AdjustScrollBars();

	wxRect GetImageDisplayRect(const wxPoint& scrollPosition) const;
	wxPoint ClientToImage(const wxPoint& position) const;
	bool AutoScroll(wxPoint currentPosition, wxPoint scrollPosition);
private:
	static inline wxSize ScrollingIncrement;
	wxPoint m_TR;
	wxPoint m_BL;
	wxRect m_Selection;

	View* m_View;

	DECLARE_DYNAMIC_CLASS(Canvas)

	DECLARE_EVENT_TABLE()
	void OnScrollLineUp(wxScrollWinEvent& event);
	void OnScrollLineDown(wxScrollWinEvent& event);
	void OnScrollPageUp(wxScrollWinEvent& event);
	void OnScrollPageDown(wxScrollWinEvent& event);
	void OnScrollThumbtrack(wxScrollWinEvent& event);
	void OnScrollThumbRelease(wxScrollWinEvent& event);
	void OnPaintCanvas(wxPaintEvent& event);
	void OnIdle(wxIdleEvent& event);
	void OnEraseBackground(wxEraseEvent& event);
	void OnLeftDown(wxMouseEvent& event);
	void OnLeftUp(wxMouseEvent& event);
	void OnMotion(wxMouseEvent& event);
};