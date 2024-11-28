#include "system.h"
#include "ui_system.h"
#include "login.h"
#include <QString>
#include <fstream>
#include <string>
#include <QTreeWidget>
#include <cmath>
#include <QDebug>
#include <QTimer>
#include <QDate>
#include <QIcon>
#include <QPushButton>
#include "customers.h"
#include "tripPackages.h"
#include "viewadmininfo.h"
#include "editadmininfo.h"
#include "addpackage.h"
#include "updatepackage.h"
#include "searchpackage.h"

bool idchecked = true;
bool namechecked = true;
bool pricechecked = true;
bool trachecked = true;

System::System(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::System)
{
    ui->setupUi(this);
    ui->side_menu->hide();
    ui->logoMenu->hide();
    ui->customerText->hide();
    ui->packagesText->hide();
    ui->stackedWidget->setCurrentIndex(0);
    ui->homeText->hide();
    ui->treeWidget->setColumnCount(0);
    ui->treeWidgetP->setColumnCount(0);
    ui->accMenu->hide();
    ui->adminInfo->hide();
    ui->adminInfoButton->hide();
    ui->signOut->hide();
    ui->signOutButton->hide();
    ui->accMenuHead->hide();
    ui->adminMenu->hide();
    ui->viewAdminInfo->hide();
    ui->viewAdminButton->hide();
    ui->editAdminInfo->hide();
    ui->editAdminButton->hide();
    ui->exitText->hide();
    ui->sortupid->hide();
    ui->sortupname->hide();
    ui->sortupprice->hide();
    ui->sortuptravelers->hide();
    Revenue rev;
    rev.returnTotalRevenue();
    ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/Revenue.txt");
    string revenue;
    getline(file,revenue);
    ui->Dcount->setText(QString::fromStdString(revenue));
    Profit profit;
    profit.returnTotalProfit();
    ifstream File("C:/Users/ND.COM/Documents/TravelAgencyMSystem/Profit.txt");
    string pro;
    getline(File,pro);
    ui->PRcount->setText(QString::fromStdString(pro));
    countPackages countt;
    int c= countt.getTotalcountOfPackages();
    ui->Pcount->setText(QString::number(c));
    countCustomers count;
    ui->Ccount->setText(QString::fromStdString(count.getTotalcountOfCustomers()));
    CustomerRatings rates;
    float f = rates.getAvgOfRatings();
    ui->Rcount->setText(QString::number(f));
    QDate date = QDate::currentDate();
    QString Date = date.toString("dddd, MM-dd-yy");
    ui->date->setText(Date);
    QTimer *timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
    System::setWindowFlags(Qt::CustomizeWindowHint);
}

System::~System()
{
    delete ui;
}
//////////

void System::showTime(){
    QTime timee = QTime::currentTime();
    QString Time = timee.toString("hh : mm : ss");
    ui->time->setText(Time);
}
void System::on_side_menu_open_clicked()
{
    if(ui->side_menu->isHidden()){
        ui->side_menu->show();
        ui->logoMenu->show();
        ui->customerText->show();
        ui->homeText->show();
        ui->packagesText->show();
        ui->exitText->show();
    }
    else{
        ui->side_menu->hide();
        ui->logoMenu->hide();
        ui->customerText->hide();
        ui->homeText->hide();
        ui->packagesText->hide();
        ui->exitText->hide();
    }
}

void System::on_accLogo_clicked()
{
    if(ui->accMenu->isHidden()){
        ui->accMenu->show();
        ui->adminInfo->show();
        ui->adminInfoButton->show();
        ui->signOut->show();
        ui->signOutButton->show();
        ui->accMenuHead->show();
    }
    else{
        ui->accMenu->hide();
        ui->adminInfo->hide();
        ui->adminInfoButton->hide();
        ui->signOut->hide();
        ui->signOutButton->hide();
        ui->accMenuHead->hide();
        ui->adminMenu->hide();
        ui->viewAdminInfo->hide();
        ui->viewAdminButton->hide();
        ui->editAdminInfo->hide();
        ui->editAdminButton->hide();
    }
}

void System::on_adminInfoButton_clicked()
{
    if(ui->adminMenu->isHidden()){
        ui->adminMenu->show();
        ui->viewAdminInfo->show();
        ui->viewAdminButton->show();
        ui->editAdminInfo->show();
        ui->editAdminButton->show();
    }
    else{
        ui->adminMenu->hide();
        ui->viewAdminInfo->hide();
        ui->viewAdminButton->hide();
        ui->editAdminInfo->hide();
        ui->editAdminButton->hide();
    }
}

