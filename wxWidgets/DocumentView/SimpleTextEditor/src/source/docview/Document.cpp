#include "Document.hpp"
#include "View.hpp"

IMPLEMENT_DYNAMIC_CLASS(Document, wxDocument)

Document::Document()
{
	wxLogMessage(wxT("DocViewTestDocument::DocViewTestDocument"));
}

bool Document::OnSaveDocument(const wxString& filename)
{
	do
	{
		View* view = (View*)GetFirstView();
		if (!view) break;
		wxTextCtrl* editor = view->GetEditor();
		if (!editor) break;

		if (!editor->SaveFile(filename))
		{
			return false;
		}

		Modify(false);

#ifdef __WXMAC__
		wxFileName fn(filename);
		fn.MacSetDefaultTypeAndCreator();
#endif
	} while (false);

	return true;
}

bool Document::OnOpenDocument(const wxString& filename)
{
	do
	{
		auto view = (View*)GetFirstView();
		if (!view) {
			break;
		}

		wxTextCtrl* editor = view->GetEditor();
		if (!editor) {
			break;
		}

		if (!editor->LoadFile(filename))
		{
			return false;
		}

		SetFilename(filename, true);
		Modify(false);
		UpdateAllViews();
	} while (false);

	return true;
}

bool Document::IsModified(void) const
{
	bool res = wxDocument::IsModified();
	auto view = (View*)GetFirstView();

	if (view)
	{
		res |= view->GetEditor()->IsModified();
	}

	return res;
}

void Document::Modify(bool mod)
{
	auto view = (View*)GetFirstView();

	wxDocument::Modify(mod);

	if (!mod && view && view->GetEditor())
	{
		view->GetEditor()->DiscardEdits();
	}
}
