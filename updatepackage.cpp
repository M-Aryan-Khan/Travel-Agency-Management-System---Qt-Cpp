#include "updatepackage.h"
#include "ui_updatepackage.h"
#include "tripPackages.h"

updatePackage::updatePackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updatePackage)
{
    ui->setupUi(this);
    updatePackage::setWindowFlags(Qt::CustomizeWindowHint);
    Fill fill;
    fill.FillTripsNames(ui);
    ui->bookingValidate->hide();
    ui->departureValidate->hide();
    ui->durationValidate->hide();
}

updatePackage::~updatePackage()
{
    delete ui;
}

void updatePackage::on_searchButton_clicked()
{
    updatePackages update;
    update.fillEdit(ui);
}

void updatePackage::on_saveButton_clicked()
{
    updatePackages u;
    bool check = u.updatePack(ui);
    if (!check) {
        return;
    }
    close();
}

void updatePackage::on_cancelButton_clicked()
{
    this->close();
}

void updatePackage::on_bookingStartsEdit_editingFinished()
{
    updatePackages check;
    if(!check.validateInput(ui, 1)){
        ui->bookingValidate->show();
        ui->bookingStartsEdit->clear();
    }
    else{
        ui->bookingValidate->hide();
    }
}

void updatePackage::on_departureEdit_editingFinished()
{
    updatePackages check;
    if(!check.validateInput(ui, 2)){
        ui->departureValidate->show();
        ui->departureEdit->clear();
    }
    else{
        ui->departureValidate->hide();
    }
}

void updatePackage::on_durationEdit_editingFinished()
{
    updatePackages check;
    if(!check.validateInput(ui, 3)){
        ui->durationValidate->show();
        ui->durationEdit->clear();
    }
    else{
        ui->durationValidate->hide();
    }
}