void System::on_home_clicked()
{
    if(ui->side_menu->isHidden()){}
    else{
        ui->side_menu->hide();
        ui->logoMenu->hide();
        ui->customerText->hide();
        ui->homeText->hide();
        ui->packagesText->hide();
        ui->exitText->hide();
    }
    ui->stackedWidget->setCurrentIndex(0);
}


void System::on_customer_clicked()
{
    if(ui->side_menu->isHidden()){}
    else{
        ui->side_menu->hide();
        ui->logoMenu->hide();
        ui->customerText->hide();
        ui->homeText->hide();
        ui->packagesText->hide();
        ui->exitText->hide();
    }
    ui->stackedWidget->setCurrentIndex(1);
}


void System::on_packages_clicked()
{
    if(ui->side_menu->isHidden()){}
    else{
        ui->side_menu->hide();
        ui->logoMenu->hide();
        ui->customerText->hide();
        ui->homeText->hide();
        ui->packagesText->hide();
        ui->exitText->hide();
    }
    ui->stackedWidget->setCurrentIndex(2);
}

void System::on_exit_clicked()
{
    this->close();
}

void System::on_Crefresh_clicked()
{
    countCustomers count;
    QString qstr = QString::fromStdString(count.getTotalcountOfCustomers());
    ui->Ccount->setText(qstr);
}

void System::on_Rrefresh_clicked()
{
    CustomerRatings rates;
    float f = rates.getAvgOfRatings();
    QString qstr = QString::number(f);
    ui->Rcount->setText(qstr);
}

void System::on_Prefresh_clicked()
{
    countPackages count;
    int c= count.getTotalcountOfPackages();
    ui->Pcount->setText(QString::number(c));
}

void System::on_PRrefresh_clicked()
{
    Profit profit;
    profit.returnTotalProfit();
    ifstream File("C:/Users/ND.COM/Documents/TravelAgencyMSystem/Profit.txt");
    string pro;
    getline(File,pro);
    ui->PRcount->setText(QString::fromStdString(pro));
}

void System::on_Drefresh_clicked()
{
    Revenue rev;
    rev.returnTotalRevenue();
    ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/Revenue.txt");
    string revenue;
    getline(file,revenue);
    ui->Dcount->setText(QString::fromStdString(revenue));
}

void System::on_displayCustomers_clicked()
{
    ui->sortupname->show();
    ui->sortupid->show();
    displayCustomers dis;
    dis.display(ui->treeWidget);
}

void System::on_displayCustomerIcon_clicked()
{
    ui->sortupid->show();
    ui->sortupname->show();
    displayCustomers dis;
    dis.display(ui->treeWidget);
}

void System::on_addCustomer_clicked()
{
    addUsers* add = new addUsers();
    add->setModal(true);
    add->exec();
    delete add;
}
void System::on_addCustomerIcon_clicked()
{
    addUsers* add = new addUsers();
    add->setModal(true);
    add->exec();
    delete add;
}

void System::on_updateCustomer_clicked()
{
    updateUsers *update = new updateUsers();
    update->setModal(true);
    update->exec();
    delete update;
}

void System::on_updateCustomerIcon_clicked()
{
    updateUsers *update = new updateUsers();
    update->setModal(true);
    update->exec();
    delete update;
}

void System::on_searchCustomer_clicked()
{
    searchUsers *search = new searchUsers();
    search->setModal(true);
    search->exec();
    delete search;
}

void System::on_searchCustomerIcon_clicked()
{
    searchUsers *search = new searchUsers();
    search->setModal(true);
    search->exec();
    delete search;
}

void System::on_deleteCustomer_clicked()
{
    deleteUsers* del = new deleteUsers();
    del->setModal(true);
    del->exec();
    delete del;
}
void System::on_deleteCustomerIcon_clicked()
{
    deleteUsers* del = new deleteUsers();
    del->setModal(true);
    del->exec();
    delete del;
}

void System::on_signOutButton_clicked()
{
    Login* l = new Login();
    l->showMaximized();
    System::close();
}

void System::on_viewAdminButton_clicked()
{
    viewAdminInfo* view = new viewAdminInfo();
    view->setModal(true);
    view->exec();
    delete view;
}

void System::on_editAdminButton_clicked()
{
    editAdminInfo* edit = new editAdminInfo();
    edit->setModal(true);
    edit->exec();
    delete edit;
}

void System::on_displayPackage_clicked()
{
    ui->sortupprice->show();
    ui->sortuptravelers->show();
    displayPackages dis;
    dis.display(ui->treeWidgetP);
}

void System::on_displayPackageIcon_clicked()
{
    ui->sortupprice->show();
    ui->sortuptravelers->show();
    displayPackages dis;
    dis.display(ui->treeWidgetP);
}


void System::on_addPackage_clicked()
{
    addPackage* add = new addPackage();
    add->setModal(true);
    add->exec();
    delete add;
}


