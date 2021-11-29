// This is a designer which is placed on scrolled canvas
#pragma once

#include "wx/wx.h"
#include "Designer.hpp"

namespace vgl {
	class DesignerScrolled {
	public:
		explicit DesignerScrolled(wxWindow* parent, wxSizer* sizer);
		void SetSize(int width, int height);
	private:
		const static inline int SCROLL_STEP = 10;
		Designer* m_desiner = nullptr;
		wxScrolledCanvas* m_scrolledCanvas = nullptr;
	};
}
