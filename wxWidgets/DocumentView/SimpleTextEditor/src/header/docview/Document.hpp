#pragma once
#include "wx/wx.h"
#include "wx/docview.h"

class Document : public wxDocument {
public:
	Document();

	virtual bool OnSaveDocument(const wxString& filename);
	virtual bool OnOpenDocument(const wxString& filename);
	virtual bool IsModified(void) const;
	virtual void Modify(bool mod);

	DECLARE_DYNAMIC_CLASS(Document);
};
