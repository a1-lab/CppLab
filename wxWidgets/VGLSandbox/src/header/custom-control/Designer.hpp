#pragma once

#include "wx/wx.h"

namespace vgl {
	class Designer : public wxPanel {
	public:
		explicit Designer(wxWindow* parent, int id = wxID_ANY, 
			int minWidth = 300, int minHeight = 200);

		void OnPaint(wxPaintEvent& event);
		void OnSize(wxSizeEvent& event);
	private:
	};
}
