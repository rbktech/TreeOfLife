#include "mainframe.h"

#include <wx/menu.h>

#include "panel/feature.h"

CMainFrame::CMainFrame()
    : wxFrame(NULL, NewControlId(), wxT("Tree Of Life"))
{
    SetIcon(wxICON(tree));

    m_plot = new CPlot(this);

    wxBoxSizer* main_box = new wxBoxSizer(wxVERTICAL);
    main_box->Add(m_plot, 1, wxEXPAND);
    SetSizerAndFit(main_box);
    this->SetSize(wxSize(700, 500));

    m_plot->Bind(wxEVT_RIGHT_DOWN, CMainFrame::RightClick, this);
}

CMainFrame::~CMainFrame()
{
}

void CMainFrame::RightClick(wxMouseEvent& event)
{
    wxMenu* m_menu = new wxMenu;
    m_menu->Append(ID_MENU_ADD_PARENT, wxT("Add parent"));
    m_menu->Append(ID_MENU_ADD_CHILD, wxT("Add child"));
    m_menu->Append(ID_MENU_ADD_MARRIAGE, wxT("Add marriage"));
    m_menu->Append(ID_MENU_CHARACTERISTICS, wxT("Characteristics"));

    // Bind(wxEVT_COMMAND_MENU_SELECTED, CMainFrame::OnAddParent, this, ID_MENU_ADD_PARENT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, CMainFrame::OnShowCharacteristics, this, ID_MENU_CHARACTERISTICS);

    this->PopupMenu(m_menu);
}

void CMainFrame::OnShowCharacteristics(wxCommandEvent& event)
{
    CFeature dlgFeature(this);
    if(dlgFeature.ShowModal() == wxID_OK)
        m_plot->AddParent(dlgFeature.GetFeature());
}

void CMainFrame::Plot()
{
    CParseStringV3 parse;
    CStringTree* tree = parse.Make("2*50+(4-(1-2)+(3-4)*(-1))");

    GetRound(tree);
}

void CMainFrame::GetRound(CStringTree* node)
{
    if(node != nullptr) {
        GetRound(node->GetRight());
        GetRound(node->GetLeft());
    }
}
