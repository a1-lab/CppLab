#include "../header/Application.hpp"
#include "../header/MainFrame.hpp"
#include "../header/customization/CustomArtProvider.hpp"

DECLARE_APP(Application)
IMPLEMENT_APP(Application)

bool Application::OnInit()
{
	wxArtProvider::Push(new CustomArtProvider);

	auto frame = new MainFrame(
		wxT("Advanced user interface"));

	frame->Show(true);

	return true;
}