#ifndef SEARCHUSERS_H
#define SEARCHUSERS_H

#include <QDialog>

namespace Ui {
class searchUsers;
}

class searchUsers : public QDialog
{
    Q_OBJECT

public:
    explicit searchUsers(QWidget *parent = nullptr);
    ~searchUsers();

private slots:
    void on_searchButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::searchUsers *ui;
};

#endif // SEARCHUSERS_H
