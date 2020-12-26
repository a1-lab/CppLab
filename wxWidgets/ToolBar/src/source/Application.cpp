#include "../header/Application.hpp"
#include "../header/MainFrame.hpp"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	auto frame = new MainFrame(
		wxT("wxWidgets Layout learning"));

	frame->Show(true);

	return true;
}