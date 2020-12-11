#include "Application.hpp"
#include "MainFrame.hpp"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	auto frame = new MainFrame(
		wxT("Hello wxWidgets Application"));

	frame->Show(true);

	return true;
}