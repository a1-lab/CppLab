#include "CFArtProvider.hpp"
#include "new.xpm"

wxBitmap CFArtProvider::CreateBitmap(const wxArtID& id, const wxArtClient& client, const wxSize& size)
{
	return wxBitmap(new_xpm);
}
