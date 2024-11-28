#ifndef DELETEPACKAGE_H
#define DELETEPACKAGE_H

#include <QDialog>

namespace Ui {
class deletePackage;
}

class deletePackage : public QDialog
{
    Q_OBJECT

public:
    explicit deletePackage(QWidget *parent = nullptr);
    ~deletePackage();

private slots:
    void on_deleteButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::deletePackage *ui;
};

#endif // DELETEPACKAGE_H
