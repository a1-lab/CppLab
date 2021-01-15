#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class Document : public wxDocument {
public:
	Document();
	wxInputStream& LoadObject(wxInputStream&);
	wxImage& GetImage();
private:
	DECLARE_DYNAMIC_CLASS(Document);
	wxImage m_Image;
};