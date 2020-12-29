#pragma once
#include "wx/artprov.h"

class CustomArtProvider : public wxArtProvider {
protected:
	wxBitmap CreateBitmap(const wxArtID&, 
		const wxArtClient&, const wxSize&) override;
};