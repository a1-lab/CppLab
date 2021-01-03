#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class Document : public wxDocument {
public:
	Document();
private:
	DECLARE_DYNAMIC_CLASS(Document);
};
