#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class Document : public wxDocument {
public:
	Document();
	wxInputStream& LoadObject(wxInputStream& stream) override;
	wxImage& GetImage();

	DECLARE_DYNAMIC_CLASS(Document);
private:
	wxImage m_Image;
};