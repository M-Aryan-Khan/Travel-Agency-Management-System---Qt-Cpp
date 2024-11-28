#include "addusers.h"
#include "ui_addusers.h"
#include "customers.h"
#include "tripPackages.h"

addUsers::addUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addUsers)
{
    ui->setupUi(this);
    addUsers::setWindowFlags(Qt::CustomizeWindowHint);
    Fill fill;
    fill.FillTripsNames(ui);
    ui->cellValidate->hide();
    ui->homeValidate->hide();
    ui->birthdayValidate->hide();
    ui->pExpiryValidate->hide();
}

addUsers::~addUsers()
{
    delete ui;
}

void addUsers::on_saveButton_clicked()
{
    addCustomers a;
    bool check = a.addCustomer(ui);

    if (!check) {
        return;
    }
    close();
}


void addUsers::on_cancelButton_clicked()
{
    this->close();
}


void addUsers::on_packageSelect_activated(int )
{
    Fill fill;
    fill.setDescriptionText(ui);
}


void addUsers::on_birthdayEdit_editingFinished()
{
    addCustomers check;
    if(!check.validateDateInput(ui, 1)){
        ui->birthdayValidate->show();
        ui->birthdayEdit->clear();
    }
    else{
        ui->birthdayValidate->hide();
    }
}


void addUsers::on_passportExpEdit_editingFinished()
{
    addCustomers check;
    if(!check.validateDateInput(ui, 2)){
        ui->pExpiryValidate->show();
        ui->passportExpEdit->clear();
    }
    else{
        ui->pExpiryValidate->hide();
    }
}

void addUsers::on_homePhoneEdit_editingFinished()
{
    addCustomers check;
    if(!check.validateContactInput(ui, 1)){
        ui->homeValidate->show();
        ui->homePhoneEdit->clear();
    }
    else{
        ui->homeValidate->hide();
    }
}

void addUsers::on_cellPhoneEdit_editingFinished()
{
    addCustomers check;
    if(!check.validateContactInput(ui, 2)){
        ui->cellValidate->show();
        ui->cellPhoneEdit->clear();
    }
    else{
        ui->cellValidate->hide();
    }
}

