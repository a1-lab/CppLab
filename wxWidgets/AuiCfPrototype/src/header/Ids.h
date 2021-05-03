#pragma once
#include "wx/wx.h"

// Scoped enumerations should be used
// Do not change to enum class see toolbar->AddTool
enum Id
{
	ID_NEW = wxID_HIGHEST + 1,
	ID_OPEN,
	ID_SAVE,
	ID_POINTER,
	ID_ADD,
	ID_DELETE,
	ID_EFFECTS,
	ID_PLAY,
	ID_WRITE_PROGRAM,
	ID_WIDTH,
	ID_HEIGHT,
	ID_SCALE
};