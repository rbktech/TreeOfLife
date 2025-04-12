#ifndef CMAINFRAME_H
#define CMAINFRAME_H

#include <wx/frame.h>
#include <wx/glcanvas.h>
#include <wx/sizer.h>

#include <parse_string_v3/parsestring_v3.h>

#include "plot/plot.h"

class CMainFrame : public wxFrame
{
private:
    enum { ID_MENU_ADD_PARENT = 0, ID_MENU_ADD_CHILD, ID_MENU_ADD_MARRIAGE, ID_MENU_CHARACTERISTICS };

    CPlot* m_plot;

    void Plot();
    void GetRound(CStringTree* node);

    void RightClick(wxMouseEvent& event);

    void OnShowCharacteristics(wxCommandEvent& event);

public:
    CMainFrame();
    ~CMainFrame() override;
};

#endif // CMAINFRAME_H