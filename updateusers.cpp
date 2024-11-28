#include "updateusers.h"
#include "ui_updateusers.h"
#include "customers.h"
#include "tripPackages.h"

updateUsers::updateUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateUsers)
{
    ui->setupUi(this);
    updateUsers::setWindowFlags(Qt::CustomizeWindowHint);
    Fill fill;
    fill.FillTripsNames(ui);
    ui->cellValidate->hide();
    ui->homeValidate->hide();
    ui->birthdayValidate->hide();
    ui->pExpiryValidate->hide();
}

updateUsers::~updateUsers()
{
    delete ui;
}

void updateUsers::on_searchButton_clicked()
{
    updateCustomers u;
    u.fillEdit(ui);
}


void updateUsers::on_saveButton_clicked()
{
    updateCustomers u;
    bool check = u.updateCustomer(ui);
    if (!check) {
        return;
    }
    close();
}


void updateUsers::on_cancelButton_clicked()
{
    this->close();
}

void updateUsers::on_birthdayEdit_editingFinished()
{
    updateCustomers check;
    if(!check.validateDateInput(ui, 1)){
        ui->birthdayValidate->show();
        ui->birthdayEdit->clear();
    }
    else{
        ui->birthdayValidate->hide();
    }
}

void updateUsers::on_passportExpEdit_editingFinished()
{
    updateCustomers check;
    if(!check.validateDateInput(ui, 2)){
        ui->pExpiryValidate->show();
        ui->passportExpEdit->clear();
    }
    else{
        ui->pExpiryValidate->hide();
    }
}

void updateUsers::on_homePhoneEdit_editingFinished()
{
    updateCustomers check;
    if(!check.validateContactInput(ui, 1)){
        ui->homeValidate->show();
        ui->homePhoneEdit->clear();
    }
    else{
        ui->homeValidate->hide();
    }
}

void updateUsers::on_cellPhoneEdit_editingFinished()
{
    updateCustomers check;
    if(!check.validateContactInput(ui, 2)){
        ui->cellValidate->show();
        ui->cellPhoneEdit->clear();
    }
    else{
        ui->cellValidate->hide();
    }
}

