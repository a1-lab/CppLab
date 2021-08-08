#include "artprovider/CFArtProvider.hpp"
#include "CFArtId.h"
#include "new.xpm"
#include "open.xpm"
#include "save.xpm"
#include "pointer.xpm"
#include "add.xpm"
#include "delete.xpm"
#include "effects.xpm"
#include "play.xpm"
#include "write_program.xpm"

wxBitmap CFArtProvider::CreateBitmap(const wxArtID& id, const wxArtClient& client, const wxSize& size)
{
	if (id == ART_NEW_PROJECT) {
		return wxBitmap(new_xpm);
	}
	else if (id == ART_OPEN_PROJECT) {
		return wxBitmap(open_xpm);
	}
	else if (id == ART_SAVE_PROJECT) {
		return wxBitmap(save_xpm);
	}
	else if (id == ART_POINTER) {
		return wxBitmap(pointer_xpm);
	}
	else if (id == ART_ADD) {
		return wxBitmap(add_xpm);
	}
	else if (id == ART_DELETE) {
		return wxBitmap(delete_xpm);
	}
	else if (id == ART_EFFECTS) {
		return wxBitmap(effects_xpm);
	}
	else if (id == ART_PLAY) {
		return wxBitmap(play_xpm);
	}
	else if (id == ART_WRITE) {
		return wxBitmap(write_xpm);
	}
	else {
		return wxBitmap(new_xpm);
	}
}
