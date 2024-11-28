#ifndef ADDUSERS_H
#define ADDUSERS_H

#include <QDialog>

namespace Ui {
class addUsers;
}

class addUsers : public QDialog
{
    Q_OBJECT

public:
    explicit addUsers(QWidget *parent = nullptr);
    ~addUsers();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_packageSelect_activated(int index);

    void on_birthdayEdit_editingFinished();

    void on_passportExpEdit_editingFinished();

    void on_homePhoneEdit_editingFinished();

    void on_cellPhoneEdit_editingFinished();

private:
    Ui::addUsers *ui;
};

#endif // ADDUSERS_H
