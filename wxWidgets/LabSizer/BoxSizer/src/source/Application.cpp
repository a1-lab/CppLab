#include "Application.hpp"
#include "MainFrame.hpp"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	auto frame = new MainFrame(
		wxT("BorderSizer Application"));

	frame->Show(true);

	return true;
}