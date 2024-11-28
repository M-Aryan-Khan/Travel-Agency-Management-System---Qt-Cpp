#ifndef DELETEUSERS_H
#define DELETEUSERS_H

#include <QDialog>

namespace Ui {
class deleteUsers;
}

class deleteUsers : public QDialog
{
    Q_OBJECT

public:
    explicit deleteUsers(QWidget *parent = nullptr);
    ~deleteUsers();

private slots:
    void on_deleteButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::deleteUsers *ui;
};

#endif // DELETEUSERS_H
