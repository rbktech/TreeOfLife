#include "mainframe.h"

class wxMainApp : public wxApp
{
private:
    bool OnInit() override
    {
        CMainFrame* mainframe = new CMainFrame();
        mainframe->SetAutoLayout(true);
        return mainframe->Show();
    }
};

IMPLEMENT_APP(wxMainApp)