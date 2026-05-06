#include "MainFrame.h"
#include <wx/dirdlg.h>

MainFrame::MainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 200))
{
    wxPanel* panel = new wxPanel(this);

    wxButton* selectBtn =
        new wxButton(panel, wxID_ANY, "Select Folder", wxPoint(50, 50));

    wxButton* runBtn =
        new wxButton(panel, wxID_ANY, "Run", wxPoint(200, 50));

    selectBtn->Bind(wxEVT_BUTTON, &MainFrame::OnSelectFolder, this);

    runBtn->Bind(wxEVT_BUTTON, [this](wxCommandEvent&) {
        if (!selectedPath.empty()) {
            processDirectory(selectedPath);
            wxMessageBox("Done merging images.", "Success");
        }
        else {
            wxMessageBox("Please select a folder first.", "Error");
        }
        });
}

void MainFrame::OnSelectFolder(wxCommandEvent& event)
{
    wxDirDialog dialog(this, "Choose a folder");

    if (dialog.ShowModal() == wxID_OK) {
        selectedPath = dialog.GetPath().ToStdString();
    }
}