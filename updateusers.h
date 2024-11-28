#ifndef UPDATEUSERS_H
#define UPDATEUSERS_H

#include <QDialog>

namespace Ui {
class updateUsers;
}

class updateUsers : public QDialog
{
    Q_OBJECT

public:
    explicit updateUsers(QWidget *parent = nullptr);
    ~updateUsers();

private slots:
    void on_searchButton_clicked();

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_birthdayEdit_editingFinished();

    void on_passportExpEdit_editingFinished();

    void on_homePhoneEdit_editingFinished();

    void on_cellPhoneEdit_editingFinished();

private:
    Ui::updateUsers *ui;
};

#endif // UPDATEUSERS_H
