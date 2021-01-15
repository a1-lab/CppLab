#include "Document.hpp"
#include "wx/log.h"

IMPLEMENT_DYNAMIC_CLASS(Document, wxDocument)

Document::Document()
{
	wxLogMessage(wxT("DocViewTestDocument::DocViewTestDocument"));
}

wxInputStream& Document::LoadObject(wxInputStream& stream)
{
	m_Image.LoadFile(stream, wxBITMAP_TYPE_ANY);
	return stream;
}

wxImage& Document::GetImage()
{
	return m_Image;
}