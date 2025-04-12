#pragma once

#include <wx/textctrl.h>

struct TNode {
    wxPoint m_xy;
    std::pair<std::string, double> m_pSurname;
    std::pair<std::string, double> m_pName;
    std::pair<std::string, double> m_pPatronymic;
    std::pair<std::string, double> m_pDateOfBirth;
    std::pair<std::string, double> m_pDateOfDeath;
    std::pair<std::string, double> m_pGender;

    TNode* m_child;

    void SetValue(std::pair<std::string, double>* value, wxScopedCharBuffer buffer, wxTextPos pos) {};
};