#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "addusers.h"
#include "ui_addusers.h"
#include "searchusers.h"
#include "ui_searchusers.h"
#include "ui_deleteusers.h"
#include "deleteusers.h"
#include "ui_updateusers.h"
#include "updateusers.h"
#include "tripPackages.h"
#include <fstream>
#include <string>
#include <iostream>
#include <QHeaderView>
#include <QTreeWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QIntValidator>
#include <QValidator>

using namespace std;
class Customer{
protected:
    virtual void getCustomers(QTreeWidget*){}
    virtual int returnTotalCustomers(){return 1;}
    virtual float returnRatings(){return 0.0;}
    virtual void returnRevenue(){return;}
    virtual void returnProfit(){return;}
    virtual bool add(Ui::addUsers *){return 1;}
    virtual void search(Ui::searchUsers *){}
    virtual void Delete(Ui::deleteUsers *){}
    virtual void fill(Ui::updateUsers *){}
    virtual bool update(Ui::updateUsers *){return 1;}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class NodeP {
public:
    int id;
    string name;
    string passport;
    string contact;
    string package;
    int NumOfTravellers;
    NodeP* next;

    NodeP() {}

    NodeP(int id, const string& name, const string& passport, const string& contact, const string& package, int NumOfTravellers) {
        this->id = id;
        this->name = name;
        this->passport = passport;
        this->contact = contact;
        this->package = package;
        this->NumOfTravellers = NumOfTravellers;
        next = NULL;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class displayCustomers : protected Customer{
    void getCustomers(QTreeWidget* ui) override{
        ui->setColumnCount(6);
        QFont font("Century Gothic", 15, QFont::Bold);
        ui->model()->setHeaderData(0, Qt::Horizontal, "   ID", Qt::DisplayRole);
        ui->model()->setHeaderData(0, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(1, Qt::Horizontal, "Name", Qt::DisplayRole);
        ui->model()->setHeaderData(1, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(2, Qt::Horizontal, "Passport Number", Qt::DisplayRole);
        ui->model()->setHeaderData(2, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(3, Qt::Horizontal, "Contact Info", Qt::DisplayRole);
        ui->model()->setHeaderData(3, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(4, Qt::Horizontal, "Package", Qt::DisplayRole);
        ui->model()->setHeaderData(4, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(5, Qt::Horizontal, "Number Of Travellers", Qt::DisplayRole);
        ui->model()->setHeaderData(5, Qt::Horizontal, font, Qt::FontRole);
        ui->setColumnWidth(0, 90);
        ui->setColumnWidth(1, 250);
        ui->setColumnWidth(2, 200);
        ui->setColumnWidth(3, 150);
        ui->setColumnWidth(4, 350);
        ui->setColumnWidth(5, 250);
        ui->header()->setSectionResizeMode(QHeaderView::Fixed);
        QHeaderView* header = ui->header();
        header->setDefaultAlignment(Qt::AlignHCenter);
        ui->setStyleSheet("QTreeView::item { border-right: 1px solid #000; }");

        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt");
        string line;
        ui->clear();

        while (getline(inFile, line)) {

            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);
            size_t pos4 = line.find('\t', pos3+1);
            size_t pos5 = line.find('\t', pos4+1);
            size_t pos6 = line.find('\t', pos5+1);
            size_t pos7 = line.find('\t', pos6+1);
            size_t pos8 = line.find('\t', pos7+1);
            size_t pos9 = line.find('\t', pos8+1);
            size_t pos10 = line.find('\t', pos9+1);
            size_t pos11 = line.find('\t', pos10+1);
            size_t pos12 = line.find('\t', pos11+1);
            size_t pos13 = line.find('\t', pos12+1);
            size_t pos14 = line.find('\t', pos13+1);
            size_t pos15 = line.find('\t', pos14+1);

            string id = line.substr(0, pos1);
            string fname = line.substr(pos1+1, pos2-pos1-1);
            string mname = line.substr(pos2+1, pos3-pos2-1);
            string lname = line.substr(pos3+1, pos4-pos3-1);
            string name = fname + " " + mname + " " + lname;
            string passport = line.substr(pos5+1, pos6-pos5-1);
            string contact = line.substr(pos11+1, pos12-pos11-1);
            string package = line.substr(pos14+1, pos15-pos14-1);
            string NumOfTravellers = line.substr(pos13+1, pos14-pos13-1);

            QTreeWidgetItem *item = new QTreeWidgetItem(ui);
            item->setText(0, QString::fromStdString(id));
            item->setText(1, QString::fromStdString(name));
            item->setText(2, QString::fromStdString(passport));
            item->setText(3, QString::fromStdString(contact));
            item->setText(4, QString::fromStdString(package));
            item->setText(5, QString::fromStdString(NumOfTravellers));

            for (int i = 0; i < ui->columnCount(); i++) {
                item->setTextAlignment(i, Qt::AlignHCenter);
                item->setFont(i, QFont("century-gothic", 11, QFont::Bold));
            }

            ui->addTopLevelItem(item);
        }

        inFile.close();
    }

public:
    void display(QTreeWidget *ui){
        getCustomers(ui);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class displayCustomersAccToDescId {
protected:
    NodeP* merge(NodeP* left, NodeP* right) {
        NodeP* result = NULL;

        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        if (left->id >= right->id) {
            result = left;
            result->next = merge(left->next, right);
        }
        else {
            result = right;
            result->next = merge(left, right->next);
        }

        return result;
    }

    NodeP* mergeSort(NodeP* head) {
        if (head == NULL || head->next == NULL)
            return head;

        NodeP* middle = getMiddle(head);
        NodeP* nextToMiddle = middle->next;
        middle->next = NULL;

        NodeP* left = mergeSort(head);
        NodeP* right = mergeSort(nextToMiddle);

        head = merge(left, right);

        return head;
    }


    NodeP* getMiddle(NodeP* head) {
        if (head == NULL)
            return head;

        NodeP* slow = head;
        NodeP* fast = head->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        return slow;
    }

    NodeP* getIdStoreInLL(NodeP*& head, NodeP*& tail,int id, const string& name, const string& passport, const string& contact, const string& package, int NumOfTravellers) {
        NodeP* newNodeP = new NodeP(id, name, passport, contact, package, NumOfTravellers);
        if (head == NULL) {
            head = newNodeP;
            tail = newNodeP;
        }
        else {
            tail->next = newNodeP;
            tail = newNodeP;
        }
        return tail;
    }

    NodeP* readFromFile() {
        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt");
        string line;
        NodeP* head = NULL;
        NodeP* tail = head;
        while (getline(inFile, line)) {
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);
            size_t pos4 = line.find('\t', pos3+1);
            size_t pos5 = line.find('\t', pos4+1);
            size_t pos6 = line.find('\t', pos5+1);
            size_t pos7 = line.find('\t', pos6+1);
            size_t pos8 = line.find('\t', pos7+1);
            size_t pos9 = line.find('\t', pos8+1);
            size_t pos10 = line.find('\t', pos9+1);
            size_t pos11 = line.find('\t', pos10+1);
            size_t pos12 = line.find('\t', pos11+1);
            size_t pos13 = line.find('\t', pos12+1);
            size_t pos14 = line.find('\t', pos13+1);
            size_t pos15 = line.find('\t', pos14+1);

            string idStr = line.substr(0, pos1);
            string fname = line.substr(pos1+1, pos2-pos1-1);
            string mname = line.substr(pos2+1, pos3-pos2-1);
            string lname = line.substr(pos3+1, pos4-pos3-1);
            string name = fname + " " + mname + " " + lname;
            string passport = line.substr(pos5+1, pos6-pos5-1);
            string contact = line.substr(pos11+1, pos12-pos11-1);
            string package = line.substr(pos14+1, pos15-pos14-1);
            string NumOfTravellersStr = line.substr(pos13+1, pos14-pos13-1);
            int id = stoi(idStr);
            int NumOfTravellers = stoi(NumOfTravellersStr);
            tail = getIdStoreInLL(head, tail, id, name, passport, contact, package, NumOfTravellers);
        }
        head = mergeSort(head);
        inFile.close();
        return head;
    }

    void Display(QTreeWidget *ui){
        ui->setColumnCount(6);
        QFont font("Century Gothic", 15, QFont::Bold);
        ui->model()->setHeaderData(0, Qt::Horizontal, "   ID", Qt::DisplayRole);
        ui->model()->setHeaderData(0, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(1, Qt::Horizontal, "Name", Qt::DisplayRole);
        ui->model()->setHeaderData(1, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(2, Qt::Horizontal, "Passport Number", Qt::DisplayRole);
        ui->model()->setHeaderData(2, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(3, Qt::Horizontal, "Contact Info", Qt::DisplayRole);
        ui->model()->setHeaderData(3, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(4, Qt::Horizontal, "Package", Qt::DisplayRole);
        ui->model()->setHeaderData(4, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(5, Qt::Horizontal, "Number Of Travellers", Qt::DisplayRole);
        ui->model()->setHeaderData(5, Qt::Horizontal, font, Qt::FontRole);
        ui->setColumnWidth(0, 90);
        ui->setColumnWidth(1, 250);
        ui->setColumnWidth(2, 200);
        ui->setColumnWidth(3, 150);
        ui->setColumnWidth(4, 350);
        ui->setColumnWidth(5, 250);
        ui->header()->setSectionResizeMode(QHeaderView::Fixed);
        QHeaderView* header = ui->header();
        header->setDefaultAlignment(Qt::AlignHCenter);
        ui->setStyleSheet("QTreeView::item { border-right: 1px solid #000; }");

        ui->clear();
        NodeP*head = readFromFile();
        NodeP* temp = head;
        while (temp!=NULL) {
            string id = to_string(temp->id);
            string name = temp->name;
            string passport = temp->passport;
            string contact = temp->contact;
            string package = temp->package;
            string NumOfTravellers = to_string(temp->NumOfTravellers);
            QTreeWidgetItem *item = new QTreeWidgetItem(ui);
            item->setText(0, QString::fromStdString(id));
            item->setText(1, QString::fromStdString(name));
            item->setText(2, QString::fromStdString(passport));
            item->setText(3, QString::fromStdString(contact));
            item->setText(4, QString::fromStdString(package));
            item->setText(5, QString::fromStdString(NumOfTravellers));

            for (int i = 0; i < ui->columnCount(); i++) {
                item->setTextAlignment(i, Qt::AlignHCenter);
                item->setFont(i, QFont("century-gothic", 11, QFont::Bold));
            }
            ui->addTopLevelItem(item);
            temp=temp->next;
        }

    }
public:
    void displayCustomersInDescId(QTreeWidget *ui){
        Display(ui);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class displayCustomersAccToAscDescName{
protected:
    void swapData(NodeP& a, NodeP& b) {
        swap(a.name, b.name);
        swap(a.id, b.id);
        swap(a.passport,b.passport);
        swap(a.contact,b.contact);
        swap(a.package,b.package);
        swap(a.NumOfTravellers,b.NumOfTravellers);
    }
    NodeP* selectionSortDescending(NodeP* head) {
        if (head == NULL){
            return nullptr;
        }

        NodeP* current = head;

        while (current) {
            NodeP* maxNodeP = current;
            NodeP* temp = current->next;

            while (temp) {
                if (temp->name > maxNodeP->name) {
                    maxNodeP = temp;
                }
                temp = temp->next;
            }

            swapData(*current, *maxNodeP);

            current = current->next;
        }
        return head;
    }
    NodeP* selectionSortAscending(NodeP* head) {
        if (head == NULL){
            return nullptr;
        }

        NodeP* current = head;

        while (current) {
            NodeP* minNodeP = current;
            NodeP* temp = current->next;

            while (temp) {
                if (temp->name < minNodeP->name) {
                    minNodeP = temp;
                }
                temp = temp->next;
            }

            swapData(*current, *minNodeP);

            current = current->next;
        }
        return head;
    }
    NodeP* getIdStoreInLL(NodeP*& head, NodeP*& tail,int id, const string& name, const string& passport, const string& contact, const string& package, int NumOfTravellers) {
        NodeP* newNodeP = new NodeP(id, name, passport, contact, package, NumOfTravellers);
        if (head == NULL) {
            head = newNodeP;
            tail = newNodeP;
        }
        else {
            tail->next = newNodeP;
            tail = newNodeP;
        }
        return tail;
    }
    NodeP* readFromFile(int doS) {
        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt");
        string line;
        NodeP* head = NULL;
        NodeP* tail = head;
        while (getline(inFile, line)) {
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);
            size_t pos4 = line.find('\t', pos3+1);
            size_t pos5 = line.find('\t', pos4+1);
            size_t pos6 = line.find('\t', pos5+1);
            size_t pos7 = line.find('\t', pos6+1);
            size_t pos8 = line.find('\t', pos7+1);
            size_t pos9 = line.find('\t', pos8+1);
            size_t pos10 = line.find('\t', pos9+1);
            size_t pos11 = line.find('\t', pos10+1);
            size_t pos12 = line.find('\t', pos11+1);
            size_t pos13 = line.find('\t', pos12+1);
            size_t pos14 = line.find('\t', pos13+1);
            size_t pos15 = line.find('\t', pos14+1);

            string idStr = line.substr(0, pos1);
            string fname = line.substr(pos1+1, pos2-pos1-1);
            string mname = line.substr(pos2+1, pos3-pos2-1);
            string lname = line.substr(pos3+1, pos4-pos3-1);
            string name = fname + " " + mname + " " + lname;
            string passport = line.substr(pos5+1, pos6-pos5-1);
            string contact = line.substr(pos11+1, pos12-pos11-1);
            string package = line.substr(pos14+1, pos15-pos14-1);
            string NumOfTravellersStr = line.substr(pos13+1, pos14-pos13-1);
            int id = stoi(idStr);
            int NumOfTravellers = stoi(NumOfTravellersStr);
            tail = getIdStoreInLL(head, tail, id, name, passport, contact, package, NumOfTravellers);
        }
        if(doS==1)
            head = selectionSortDescending(head);
        else
            head = selectionSortAscending(head);
        inFile.close();
        return head;
    }
    void Display(QTreeWidget *ui, int doS){
        ui->setColumnCount(6);
        QFont font("Century Gothic", 15, QFont::Bold);
        ui->model()->setHeaderData(0, Qt::Horizontal, "   ID", Qt::DisplayRole);
        ui->model()->setHeaderData(0, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(1, Qt::Horizontal, "Name", Qt::DisplayRole);
        ui->model()->setHeaderData(1, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(2, Qt::Horizontal, "Passport Number", Qt::DisplayRole);
        ui->model()->setHeaderData(2, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(3, Qt::Horizontal, "Contact Info", Qt::DisplayRole);
        ui->model()->setHeaderData(3, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(4, Qt::Horizontal, "Package", Qt::DisplayRole);
        ui->model()->setHeaderData(4, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(5, Qt::Horizontal, "Number Of Travellers", Qt::DisplayRole);
        ui->model()->setHeaderData(5, Qt::Horizontal, font, Qt::FontRole);
        ui->setColumnWidth(0, 90);
        ui->setColumnWidth(1, 250);
        ui->setColumnWidth(2, 200);
        ui->setColumnWidth(3, 150);
        ui->setColumnWidth(4, 350);
        ui->setColumnWidth(5, 250);
        ui->header()->setSectionResizeMode(QHeaderView::Fixed);
        QHeaderView* header = ui->header();
        header->setDefaultAlignment(Qt::AlignHCenter);
        ui->setStyleSheet("QTreeView::item { border-right: 1px solid #000; }");

        ui->clear();
        NodeP*head = readFromFile(doS);
        NodeP* temp = head;
        while (temp!=NULL) {
            string id = to_string(temp->id);
            string name = temp->name;
            string passport = temp->passport;
            string contact = temp->contact;
            string package = temp->package;
            string NumOfTravellers = to_string(temp->NumOfTravellers);
            QTreeWidgetItem *item = new QTreeWidgetItem(ui);
            item->setText(0, QString::fromStdString(id));
            item->setText(1, QString::fromStdString(name));
            item->setText(2, QString::fromStdString(passport));
            item->setText(3, QString::fromStdString(contact));
            item->setText(4, QString::fromStdString(package));
            item->setText(5, QString::fromStdString(NumOfTravellers));

            for (int i = 0; i < ui->columnCount(); i++) {
                item->setTextAlignment(i, Qt::AlignHCenter);
                item->setFont(i, QFont("century-gothic", 11, QFont::Bold));
            }
            ui->addTopLevelItem(item);
            temp=temp->next;
        }

    }
public:
    void displayCustomersInAscDescName(QTreeWidget *ui, int doS){
        Display(ui, doS);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class countCustomers: protected Customer{
protected:
    int returnTotalCustomers() override{
        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt");
        string line;
        int i=0;
        while (getline(inFile, line)) {
            i++;
        }
        return i;
    }
public:
    string getTotalcountOfCustomers(){
        string str = to_string(returnTotalCustomers());
        return str;
    }

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CustomerRatings: protected Customer{
protected:
    float returnRatings() override{
        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt");
        string line;
        float ratings = 0.0;
        int count =0;
        while (getline(inFile, line)) {
            size_t pos = line.find_last_of('\t');
            if (pos != string::npos) {
                QString ratingStr = QString::fromStdString(line.substr(pos+1));
                float rating = ratingStr.toFloat();
                ratings += rating;
                count++;
            }
        }
        inFile.close();
        if (count > 0) {
            ratings /= count;
        }
        return roundf(ratings * 10) / 10.0f;
    }
public:
    float getAvgOfRatings(){
        float f = returnRatings();
        return f;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class addCustomers : protected Customer{
private:
    void makeInitialCapital(string& input){
        if (!isupper(input[0])) {
            input[0] = toupper(input[0]);
        }
    }
    void validateInput(Ui::addUsers *ui) {
        QString text = ui->passportEdit->text();
        QRegularExpression upperCaseRegex("^[A-Z]*$");
        QRegularExpressionMatch match = upperCaseRegex.match(text);

        string temp = text.toStdString();
        if (!match.hasMatch()) {

            int len= temp.length();
            for(int i=0;i<len;i++){
                if(temp[i]>= 'a' && temp [i] <= 'z'){
                    temp[i] = toupper(temp[i]);
                }
            }
        }
        text = QString::fromStdString(temp);
        ui->passportEdit->setText(text);
    }

    bool add(Ui::addUsers *ui) override{
        if(!ui->firstNameEdit->text().isEmpty() && !ui->lastNameEdit->text().isEmpty() && !ui->birthdayEdit->text().isEmpty() &&
            !ui->passportEdit->text().isEmpty() && !ui->passportExpEdit->text().isEmpty() && !ui->addressEdit->text().isEmpty() &&
            !ui->cityEdit->text().isEmpty() && !ui->postalEdit->text().isEmpty() && !ui->homePhoneEdit->text().isEmpty() &&
            !ui->countryEdit->text().isEmpty() && !ui->cellPhoneEdit->text().isEmpty() && !ui->numOfTravEdit->text().isEmpty())
        {
            QString Id;
            ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt");
            string line,line2;
            ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
            while (getline(inFile, line)) {
                while(getline(file,line2)){
                    size_t pos1 = line2.find('\t');
                    size_t pos2 = line2.find('\t', pos1+1);
                    size_t pos3 = line2.find('\t', pos2+1);

                    string packageName = line2.substr(pos2+1,pos3-pos2-1);
                    string maxTravellersAllowed = line2.substr(pos1+1,pos2-pos1-1);

                    if(packageName == ui->packageSelect->currentText().toStdString()){
                        if(ui->numOfTravEdit->text().toInt() > stoi(maxTravellersAllowed)){
                            QMessageBox::warning(nullptr, "Can't add", "Num. Of Travellers are exceeding from limit of package");
                            file.close();
                            return false;
                        }
                    }
                }
                file.close();
                size_t pos1 = line.find('\t');
                Id = QString::fromStdString(line.substr(0, pos1));
            }
            inFile.close();
            int id= Id.toInt();
            id++;
            string fname = ui->firstNameEdit->text().toStdString();
            makeInitialCapital(fname);
            string mname = ui->middleNameEdit->text().toStdString();
            makeInitialCapital(mname);
            string lname = ui->lastNameEdit->text().toStdString();
            makeInitialCapital(lname);
            string birthday = ui->birthdayEdit->text().toStdString();
            validateInput(ui);
            string passportNumber = ui->passportEdit->text().toStdString();
            string passportExpiryDate = ui->passportExpEdit->text().toStdString();
            string streetAddress = ui->addressEdit->text().toStdString();
            string city = ui->cityEdit->text().toStdString();
            string postalCode = ui->postalEdit->text().toStdString();
            string country = ui->countryEdit->text().toStdString();
            string homePhone = ui->homePhoneEdit->text().toStdString();
            string cellPhone = ui->cellPhoneEdit->text().toStdString();
            string numOfParticipants = ui->numOfTravEdit->text().toStdString();
            string package = ui->packageSelect->currentText().toStdString();
            string ratings = ui->ratingsSelect->currentText().toStdString();

            ofstream outFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt", ios::app);
            outFile << id << "\t" << fname << "\t" << mname << "\t" << lname << "\t" << birthday << "\t" << passportNumber << "\t" << passportExpiryDate << "\t"
                    << streetAddress << "\t" << city << "\t" << postalCode << "\t" << country << "\t" << homePhone << "\t" << cellPhone << "\t"
                    << numOfParticipants << "\t" << package << "\t" << ratings << endl;
            outFile.close();
            return true;
        }
        else{
            QMessageBox::information(nullptr, "Fill Form", "All Information Should Be Filled");
            return false;
        }

    }
public:
    bool addCustomer(Ui::addUsers *ui){
        return add(ui);
    }
    bool validateDateInput(Ui::addUsers *ui, int i) {
        if(i==1){
            QString text = ui->birthdayEdit->text();
            QRegularExpression dateRegex("^\\d{2}/\\d{2}/\\d{2}$");
            QRegularExpressionMatch match = dateRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
        else{
            QString text = ui->passportExpEdit->text();
            QRegularExpression dateRegex("^\\d{2}/\\d{2}/\\d{2}$");
            QRegularExpressionMatch match = dateRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
    }
    bool validateContactInput(Ui::addUsers *ui, int i) {
        if(i==1){
            QString text = ui->homePhoneEdit->text();
            QRegularExpression numberRegex("^\\d{4}-\\d{7}$");
            QRegularExpressionMatch match = numberRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
        else{
            QString text = ui->cellPhoneEdit->text();
            QRegularExpression numberRegex("^\\d{4}-\\d{7}$");
            QRegularExpressionMatch match = numberRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class searchCustomers : protected Customer{
private:
    void search(Ui::searchUsers *ui) override{
        ui->CustomerDetialsView->clear();
        string id;
        QString Id = ui->getCustomerIdEdit->text();
        id = Id.toStdString();
        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt");
        string line;
        while (getline(inFile, line)) {

            QFont font("Century Gothic", 12, QFont::Bold);
            size_t pos = line.find('\t');
            Id = QString::fromStdString(line.substr(0, pos));
            string ID = Id.toStdString();

            if(id == ID){
                ui->CustomerDetialsView->setColumnCount(11);
                for(int i =0;i<10;i++){
                    ui->CustomerDetialsView->model()->setHeaderData(i, Qt::Horizontal, font, Qt::FontRole);
                    ui->CustomerDetialsView->setColumnWidth(i, 250);
                }

                ui->CustomerDetialsView->setColumnWidth(0, 90);
                ui->CustomerDetialsView->setColumnWidth(0, 300);
                ui->CustomerDetialsView->header()->setSectionResizeMode(QHeaderView::Fixed);
                QHeaderView* header = ui->CustomerDetialsView->header();
                header->setDefaultAlignment(Qt::AlignHCenter);
                ui->CustomerDetialsView->setStyleSheet("QTreeView::item { border-right: 1px solid #000; }");
                size_t pos1 = line.find('\t', pos+1);
                size_t pos2 = line.find('\t', pos1+1);
                size_t pos3 = line.find('\t', pos2+1);
                size_t pos4 = line.find('\t', pos3+1);
                size_t pos5 = line.find('\t', pos4+1);
                size_t pos6 = line.find('\t', pos5+1);
                size_t pos7 = line.find('\t', pos6+1);
                size_t pos8 = line.find('\t', pos7+1);
                size_t pos9 = line.find('\t', pos8+1);
                size_t pos10 = line.find('\t', pos9+1);
                size_t pos11 = line.find('\t', pos10+1);
                size_t pos12 = line.find('\t', pos11+1);
                size_t pos13 = line.find('\t', pos12+1);
                size_t pos14 = line.find('\t', pos13+1);

                string fname = line.substr(pos+1, pos1-pos-1);
                string mname = line.substr(pos1+1, pos2-pos1-1);
                string lname = line.substr(pos2+1, pos3-pos2-1);
                string name = fname + " " + mname + " " + lname;
                string dateOfBirth =line.substr(pos3+1, pos4-pos3-1);
                string passport = line.substr(pos4+1, pos5-pos4-1);
                string passportExpiry = line.substr(pos5+1, pos6-pos5-1);
                string streetAddress = line.substr(pos6+1, pos7-pos6-1);
                string city = line.substr(pos7+1, pos8-pos7-1);
                string postalCode = line.substr(pos8+1, pos9-pos8-1);
                string country = line.substr(pos9+1, pos10-pos9-1);
                string address = streetAddress + ",\n" + city + ", " + postalCode +", " + country;
                string homeContact = line.substr(pos10+1, pos11-pos10-1);
                string cellContact = line.substr(pos11+1, pos12-pos11-1);
                string numOfTravellers = line.substr(pos12+1, pos13-pos12-1);
                string package = line.substr(pos13+1, pos14-pos13-1);

                QTreeWidgetItem *item = new QTreeWidgetItem(ui->CustomerDetialsView);
                Id = QString::fromStdString(id);
                item->setText(0, "ID: " + Id);
                item->setText(1, "Name: " + QString::fromStdString(name));
                item->setText(2, "DOB: " + QString::fromStdString(dateOfBirth));
                item->setText(3, "Passport: " + QString::fromStdString(passport));
                item->setText(4, "Passport Exp Date: " + QString::fromStdString(passportExpiry));
                item->setText(5, "Address: " + QString::fromStdString(address));
                item->setText(6, "Home Contact: " + QString::fromStdString(homeContact));
                item->setText(7, "Cell Contact: " + QString::fromStdString(cellContact));
                item->setText(8, "Number of Travellers: " + QString::fromStdString(numOfTravellers));
                item->setText(9, "Package: " + QString::fromStdString(package));
                for (int i = 0; i < 10; i++) {
                    item->setTextAlignment(i, Qt::AlignHCenter);
                    item->setFont(i, QFont("century-gothic", 10, QFont::Bold));
                }
                ui->CustomerDetialsView->addTopLevelItem(item);
                inFile.close();
                return;
            }
        }
        QMessageBox::critical(nullptr, "Error", "Customer record not found.");
    }
public:
    void searchCustomer(Ui::searchUsers *ui){
        search(ui);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class deleteCustomers : protected Customer{
private:
    void Delete(Ui::deleteUsers *ui) override{
        if(ui->checkBox->isChecked()){
            string filename = "C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt";
            QString id = ui->getIdEdit->text();
            ifstream inFile(filename);
            ofstream outFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/temp.txt");
            string line;
            while (getline(inFile, line)) {
                size_t pos = line.find('\t');
                QString Id = QString::fromStdString(line.substr(0, pos));
                if(Id.toStdString()==id.toStdString()){
                    QMessageBox::information(nullptr, "Info", "Successfully Deleted");
                   continue;
                }
                outFile << line << endl;
            }
            inFile.close();
            outFile.close();

            remove(filename.c_str());

            rename("C:/Users/ND.COM/Documents/TravelAgencyMSystem/temp.txt", filename.c_str());
            return;
        }
        else {
            QMessageBox::critical(nullptr, "Error", "Check Confirmation box to Delete");
        }
    }
public:
    void deleteCustomer(Ui::deleteUsers *ui){
        return Delete(ui);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class updateCustomers : protected Customer{
private:
    void makeInitialCapital(string& input){
        if (!isupper(input[0])) {
            input[0] = toupper(input[0]);
        }
    }
    void validateInput(Ui::updateUsers *ui) {
        QString text = ui->passportEdit->text();
        QRegularExpression upperCaseRegex("^[A-Z]*$");
        QRegularExpressionMatch match = upperCaseRegex.match(text);

        string temp = text.toStdString();
        if (!match.hasMatch()) {

            int len= temp.length();
            for(int i=0;i<len;i++){
                if(temp[i]>= 'a' && temp [i] <= 'z'){
                   temp[i] = toupper(temp[i]);
                }
            }
        }
        text = QString::fromStdString(temp);
        ui->passportEdit->setText(text);
    }
    void fill(Ui::updateUsers *ui) override{
        QString Id = ui->getIdEdit->text();

        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt");
        string line;
        while (getline(inFile, line)) {
            size_t pos = line.find('\t');
            QString id = QString::fromStdString(line.substr(0, pos));

            if(Id.toStdString() == id.toStdString()){
                size_t pos2 = line.find('\t', pos+1);
                size_t pos3 = line.find('\t', pos2+1);
                size_t pos4 = line.find('\t', pos3+1);
                size_t pos5 = line.find('\t', pos4+1);
                size_t pos6 = line.find('\t', pos5+1);
                size_t pos7 = line.find('\t', pos6+1);
                size_t pos8 = line.find('\t', pos7+1);
                size_t pos9 = line.find('\t', pos8+1);
                size_t pos10 = line.find('\t', pos9+1);
                size_t pos11 = line.find('\t', pos10+1);
                size_t pos12 = line.find('\t', pos11+1);
                size_t pos13 = line.find('\t', pos12+1);
                size_t pos14 = line.find('\t', pos13+1);
                size_t pos15 = line.find('\t', pos14+1);
                size_t pos16 = line.find('\t', pos15+1);

                string fname = line.substr(pos+1, pos2-pos-1);
                string mname = line.substr(pos2+1, pos3-pos2-1);
                string lname = line.substr(pos3+1, pos4-pos3-1);
                string dateOfBirth =line.substr(pos4+1, pos5-pos4-1);
                string passport = line.substr(pos5+1, pos6-pos5-1);
                string passportExpiry = line.substr(pos6+1, pos7-pos6-1);
                string streetAddress = line.substr(pos7+1, pos8-pos7-1);
                string city = line.substr(pos8+1, pos9-pos8-1);
                string postalCode = line.substr(pos9+1, pos10-pos9-1);
                string country = line.substr(pos10+1, pos11-pos10-1);
                string homeContact = line.substr(pos11+1, pos12-pos11-1);
                string cellContact = line.substr(pos12+1, pos13-pos12-1);
                string numOfTravellers = line.substr(pos13+1, pos14-pos13-1);
                string packageName = line.substr(pos14+1, pos15-pos14-1);
                string ratings = line.substr(pos15+1, pos16-pos15-1);

                ui->firstNameEdit->setText(QString::fromStdString(fname));
                ui->lastNameEdit->setText(QString::fromStdString(lname));
                ui->middleNameEdit->setText(QString::fromStdString(mname));
                ui->birthdayEdit->setText(QString::fromStdString(dateOfBirth));
                ui->passportEdit->setText(QString::fromStdString(passport));
                ui->passportExpEdit->setText(QString::fromStdString(passportExpiry));
                ui->addressEdit->setText(QString::fromStdString(streetAddress));
                ui->cityEdit->setText(QString::fromStdString(city));
                ui->postalEdit->setText(QString::fromStdString(postalCode));
                ui->countryEdit->setText(QString::fromStdString(country));
                ui->homePhoneEdit->setText(QString::fromStdString(homeContact));
                ui->cellPhoneEdit->setText(QString::fromStdString(cellContact));
                ui->numOfTravEdit->setText(QString::fromStdString(numOfTravellers));
                countPackages countP;
                int count = countP.getTotalcountOfPackages();
                for(int i = 0; i < count; i++){
                    ui->packageSelect->setCurrentIndex(i);
                    string currentPackageName = ui->packageSelect->currentText().toStdString();
                    if(currentPackageName == packageName){
                        break;
                    }
                }
                for(int i = 0; i < count; i++){
                    ui->ratingsSelect->setCurrentIndex(i);
                    string currentRatings = ui->ratingsSelect->currentText().toStdString();
                    if(currentRatings == ratings){
                        break;
                    }
                }
                return;
            }
        }
    }

    bool update(Ui::updateUsers *ui) override{
        if(!ui->firstNameEdit->text().isEmpty() && !ui->lastNameEdit->text().isEmpty() && !ui->birthdayEdit->text().isEmpty() &&
            !ui->passportEdit->text().isEmpty() && !ui->passportExpEdit->text().isEmpty() && !ui->addressEdit->text().isEmpty() &&
            !ui->cityEdit->text().isEmpty() && !ui->postalEdit->text().isEmpty() && !ui->homePhoneEdit->text().isEmpty() &&
            !ui->countryEdit->text().isEmpty() && !ui->cellPhoneEdit->text().isEmpty() && !ui->numOfTravEdit->text().isEmpty())
        {
            string filename = "C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt";
            QString id = ui->getIdEdit->text();
            ifstream inFile(filename);
            ofstream outFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/temp.txt");
            string line,line2;
            while (getline(inFile, line)) {
                size_t pos = line.find('\t');
                QString Id = QString::fromStdString(line.substr(0, pos));
                if(Id.toStdString()==id.toStdString()){
                    if(Id.toStdString() == id.toStdString()) {
                        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
                            while(getline(file,line2)){
                                size_t pos1 = line2.find('\t');
                                size_t pos2 = line2.find('\t', pos1+1);
                                size_t pos3 = line2.find('\t', pos2+1);

                                string packageName = line2.substr(pos2+1,pos3-pos2-1);
                                string maxTravellersAllowed = line2.substr(pos1+1,pos2-pos1-1);

                                if(packageName == ui->packageSelect->currentText().toStdString()){
                                    if(ui->numOfTravEdit->text().toInt() > stoi(maxTravellersAllowed)){
                                        QMessageBox::warning(nullptr, "Can't add", "Num. Of Travellers are exceeding from limit");
                                        file.close();
                                        return false;
                                    }
                                }
                            }
                            file.close();
                    }
                    string ID = Id.toStdString();
                    string fname = ui->firstNameEdit->text().toStdString();
                    makeInitialCapital(fname);
                    string mname = ui->middleNameEdit->text().toStdString();
                    makeInitialCapital(mname);
                    string lname = ui->lastNameEdit->text().toStdString();
                    makeInitialCapital(lname);
                    string birthday = ui->birthdayEdit->text().toStdString();
                    validateInput(ui);
                    string passportNumber = ui->passportEdit->text().toStdString();
                    string passportExpiryDate = ui->passportExpEdit->text().toStdString();
                    string streetAddress = ui->addressEdit->text().toStdString();
                    string city = ui->cityEdit->text().toStdString();
                    string postalCode = ui->postalEdit->text().toStdString();
                    string country = ui->countryEdit->text().toStdString();
                    string homePhone = ui->homePhoneEdit->text().toStdString();
                    string cellPhone = ui->cellPhoneEdit->text().toStdString();
                    string numOfParticipants = ui->numOfTravEdit->text().toStdString();
                    string package = ui->packageSelect->currentText().toStdString();
                    string ratings = ui->ratingsSelect->currentText().toStdString();

                    outFile << ID << "\t" << fname << "\t" << mname << "\t" << lname << "\t" << birthday << "\t" << passportNumber << "\t" << passportExpiryDate << "\t"
                            << streetAddress << "\t" << city << "\t" << postalCode << "\t" << country << "\t" << homePhone << "\t" << cellPhone << "\t"
                            << numOfParticipants << "\t" << package << "\t" << ratings << endl;
                    continue;
                }
                outFile << line << endl;
            }
            inFile.close();
            outFile.close();

            remove(filename.c_str());

            rename("C:/Users/ND.COM/Documents/TravelAgencyMSystem/temp.txt", filename.c_str());
            return true;
        }
        else{
            QMessageBox::information(nullptr, "Fill Form", "All Information Should Be Filled");
            return false;
        }
    }
public:
    void fillEdit(Ui::updateUsers *ui){
        fill(ui);
    }
    bool updateCustomer(Ui::updateUsers *ui){
        return update(ui);
    }
    bool validateDateInput(Ui::updateUsers *ui, int i) {
        if(i==1){
            QString text = ui->birthdayEdit->text();
            QRegularExpression dateRegex("^\\d{2}/\\d{2}/\\d{2}$");
            QRegularExpressionMatch match = dateRegex.match(text);
            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
        else{
            QString text = ui->passportExpEdit->text();
            QRegularExpression dateRegex("^\\d{2}/\\d{2}/\\d{2}$");
            QRegularExpressionMatch match = dateRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }

    }
    bool validateContactInput(Ui::updateUsers *ui, int i) {
        if(i==1){
            QString text = ui->homePhoneEdit->text();
            QRegularExpression numberRegex("^\\d{4}-\\d{7}$");
            QRegularExpressionMatch match = numberRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
        else{
            QString text = ui->cellPhoneEdit->text();
            QRegularExpression numberRegex("^\\d{4}-\\d{7}$");
            QRegularExpressionMatch match = numberRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Revenue : protected Customer {

    void returnRevenue() override{
        ifstream inCFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt");
        string line1;
        int revenue = 0;
        while(getline(inCFile,line1)){
            ifstream inPFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
            string line2;
            size_t pos1 = line1.find('\t');
            size_t pos2 = line1.find('\t', pos1+1);
            size_t pos3 = line1.find('\t', pos2+1);
            size_t pos4 = line1.find('\t', pos3+1);
            size_t pos5 = line1.find('\t', pos4+1);
            size_t pos6 = line1.find('\t', pos5+1);
            size_t pos7 = line1.find('\t', pos6+1);
            size_t pos8 = line1.find('\t', pos7+1);
            size_t pos9 = line1.find('\t', pos8+1);
            size_t pos10 = line1.find('\t', pos9+1);
            size_t pos11 = line1.find('\t', pos10+1);
            size_t pos12 = line1.find('\t', pos11+1);
            size_t pos13 = line1.find('\t', pos12+1);
            size_t pos14 = line1.find('\t', pos13+1);
            size_t pos15 = line1.find('\t', pos14+1);

            string package = line1.substr(pos14+1,pos15-pos14-1);
            string num = line1.substr(pos13+1, pos14-pos13-1);
            int numOfTravellers = stoi(num);

            while(getline(inPFile,line2)){
                size_t posp1 = line2.find('\t');
                size_t posp2 = line2.find('\t', posp1+1);
                size_t posp3 = line2.find('\t', posp2+1);

                string packageName = line2.substr(posp2+1,posp3-posp2-1);

                if(package == packageName){
                    string price = line2.substr(0,posp1);
                    int priceOfPackage = stoi(price);
                    revenue += (numOfTravellers * priceOfPackage);
                }
                else
                    continue;
            }
            inPFile.close();
        }
        inCFile.close();
        ofstream File("C:/Users/ND.COM/Documents/TravelAgencyMSystem/Revenue.txt", ofstream::trunc);
        File.close();
        ofstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/Revenue.txt", ios::app);
        file << revenue;
    }
public:
    void returnTotalRevenue(){
        returnRevenue();
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Profit : protected Customer {

    void returnProfit() override{
        ifstream inCFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/customersRecord.txt");
        string line1;
        float revenue = 0;
        while(getline(inCFile,line1)){
            ifstream inPFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
            string line2;
            size_t pos1 = line1.find('\t');
            size_t pos2 = line1.find('\t', pos1+1);
            size_t pos3 = line1.find('\t', pos2+1);
            size_t pos4 = line1.find('\t', pos3+1);
            size_t pos5 = line1.find('\t', pos4+1);
            size_t pos6 = line1.find('\t', pos5+1);
            size_t pos7 = line1.find('\t', pos6+1);
            size_t pos8 = line1.find('\t', pos7+1);
            size_t pos9 = line1.find('\t', pos8+1);
            size_t pos10 = line1.find('\t', pos9+1);
            size_t pos11 = line1.find('\t', pos10+1);
            size_t pos12 = line1.find('\t', pos11+1);
            size_t pos13 = line1.find('\t', pos12+1);
            size_t pos14 = line1.find('\t', pos13+1);
            size_t pos15 = line1.find('\t', pos14+1);

            string package = line1.substr(pos14+1,pos15-pos14-1);
            string num = line1.substr(pos13+1, pos14-pos13-1);
            int numOfTravellers = stoi(num);

            while(getline(inPFile,line2)){
                size_t posp1 = line2.find('\t');
                size_t posp2 = line2.find('\t', posp1+1);
                size_t posp3 = line2.find('\t', posp2+1);

                string packageName = line2.substr(posp2+1,posp3-posp2-1);

                if(package == packageName){
                    string price = line2.substr(0,posp1);
                    int priceOfPackage = stoi(price);
                    if(numOfTravellers <=2 )
                        revenue += (numOfTravellers * priceOfPackage)*0.03;
                    else if(numOfTravellers >2 && numOfTravellers<=4 )
                        revenue += (numOfTravellers * priceOfPackage)*0.07;
                    if(numOfTravellers > 4 )
                        revenue += (numOfTravellers * priceOfPackage)*0.10;
                }
                else
                    continue;
            }
            inPFile.close();
        }
        inCFile.close();
        ofstream File("C:/Users/ND.COM/Documents/TravelAgencyMSystem/Profit.txt", ofstream::trunc);
        File.close();
        ofstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/Profit.txt", ios::app);
        file << revenue;
    }
public:
    void returnTotalProfit(){
        returnProfit();
    }
};

#endif // CUSTOMERS_H
