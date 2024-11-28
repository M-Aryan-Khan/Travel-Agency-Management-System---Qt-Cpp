#include "login.h"
#include "./ui_login.h"
#include <QString>
#include<QMessageBox>
#include <iostream>
#include <fstream>

using namespace std;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    showMaximized();
}

Login::~Login()
{
    delete ui;
}

void Login::on_LoginButton_clicked()
{
    ifstream infile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/admin.txt");
    string line,user,pass;
    while(getline(infile,line)){
        size_t pos1 = line.find('\t');
        size_t pos2 = line.find('\t',pos1+1);
        size_t pos3 = line.find('\t', pos2+1);
        size_t pos4 = line.find('\t', pos3+1);
        size_t pos5 = line.find('\t', pos4+1);
        size_t pos6 = line.find('\t', pos5+1);
        size_t pos7 = line.find('\t', pos6+1);
        size_t pos8 = line.find('\t', pos7+1);
        size_t pos9 = line.find('\t', pos8+1);

        user = line.substr(pos7+1,pos8 - pos7 -1);
        pass = line.substr(pos8+1,pos9- pos8 -1);
    }
    infile.close();

    string username = ui->EnterUsername->text().toStdString();
    string password = ui->EnterPassword->text().toStdString();

    if(username == user && password == pass){
        ui->IC_Teller->setText("");
        this->close();
        sys.showMaximized();
    }
    else {
        ui->IC_Teller->setText("Incorrect!");
    }
}

void Login::on_eye_clicked()
{
    if(ui->EnterPassword->echoMode() == QLineEdit::Password) {
        ui->EnterPassword->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->EnterPassword->setEchoMode(QLineEdit::Password);
    }
}

