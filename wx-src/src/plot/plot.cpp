#include "plot.h"

#include <thread>
#include <wx/dcbuffer.h>
#include <wx/msgdlg.h>

BEGIN_EVENT_TABLE(CPlot, wxPanel)
EVT_PAINT(CPlot::PaintEvent)
EVT_MOTION(CPlot::MouseMoved)
EVT_SIZE(CPlot::ChangeSize)
EVT_TIMER(TIMER_ID, CPlot::OnTimer)
EVT_LEFT_DOWN(CPlot::MouseLeftDown)
EVT_LEFT_UP(CPlot::MouseLeftReleased)

// EVT_LEAVE_WINDOW(CPlot::MouseLeftWindow)
// EVT_KEY_DOWN(CPlot::KeyPressed)
// EVT_KEY_UP(CPlot::KeyReleased)
// EVT_MOUSEWHEEL(CPlot::MouseWheelMoved)

END_EVENT_TABLE()

CPlot::CPlot(wxWindow* parent)
    : wxPanel(parent, NewControlId())
    , m_timer(this, TIMER_ID)
{
    m_mouseClick = false;

    this->SetBackgroundColour(wxColor(0x20, 0xB2, 0xAA));
    m_screen = this->GetSize();
    m_timer.Start(35);
}

CPlot::~CPlot()
{
}

void CPlot::OnTimer(wxTimerEvent& event)
{
    Refresh();
}

void CPlot::ChangeSize(wxSizeEvent& event)
{
    m_screen = this->GetSize();
}

void CPlot::MouseMoved(wxMouseEvent& event)
{
    m_mousePosition = event.GetPosition();
}

void CPlot::PaintEvent(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    for(auto& p : m_parents)
        GetRound(p, dc);

    DrowMousePosition(dc);
}

void CPlot::DrowMousePosition(wxDC& dc)
{
    wxString temp = wxString::Format(wxT("%d, %d"), m_mousePosition.x, m_mousePosition.y);
    dc.DrawText(temp, m_mousePosition.x + 10, m_mousePosition.y - 10);
}

void CPlot::DrowElement(TNode* node, wxDC& dc)
{
    const int radiusX = 105;
    const int radiusY = 45;

    const int space = 12;

    dc.DrawEllipse(wxPoint(node->m_xy.x, node->m_xy.y), wxSize(radiusX * 2, radiusY * 2));

    dc.DrawText(wxString(node->m_pSurname.first),
        wxPoint(node->m_xy.x + radiusX - node->m_pSurname.second, node->m_xy.y + 1 * space));
    dc.DrawText(wxString(node->m_pName.first),
        wxPoint(node->m_xy.x + radiusX - node->m_pName.second, node->m_xy.y + 2 * space));
    dc.DrawText(wxString(node->m_pPatronymic.first),
        wxPoint(node->m_xy.x + radiusX - node->m_pPatronymic.second, node->m_xy.y + 3 * space));

    dc.DrawText(
        wxString(node->m_pDateOfBirth.first), wxPoint(node->m_xy.x + radiusX * 5 / 11, node->m_xy.y + 5 * space));
    dc.DrawText(
        wxString(node->m_pDateOfDeath.first), wxPoint(node->m_xy.x + 2 * radiusX * 6 / 11, node->m_xy.y + 5 * space));
    dc.DrawText(wxT("-"), wxPoint(node->m_xy.x + radiusX, node->m_xy.y + 5 * space));

    dc.DrawText(wxString(node->m_pGender.first[0]), wxPoint(node->m_xy.x + radiusX / 3, node->m_xy.y + 3 * space));

    CheckPosition(node->m_xy, radiusX, radiusY);
}

void CPlot::AddParent(TNode* node)
{
    node->m_xy = m_mousePosition;
    m_parents.push_back(node);
}

void CPlot::CheckPosition(const wxPoint& xy, const int& radiusX, const int& radiusY)
{
    if(pow((m_mousePosition.x - xy.x), 2) / pow(radiusX, 2) + pow((m_mousePosition.y - xy.y), 2) / pow(radiusY, 2) <= 1)
        m_mouseClick = true;
    else
        m_mouseClick = false;

    // if(m_mousePosition.x >= xy.x && m_mousePosition.x <= xy.x + 2 * radiusX && m_mousePosition.y >= xy.y &&
    //    m_mousePosition.y <= xy.y + 2 * radiusY)
    //    m_mouseClick = true;
    // else
    //    m_mouseClick = false;
}

void CPlot::GetRound(TNode* node, wxDC& dc)
{
    if(node != nullptr) {
        DrowElement(node, dc);
        GetRound(node->m_child, dc);
        // GetRound(node->GetLeft());
    }
}

void CPlot::MouseLeftDown(wxMouseEvent& event)
{
    if(m_mouseClick == true) {
        wxMessageBox("sadsa");
        m_mouseClick = false;
    }
}

void CPlot::MouseLeftReleased(wxMouseEvent& event)
{
}

/*void CPlot::MouseWheelMoved(wxMouseEvent& event)
{
}



void CPlot::MouseLeftWindow(wxMouseEvent& event)
{
}

void CPlot::KeyPressed(wxKeyEvent& event)
{
}

void CPlot::KeyReleased(wxKeyEvent& event)
{
}*/