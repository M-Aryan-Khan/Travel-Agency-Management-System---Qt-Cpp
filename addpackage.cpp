#include "addpackage.h"
#include "ui_addpackage.h"
#include "tripPackages.h"

addPackage::addPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPackage)
{
    ui->setupUi(this);
    addPackage::setWindowFlags(Qt::CustomizeWindowHint);
    ui->bookingValidate->hide();
    ui->departureValidate->hide();
    ui->durationValidate->hide();
}

addPackage::~addPackage()
{
    delete ui;
}

void addPackage::on_saveButton_clicked()
{
    addPackages a;
    bool check = a.addPack(ui);
    if (!check) {
        return;
    }
    close();
}

void addPackage::on_cancelButton_clicked()
{
    this->close();
}

void addPackage::on_bookingStartsEdit_editingFinished()
{
    addPackages check;
    if(!check.validateInput(ui, 1)){
        ui->bookingValidate->show();
        ui->bookingStartsEdit->clear();
    }
    else{
        ui->bookingValidate->hide();
    }
}

void addPackage::on_durationEdit_editingFinished()
{
    addPackages check;
    if(!check.validateInput(ui, 3)){
        ui->durationValidate->show();
        ui->durationEdit->clear();
    }
    else{
        ui->durationValidate->hide();
    }
}

void addPackage::on_departureEdit_editingFinished()
{
    addPackages check;
    if(!check.validateInput(ui, 2)){
        ui->departureValidate->show();
        ui->departureEdit->clear();
    }
    else{
        ui->departureValidate->hide();
    }
}
