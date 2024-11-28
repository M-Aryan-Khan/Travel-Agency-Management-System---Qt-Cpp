#include "editadmininfo.h"
#include "ui_editadmininfo.h"
#include "admin.h"
#include "changepassword.h"

editAdminInfo::editAdminInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editAdminInfo)
{
    ui->setupUi(this);
    editAdminInfo::setWindowFlags(Qt::CustomizeWindowHint);
    editAdmin edit;
    edit.editAdminInfo(ui);
}

editAdminInfo::~editAdminInfo()
{
    delete ui;
}

void editAdminInfo::on_save_clicked()
{
    editAdmin edit;
    edit.saveAdminInfo(ui);
    close();
}

void editAdminInfo::on_back_clicked()
{
    this->close();
}

void editAdminInfo::on_change_clicked()
{
    changePassword* change = new changePassword(ui);
    change->setModal(true);
    change->exec();
    delete change;
}

