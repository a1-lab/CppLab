#include "wx/imagpng.h"
#include "wx/log.h"
#include "Document.hpp"

IMPLEMENT_DYNAMIC_CLASS(Document, wxDocument)

Document::Document()
{
	wxImage::AddHandler(new wxPNGHandler());
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