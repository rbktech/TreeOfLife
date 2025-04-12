#include "feature.h"

#include <wx/sizer.h>
#include <wx/stattext.h>

CFeature::CFeature(wxWindow* parent)
    : wxDialog(parent, NewControlId(), wxT("Характеристики"))
{
    m_txtSurname = new wxTextCtrl(this, NewControlId(), wxT("Петров"));
    m_txtName = new wxTextCtrl(this, NewControlId(), wxT("Иван"));
    m_txtPatronymic = new wxTextCtrl(this, NewControlId(), wxT("Гаврилович"));
    m_txtGender = new wxTextCtrl(this, NewControlId(), wxT("Мужской"));
    m_txtDateOfBirth = new wxTextCtrl(this, NewControlId(), wxT("28.09.1988"));
    m_txtDateOfDeath = new wxTextCtrl(this, NewControlId(), wxT("31.12.9999"));

    wxSizer* button_sizer = CreateSeparatedButtonSizer(wxOK | wxCANCEL);

    wxBoxSizer* main_box = new wxBoxSizer(wxVERTICAL);

    wxFlexGridSizer* gr_box = new wxFlexGridSizer(6, 2, 5, 5);
    gr_box->Add(new wxStaticText(this, wxID_ANY, wxT("Фамилия")), 0, wxALIGN_CENTER_VERTICAL);
    gr_box->Add(m_txtSurname);
    gr_box->Add(new wxStaticText(this, wxID_ANY, wxT("Имя")), 0, wxALIGN_CENTER_VERTICAL);
    gr_box->Add(m_txtName);
    gr_box->Add(new wxStaticText(this, wxID_ANY, wxT("Отчество")), 0, wxALIGN_CENTER_VERTICAL);
    gr_box->Add(m_txtPatronymic);
    gr_box->Add(new wxStaticText(this, wxID_ANY, wxT("Пол")), 0, wxALIGN_CENTER_VERTICAL);
    gr_box->Add(m_txtGender);
    gr_box->Add(new wxStaticText(this, wxID_ANY, wxT("Дата рождения")), 0, wxALIGN_CENTER_VERTICAL);
    gr_box->Add(m_txtDateOfBirth);
    gr_box->Add(new wxStaticText(this, wxID_ANY, wxT("Дата смерти")), 0, wxALIGN_CENTER_VERTICAL);
    gr_box->Add(m_txtDateOfDeath);

    main_box->Add(gr_box, 0, wxALL, 5);
    main_box->Add(button_sizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

    SetSizerAndFit(main_box);

    // Bind(wxEVT_BUTTON, &DataManagerAddFormulaDlg::OnOkButton, this, wxID_OK);
}

CFeature::~CFeature()
{
}

TNode* CFeature::GetFeature()
{
    TNode* node = new TNode;

    node->SetValue(&node->m_pSurname, m_txtSurname->GetValue().mb_str(), m_txtSurname->GetLastPosition());
    node->SetValue(&node->m_pName, m_txtName->GetValue().mb_str(), m_txtName->GetLastPosition());
    node->SetValue(&node->m_pPatronymic, m_txtPatronymic->GetValue().mb_str(), m_txtPatronymic->GetLastPosition());
    node->SetValue(&node->m_pGender, m_txtGender->GetValue().mb_str(), m_txtGender->GetLastPosition());
    node->SetValue(&node->m_pDateOfBirth, m_txtDateOfBirth->GetValue().mb_str(), m_txtDateOfBirth->GetLastPosition());
    node->SetValue(&node->m_pDateOfDeath, m_txtDateOfDeath->GetValue().mb_str(), m_txtDateOfDeath->GetLastPosition());

    return node;
}