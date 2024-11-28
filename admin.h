#ifndef ADMIN_H
#define ADMIN_H

#include <fstream>
#include "editadmininfo.h"
#include "ui_editadmininfo.h"
#include "changepassword.h"
#include "ui_changepassword.h"
#include "viewadmininfo.h"
#include "ui_viewadmininfo.h"
#include <QMessageBox>

using namespace std;

class Admin{
protected:
    virtual void setToRead(Ui::viewAdminInfo* ){}
    virtual void fillLines(Ui::viewAdminInfo* ){}
    virtual void view(Ui::viewAdminInfo* ){}
    virtual void changeP(Ui::changePassword *, Ui::editAdminInfo *){}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class viewAdmin : protected Admin{
protected:
    void setToRead(Ui::viewAdminInfo* ui,bool what){
        ui->firstName->setReadOnly(what);
        ui->middleName->setReadOnly(what);
        ui->lastName->setReadOnly(what);
        ui->birthday->setReadOnly(what);
        ui->contactInfo->setReadOnly(what);
        ui->emailaddress->setReadOnly(what);
        ui->dateOfHiring->setReadOnly(what);
        ui->username->setReadOnly(what);
        ui->password->setReadOnly(what);
    }

    void fillLines(Ui::viewAdminInfo* ui){
        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/admin.txt");
        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);
            size_t pos4 = line.find('\t', pos3+1);
            size_t pos5 = line.find('\t', pos4+1);
            size_t pos6 = line.find('\t', pos5+1);
            size_t pos7 = line.find('\t', pos6+1);
            size_t pos8 = line.find('\t', pos7+1);
            size_t pos9 = line.find('\t', pos8+1);

            string fname = line.substr(0, pos1);
            string mname = line.substr(pos1+1, pos2-pos1-1);
            string lname = line.substr(pos2+1, pos3-pos2-1);
            string dateOfBirth = line.substr(pos3+1, pos4-pos3-1);
            string emailaddress = line.substr(pos4+1, pos5-pos4-1);
            string contactInfo = line.substr(pos5+1, pos6-pos5-1);
            string dateOfhiring = line.substr(pos6+1, pos7-pos6-1);
            string username = line.substr(pos7+1, pos8-pos7-1);
            string password = line.substr(pos8+1, pos9-pos8-1);

            ui->firstName->setText(QString::fromStdString(fname));
            ui->middleName->setText(QString::fromStdString(mname));
            ui->lastName->setText(QString::fromStdString(lname));
            ui->birthday->setText(QString::fromStdString(dateOfBirth));
            ui->contactInfo->setText(QString::fromStdString(emailaddress));
            ui->emailaddress->setText(QString::fromStdString(contactInfo));
            ui->dateOfHiring->setText(QString::fromStdString(dateOfhiring));
            ui->username->setText(QString::fromStdString(username));
            ui->password->setText(QString::fromStdString(password));
        }
        file.close();
    }

    void view(Ui::viewAdminInfo* ui){
        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/admin.txt");
        if (file.is_open()) {
            if (file.peek() == ifstream::traits_type::eof()) {
                ui->firstName->setText("admin");
                ui->middleName->setText("");
                ui->lastName->setText("");
                ui->birthday->setText("01/01/01");
                ui->contactInfo->setText("0000-0000000");
                ui->emailaddress->setText("123@gmail.com");
                ui->dateOfHiring->setText("01/01/01");
                ui->username->setText("admin");
                ui->password->setText("admin");
                setToRead(ui,true);
            }
            else {
                fillLines(ui);
                setToRead(ui,true);
            }
        }
        file.close();
    }

