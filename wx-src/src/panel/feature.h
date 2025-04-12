#ifndef CFEATURE_H
#define CFEATURE_H

#include <wx/dialog.h>
#include <wx/textctrl.h>

#include "node.h"

class CFeature : public wxDialog
{
private:
    wxTextCtrl* m_txtSurname;
    wxTextCtrl* m_txtName;
    wxTextCtrl* m_txtPatronymic;
    wxTextCtrl* m_txtGender;
    wxTextCtrl* m_txtDateOfBirth;
    wxTextCtrl* m_txtDateOfDeath;

public:
    TNode* GetFeature();

    CFeature(wxWindow* parent);
    ~CFeature();
};

#endif // CFEATURE_H