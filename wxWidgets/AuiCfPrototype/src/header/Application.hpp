#pragma once
#include "wx/wx.h"

class Application : public wxApp {
public:
	bool OnInit() override;
};

DECLARE_APP(Application)