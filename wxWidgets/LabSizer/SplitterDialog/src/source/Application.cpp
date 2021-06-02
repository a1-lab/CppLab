#include "Application.hpp"
#include "SplitterDialog.hpp"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	auto frame = new SplitterDialog(NULL);

	frame->Show(true);
	return true;
}