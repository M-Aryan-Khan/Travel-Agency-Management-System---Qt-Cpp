#include "searchpackage.h"
#include "ui_searchpackage.h"
#include "tripPackages.h"

searchPackage::searchPackage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchPackage)
{
    ui->setupUi(this);
}

searchPackage::~searchPackage()
{
    delete ui;
}

void searchPackage::on_cancelButton_clicked()
{
    this->close();
}

void searchPackage::on_packageSelect_activated(int)
{
    searchPackages sea;
    sea.searchPack(ui);
}

