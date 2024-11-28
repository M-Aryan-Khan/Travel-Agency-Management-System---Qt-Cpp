#ifndef EDITADMININFO_H
#define EDITADMININFO_H

#include <QDialog>

namespace Ui {
class editAdminInfo;
}

class editAdminInfo : public QDialog
{
    Q_OBJECT

public:
    explicit editAdminInfo(QWidget *parent = nullptr);
    ~editAdminInfo();

private slots:
    void on_save_clicked();

    void on_back_clicked();

    void on_change_clicked();

private:
    Ui::editAdminInfo *ui;
};

#endif // EDITADMININFO_H
