#include "deletepackage.h"
#include "ui_deletepackage.h"
#include "tripPackages.h"

deletePackage::deletePackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletePackage)
{
    ui->setupUi(this);
    deletePackage::setWindowFlags(Qt::CustomizeWindowHint);
    Fill fill;
    fill.FillTripsNames(ui);
}

deletePackage::~deletePackage()
{
    delete ui;
}

void deletePackage::on_deleteButton_clicked()
{
    deletePackages del;
    del.deletePack(ui);
    close();
}


void deletePackage::on_cancelButton_clicked()
{
    this->close();
}

