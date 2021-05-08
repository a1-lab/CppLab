#include "CFArtProvider.hpp"
#include "CFArtId.h"
#include "new.xpm"

wxBitmap CFArtProvider::CreateBitmap(const wxArtID& id, const wxArtClient& client, const wxSize& size)
{
	if (id == ART_NEW_PROJECT) {
		return wxBitmap(new_xpm);
	}
	else if (id == ART_OPEN_PROJECT) {
		return wxBitmap(new_xpm);
	}
	else {
		return wxBitmap(new_xpm);
	}
}
