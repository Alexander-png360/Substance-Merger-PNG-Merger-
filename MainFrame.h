#pragma once

#include <wx/wx.h>
#include <string>

void processDirectory(const std::string& directoryPath);

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);

private:
    // Event Handlers
    void OnSelectFolder(wxCommandEvent& event);
    void OnRun(wxCommandEvent& event);

    
    wxPanel* m_panel;
    wxButton* m_selectBtn;
    wxButton* m_runBtn;
    wxStaticText* m_pathLabel; 

    std::string selectedPath;

};