#ifndef VIEWADMININFO_H
#define VIEWADMININFO_H

#include <QDialog>

namespace Ui {
class viewAdminInfo;
}

class viewAdminInfo : public QDialog
{
    Q_OBJECT

public:
    explicit viewAdminInfo(QWidget *parent = nullptr);
    ~viewAdminInfo();

private slots:
    void on_back_clicked();

private:
    Ui::viewAdminInfo *ui;
};

#endif // VIEWADMININFO_H
