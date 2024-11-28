#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include "editadmininfo.h"
#include "ui_editadmininfo.h"

#include <QDialog>

namespace Ui {
class changePassword;
}

class changePassword : public QDialog
{
    Q_OBJECT

public:
    explicit changePassword(Ui::editAdminInfo* edit, QWidget *parent = nullptr);
    ~changePassword();

private slots:
    void on_save_clicked();

    void on_cancel_clicked();

    void on_eye_clicked();

    void on_eye1_clicked();

    void on_eye2_clicked();

private:
    Ui::changePassword *ui;
    Ui::editAdminInfo *edit;
};

#endif // CHANGEPASSWORD_H
