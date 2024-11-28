#include "deleteusers.h"
#include "ui_deleteusers.h"
#include "customers.h"

deleteUsers::deleteUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteUsers)
{
    ui->setupUi(this);
    deleteUsers::setWindowFlags(Qt::CustomizeWindowHint);
}

deleteUsers::~deleteUsers()
{
    delete ui;
}

void deleteUsers::on_deleteButton_clicked()
{
    deleteCustomers d;
    d.deleteCustomer(ui);
    this->close();
}


void deleteUsers::on_cancelButton_clicked()
{
    this->close();
}

