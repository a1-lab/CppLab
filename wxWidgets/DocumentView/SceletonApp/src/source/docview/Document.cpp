#include "Document.hpp"
#include "wx/log.h"

IMPLEMENT_DYNAMIC_CLASS(Document, wxDocument)

Document::Document()
{
	wxLogMessage(wxT("DocViewTestDocument::DocViewTestDocument"));
}
