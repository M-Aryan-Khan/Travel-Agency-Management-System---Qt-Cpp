#include "searchusers.h"
#include "ui_searchusers.h"
#include "customers.h"

searchUsers::searchUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchUsers)
{
    ui->setupUi(this);
    searchUsers::setWindowFlags(Qt::CustomizeWindowHint);
}

searchUsers::~searchUsers()
{
    delete ui;
}

void searchUsers::on_searchButton_clicked()
{
    searchCustomers s;
    s.searchCustomer(ui);
}

void searchUsers::on_cancelButton_clicked()
{
    this->close();
}