public:
    void viewAdmininfo(Ui::viewAdminInfo* ui){
        view(ui);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class editAdmin : protected Admin{
protected:
    void setToRead(Ui::editAdminInfo* ui,bool what){
        ui->firstName->setReadOnly(what);
        ui->middleName->setReadOnly(what);
        ui->lastName->setReadOnly(what);
        ui->birthday->setReadOnly(what);
        ui->contactInfo->setReadOnly(what);
        ui->emailaddress->setReadOnly(what);
        ui->dateOfHiring->setReadOnly(what);
        ui->username->setReadOnly(what);
    }

    void fillLines(Ui::editAdminInfo* ui){
        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/admin.txt");
        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);
            size_t pos4 = line.find('\t', pos3+1);
            size_t pos5 = line.find('\t', pos4+1);
            size_t pos6 = line.find('\t', pos5+1);
            size_t pos7 = line.find('\t', pos6+1);
            size_t pos8 = line.find('\t', pos7+1);
            size_t pos9 = line.find('\t', pos8+1);

            string fname = line.substr(0, pos1);
            string mname = line.substr(pos1+1, pos2-pos1-1);
            string lname = line.substr(pos2+1, pos3-pos2-1);
            string dateOfBirth = line.substr(pos3+1, pos4-pos3-1);
            string emailaddress = line.substr(pos4+1, pos5-pos4-1);
            string contactInfo = line.substr(pos5+1, pos6-pos5-1);
            string dateOfhiring = line.substr(pos6+1, pos7-pos6-1);
            string username = line.substr(pos7+1, pos8-pos7-1);
            string password = line.substr(pos8+1, pos9-pos8-1);

            ui->firstName->setText(QString::fromStdString(fname));
            ui->middleName->setText(QString::fromStdString(mname));
            ui->lastName->setText(QString::fromStdString(lname));
            ui->birthday->setText(QString::fromStdString(dateOfBirth));
            ui->contactInfo->setText(QString::fromStdString(emailaddress));
            ui->emailaddress->setText(QString::fromStdString(contactInfo));
            ui->dateOfHiring->setText(QString::fromStdString(dateOfhiring));
            ui->username->setText(QString::fromStdString(username));
            ui->password->setText(QString::fromStdString(password));
        }
        file.close();
    }

    void view(Ui::editAdminInfo* ui){
        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/admin.txt");
        if (file.is_open()) {
            if (file.peek() == ifstream::traits_type::eof()) {
                ui->firstName->setText("admin");
                ui->middleName->setText("");
                ui->lastName->setText("");
                ui->birthday->setText("01/01/01");
                ui->contactInfo->setText("0000-0000000");
                ui->emailaddress->setText("123@gmail.com");
                ui->dateOfHiring->setText("01/01/01");
                ui->username->setText("admin");
                ui->password->setText("admin");
                setToRead(ui,false);
                ui->password->setReadOnly(true);
            }
            else {
                fillLines(ui);
                setToRead(ui,false);
                ui->password->setReadOnly(true);
            }
        }
        file.close();
    }

    void saveInfo(Ui::editAdminInfo* ui){

        string fname = ui->firstName->text().toStdString();
        string mname = ui->middleName->text().toStdString();
        string lname = ui->lastName->text().toStdString();
        string birthday = ui->birthday->text().toStdString();
        string  emailAddress = ui->emailaddress->text().toStdString();
        string contactinfo = ui->contactInfo->text().toStdString();
        string dateofhiring = ui->dateOfHiring->text().toStdString();
        string username = ui->username->text().toStdString();
        string password = ui->password->text().toStdString();

        ofstream File("C:/Users/ND.COM/Documents/TravelAgencyMSystem/admin.txt", ofstream::trunc);
        File.close();
        ofstream outFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/admin.txt", ios::app);
        outFile << fname << "\t" << mname << "\t" << lname << "\t" << birthday << "\t" << emailAddress << "\t" << contactinfo << "\t"
                << dateofhiring << "\t" << username << "\t" << password << endl;
        outFile.close();
    }

public:
    void editAdminInfo(Ui::editAdminInfo* ui){
        view(ui);
    }
    void saveAdminInfo(Ui::editAdminInfo* ui){
        saveInfo(ui);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class changePass : protected Admin{
    void changeP(Ui::changePassword *change, Ui::editAdminInfo *edit){
        if(edit->password->text() == change->oldPassword->text()){
            if(change->newPassword->text() == change->confirmPassword->text()){
                QMessageBox::information(nullptr,"Succesul", "chnage password successfully");
                string fname = edit->firstName->text().toStdString();
                string mname = edit->middleName->text().toStdString();
                string lname = edit->lastName->text().toStdString();
                string birthday = edit->birthday->text().toStdString();
                string  emailAddress = edit->emailaddress->text().toStdString();
                string contactinfo = edit->contactInfo->text().toStdString();
                string dateofhiring = edit->dateOfHiring->text().toStdString();
                string username = edit->username->text().toStdString();
                string password = change->newPassword->text().toStdString();
                edit->password->setText(QString::fromStdString(password));

                ofstream File("C:/Users/ND.COM/Documents/TravelAgencyMSystem/admin.txt", ofstream::trunc);
                File.close();
                ofstream outFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/admin.txt", ios::app);
                outFile << fname << "\t" << mname << "\t" << lname << "\t" << birthday << "\t" << emailAddress << "\t" << contactinfo
                        << "\t" << dateofhiring << "\t" << username << "\t" << password << endl;
                outFile.close();

            }
            else
                QMessageBox::critical(nullptr, "Error", "password doesn't match");
        }
        else
            QMessageBox::critical(nullptr, "Error", "old password is incorrect");
    }
public:
    void callToChangePassword(Ui::changePassword *change, Ui::editAdminInfo *edit){
        changeP(change, edit);
    }
};

#endif // ADMIN_H
