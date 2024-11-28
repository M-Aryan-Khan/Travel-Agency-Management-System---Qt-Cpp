#include "changepassword.h"
#include "ui_changepassword.h"
#include "editadmininfo.h"
#include "ui_editadmininfo.h"
#include <QMessageBox>
#include "admin.h"

changePassword::changePassword(Ui::editAdminInfo* edit,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changePassword),
    edit(edit)
{
    ui->setupUi(this);
    changePassword::setWindowFlags(Qt::CustomizeWindowHint);
}

changePassword::~changePassword()
{
    delete ui;
}

void changePassword::on_save_clicked()
{
    changePass chPass;
    chPass.callToChangePassword(ui,edit);
    close();
}


void changePassword::on_cancel_clicked()
{
    this->close();
}


void changePassword::on_eye_clicked()
{
    if(ui->oldPassword->echoMode() == QLineEdit::Password) {
        ui->oldPassword->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->oldPassword->setEchoMode(QLineEdit::Password);
    }
}


void changePassword::on_eye1_clicked()
{
    if(ui->newPassword->echoMode() == QLineEdit::Password) {
        ui->newPassword->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->newPassword->setEchoMode(QLineEdit::Password);
    }
}


void changePassword::on_eye2_clicked()
{
    if(ui->confirmPassword->echoMode() == QLineEdit::Password) {
        ui->confirmPassword->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->confirmPassword->setEchoMode(QLineEdit::Password);
    }
}



