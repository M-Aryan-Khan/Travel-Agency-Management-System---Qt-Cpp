#ifndef UPDATEPACKAGE_H
#define UPDATEPACKAGE_H

#include <QDialog>

namespace Ui {
class updatePackage;
}

class updatePackage : public QDialog
{
    Q_OBJECT

public:
    explicit updatePackage(QWidget *parent = nullptr);
    ~updatePackage();

private slots:
    void on_searchButton_clicked();

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_bookingStartsEdit_editingFinished();

    void on_departureEdit_editingFinished();

    void on_durationEdit_editingFinished();

private:
    Ui::updatePackage *ui;
};

#endif // UPDATEPACKAGE_H