void System::on_updatePackage_clicked()
{
    updatePackage* update = new updatePackage();
    update->setModal(true);
    update->exec();
    delete update;
}


void System::on_updatePackageIcon_clicked()
{
    updatePackage* update = new updatePackage();
    update->setModal(true);
    update->exec();
    delete update;
}


void System::on_searchPackage_clicked()
{
    searchPackage* search = new searchPackage();
    search->setModal(true);
    search->exec();
    delete search;
}


void System::on_searchPackageIcon_clicked()
{
    searchPackage* search = new searchPackage();
    search->setModal(true);
    search->exec();
    delete search;
}


void System::on_deletePackage_clicked()
{
    deletePackage* del = new deletePackage();
    del->setModal(true);
    del->exec();
    delete del;
}


void System::on_deletePackageIcon_clicked()
{
    deletePackage* del = new deletePackage();
    del->setModal(true);
    del->exec();
    delete del;
}

void System::on_refresh_clicked()
{
    countCustomers count;
    QString qstr = QString::fromStdString(count.getTotalcountOfCustomers());
    ui->Ccount->setText(qstr);
    CustomerRatings rates;
    float f = rates.getAvgOfRatings();
    qstr = QString::number(f);
    ui->Rcount->setText(qstr);
    countPackages count1;
    int c= count1.getTotalcountOfPackages();
    ui->Pcount->setText(QString::number(c));
    Profit profit;
    profit.returnTotalProfit();
    ifstream File("C:/Users/ND.COM/Documents/TravelAgencyMSystem/Profit.txt");
    string pro;
    getline(File,pro);
    ui->PRcount->setText(QString::fromStdString(pro));
    Revenue rev;
    rev.returnTotalRevenue();
    ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/Revenue.txt");
    string revenue;
    getline(file,revenue);
    ui->Dcount->setText(QString::fromStdString(revenue));
}


void System::on_sortupid_clicked()
{
    if(idchecked==true){
        QIcon newIcon("C:/Users/ND.COM/Documents/TravelAgencyMSystem/sortdownarrow.png");
        ui->sortupid->setIcon(newIcon);
        idchecked =false;
        displayCustomersAccToDescId dis;
        dis.displayCustomersInDescId(ui->treeWidget);
    }
    else{
        QIcon newIcon("C:/Users/ND.COM/Documents/TravelAgencyMSystem/sortuparrow.png");
        ui->sortupid->setIcon(newIcon);
        idchecked=true;
        displayCustomers dis;
        dis.display(ui->treeWidget);
    }
}


void System::on_sortupname_clicked()
{
    if(namechecked==true){
        QIcon newIcon("C:/Users/ND.COM/Documents/TravelAgencyMSystem/sortdownarrow.png");
        ui->sortupname->setIcon(newIcon);
        namechecked =false;
        displayCustomersAccToAscDescName dis;
        dis.displayCustomersInAscDescName(ui->treeWidget, 1);
    }
    else{
        QIcon newIcon("C:/Users/ND.COM/Documents/TravelAgencyMSystem/sortuparrow.png");
        ui->sortupname->setIcon(newIcon);
        namechecked=true;
        displayCustomersAccToAscDescName dis;
        dis.displayCustomersInAscDescName(ui->treeWidget, 2);
    }
}


void System::on_sortupprice_clicked()
{
    if(pricechecked==true){
        QIcon newIcon("C:/Users/ND.COM/Documents/TravelAgencyMSystem/sortdownarrow.png");
        ui->sortupprice->setIcon(newIcon);
        pricechecked =false;
        displayPackagesAscDesc dis;
        dis.displayCustomersInAscDesc(ui->treeWidgetP, 1);
    }
    else{
        QIcon newIcon("C:/Users/ND.COM/Documents/TravelAgencyMSystem/sortuparrow.png");
        ui->sortupprice->setIcon(newIcon);
        pricechecked=true;
        displayPackagesAscDesc dis;
        dis.displayCustomersInAscDesc(ui->treeWidgetP, 2);
    }
}


void System::on_sortuptravelers_clicked()
{
    if(trachecked==true){
        QIcon newIcon("C:/Users/ND.COM/Documents/TravelAgencyMSystem/sortdownarrow.png");
        ui->sortuptravelers->setIcon(newIcon);
        trachecked =false;
        displayPackagesAscDesc dis;
        dis.displayCustomersInAscDesc(ui->treeWidgetP, 3);
    }
    else{
        QIcon newIcon("C:/Users/ND.COM/Documents/TravelAgencyMSystem/sortuparrow.png");
        ui->sortuptravelers->setIcon(newIcon);
        trachecked=true;
        displayPackagesAscDesc dis;
        dis.displayCustomersInAscDesc(ui->treeWidgetP, 4);
    }
}

