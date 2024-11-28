#ifndef SEARCHPACKAGE_H
#define SEARCHPACKAGE_H

#include <QDialog>

namespace Ui {
class searchPackage;
}

class searchPackage : public QDialog
{
    Q_OBJECT

public:
    explicit searchPackage(QWidget *parent = nullptr);
    ~searchPackage();

private slots:
    void on_cancelButton_clicked();

    void on_packageSelect_activated(int index);

private:
    Ui::searchPackage *ui;
};

#endif // SEARCHPACKAGE_H
