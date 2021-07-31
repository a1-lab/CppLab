#include "../header/Application.hpp"
#include "../header/MainFrame.hpp"

DECLARE_APP(Application)
IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	auto frame = new MainFrame(
		wxT("Advanced user interface"));

	frame->Show(true);

	return true;
}