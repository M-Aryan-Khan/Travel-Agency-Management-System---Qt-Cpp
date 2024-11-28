#ifndef SYSTEM_H
#define SYSTEM_H

#include <QMainWindow>
#include"addusers.h"
#include"deleteusers.h"
#include"searchusers.h"
#include"updateusers.h"
#include "viewadmininfo.h"
#include "editadmininfo.h"

namespace Ui {
class System;
}

class System : public QMainWindow
{
    Q_OBJECT

public:
    explicit System(QWidget *parent = nullptr);
    ~System();

private slots:
    void on_refresh_clicked();

private slots:
    void on_side_menu_open_clicked();

    void on_accLogo_clicked();

    void on_home_clicked();

    void on_customer_clicked();

    void on_Crefresh_clicked();

    void on_Rrefresh_clicked();

    void on_displayCustomers_clicked();

    void on_addCustomer_clicked();

    void on_updateCustomer_clicked();

    void on_searchCustomer_clicked();

    void on_deleteCustomer_clicked();

    void on_signOutButton_clicked();

    void on_addCustomerIcon_clicked();

    void on_updateCustomerIcon_clicked();

    void on_searchCustomerIcon_clicked();

    void on_deleteCustomerIcon_clicked();

    void on_adminInfoButton_clicked();

    void on_viewAdminButton_clicked();

    void on_displayCustomerIcon_clicked();

    void on_editAdminButton_clicked();

    void on_packages_clicked();

    void on_Drefresh_clicked();

    void on_PRrefresh_clicked();

    void on_displayPackage_clicked();

    void on_displayPackageIcon_clicked();

    void on_addPackage_clicked();

    void on_updatePackage_clicked();

    void on_updatePackageIcon_clicked();

    void on_searchPackage_clicked();

    void on_searchPackageIcon_clicked();

    void on_deletePackage_clicked();

    void on_deletePackageIcon_clicked();

    void on_Prefresh_clicked();

    void on_exit_clicked();

    void showTime();

    void on_sortupid_clicked();

    void on_sortupname_clicked();

    void on_sortupprice_clicked();

    void on_sortuptravelers_clicked();

private:
    Ui::System *ui;
    addUsers addUser;
    deleteUsers delUser;
    searchUsers seaUser;
    updateUsers upUser;
};

#endif // SYSTEM_H

