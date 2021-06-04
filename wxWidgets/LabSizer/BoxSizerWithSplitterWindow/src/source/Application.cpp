#include "Application.hpp"
#include "MainFrame.hpp"

IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	SetProcessDPIAware();

	auto frame = new MainFrame(
		wxT("BorderSizer Application"));
	frame->SetMinSize(wxSize(800, 600));
	frame->SetSize(wxSize(800, 600));
	frame->Centre();
	frame->Show(true);

	return true;
}