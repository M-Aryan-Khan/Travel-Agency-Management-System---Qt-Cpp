#ifndef ADDPACKAGE_H
#define ADDPACKAGE_H

#include <QDialog>

namespace Ui {
class addPackage;
}

class addPackage : public QDialog
{
    Q_OBJECT

public:
    explicit addPackage(QWidget *parent = nullptr);
    ~addPackage();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_bookingStartsEdit_editingFinished();

    void on_durationEdit_editingFinished();

    void on_departureEdit_editingFinished();

private:
    Ui::addPackage *ui;
};

#endif // ADDPACKAGE_H
