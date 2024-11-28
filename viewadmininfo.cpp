#include "viewadmininfo.h"
#include "ui_viewadmininfo.h"
#include "admin.h"

viewAdminInfo::viewAdminInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewAdminInfo)
{
    ui->setupUi(this);
    viewAdminInfo::setWindowFlags(Qt::CustomizeWindowHint);
    viewAdmin view;
    view.viewAdmininfo(ui);
}

viewAdminInfo::~viewAdminInfo()
{
    delete ui;
}

void viewAdminInfo::on_back_clicked()
{
    this->close();
}
