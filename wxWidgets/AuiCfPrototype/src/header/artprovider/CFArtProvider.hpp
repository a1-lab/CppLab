#pragma once
#include "wx/artprov.h"

class CFArtProvider : public wxArtProvider {
	virtual wxBitmap CreateBitmap(const wxArtID& id,
		const wxArtClient& client, const wxSize& size) override;
};