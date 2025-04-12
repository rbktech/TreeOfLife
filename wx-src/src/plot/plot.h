#ifndef CPLOT_H
#define CPLOT_H

#include <wx/panel.h>
#include <wx/timer.h>

#include <cfloat>
#include <list>
#include <map>
#include <vector>

#include "node.h"

class CPlot : public wxPanel
{
private:
    bool m_mouseClick;

    enum { TIMER_ID = 0 };

    wxTimer m_timer;

    typedef void (CPlot::*iFunc)();

    std::vector<TNode*> m_parents;

    wxSize m_screen;
    wxPoint m_mousePosition;

    void CheckPosition(const wxPoint& xy, const int& radiusX, const int& radiusY);

    void GetRound(TNode* node, wxDC& dc);

    void DrowElement(TNode* node, wxDC& dc);
    void DrowMousePosition(wxDC& dc);

    void OnTimer(wxTimerEvent& event);

    void ChangeSize(wxSizeEvent& event);
    void PaintEvent(wxPaintEvent& event);
    void MouseMoved(wxMouseEvent& event);

    void MouseLeftDown(wxMouseEvent& event);
    void MouseLeftReleased(wxMouseEvent& event);
    // void MouseWheelMoved(wxMouseEvent& event);
    // void MouseLeftWindow(wxMouseEvent& event);
    // void KeyPressed(wxKeyEvent& event);
    // void KeyReleased(wxKeyEvent& event);

    DECLARE_EVENT_TABLE()

public:
    void AddParent(TNode* node);
    void CheckPosition();
    CPlot(wxWindow* parent);
    ~CPlot();
};

#endif // CPLOT_H