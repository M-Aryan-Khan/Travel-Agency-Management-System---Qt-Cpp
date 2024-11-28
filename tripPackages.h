#ifndef TRIPPACKAGES_H
#define TRIPPACKAGES_H
#include "addusers.h"
#include "ui_addusers.h"
#include "updateusers.h"
#include "ui_updateusers.h"
#include "ui_addpackage.h"
#include "updatepackage.h"
#include "ui_updatepackage.h"
#include "searchpackage.h"
#include "ui_searchpackage.h"
#include "deletepackage.h"
#include "ui_deletepackage.h"
#include "tripPackages.h"

#include <fstream>
#include <iostream>
#include <QHeaderView>
#include <QTreeWidget>
#include <QMessageBox>

using namespace std;

class packages{
protected:
    virtual void fillTripsNames(Ui::addUsers *){}
    virtual void fillTripsNames(Ui::updateUsers *){}
    virtual void fillTripsNames(Ui::updatePackage *){}
    virtual void fillTripsNames(Ui::searchPackage *){}
    virtual void fillTripsNames(Ui::deletePackage *){}
    virtual void showDescription(Ui::addUsers *){}
    virtual int returnTotalPackages(){return 1;}
    virtual void getPackages(QTreeWidget* ){}
    virtual bool add(Ui::addPackage *) {return 1;}
    virtual void fill(Ui::updatePackage *) {}
    virtual bool update(Ui::updatePackage *) {return 1;}
    virtual void search(Ui::searchPackage *){}
    virtual void Delete(Ui::deletePackage *) {}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Node {
public:
    string packageName;
    int price;
    int travellersAllowed;
    string duration;
    string bookingStarts;
    string departure;
    Node* next;
    Node() {}

    Node(const string &packageName, int price, int travellersAllowed, const string&duration, const string&bookingStarts, const string&departure) {
        this->packageName = packageName;
        this->price =price;
        this->travellersAllowed = travellersAllowed;
        this->duration = duration;
        this->bookingStarts = bookingStarts;
        this->departure = departure;
        next = NULL;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Fill : protected packages{
protected:
    void fillTripsNames(Ui::addUsers *ui) override{
        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
        string line;
        ui->packageSelect->clear();
        while(getline(file,line)){
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);

            string packageName = line.substr(pos2+1,pos3-pos2-1);

            ui->packageSelect->addItem(QString::fromStdString(packageName));
        }
    }

    void fillTripsNames(Ui::updateUsers *ui) override{
        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
        string line;
        ui->packageSelect->clear();
        while(getline(file,line)){
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);

            string packageName = line.substr(pos2+1,pos3-pos2-1);

            ui->packageSelect->addItem(QString::fromStdString(packageName));
        }
    }

    void fillTripsNames(Ui::updatePackage *ui) override{
        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
        string line;
        ui->packageSelect->clear();
        while(getline(file,line)){
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);

            string packageName = line.substr(pos2+1,pos3-pos2-1);

            ui->packageSelect->addItem(QString::fromStdString(packageName));
        }
    }

    void fillTripsNames(Ui::searchPackage *ui) override{
        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
        string line;
        ui->packageSelect->clear();
        while(getline(file,line)){
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);

            string packageName = line.substr(pos2+1,pos3-pos2-1);

            ui->packageSelect->addItem(QString::fromStdString(packageName));
        }
    }

    void fillTripsNames(Ui::deletePackage *ui) override{
        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
        string line;
        ui->packageSelect->clear();
        while(getline(file,line)){
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);

            string packageName = line.substr(pos2+1,pos3-pos2-1);

            ui->packageSelect->addItem(QString::fromStdString(packageName));
        }
    }

    void showDescription(Ui::addUsers *ui) override{
        ifstream file("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
        string line;
        ui->packageDescriptionShow->clear();
        QString PackageName = ui->packageSelect->currentText();
        string packageName = PackageName.toStdString();
        while(getline(file,line)){
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);
            size_t pos4 = line.find('\t', pos3+1);
            size_t pos5 = line.find('\t', pos4+1);
            size_t pos6 = line.find('\t', pos5+1);
            size_t pos7 = line.find('\t', pos6+1);
            size_t pos8 = line.find('\t', pos7+1);

            string pkgName = line.substr(pos2+1,pos3-pos2-1);

            if(packageName == pkgName){
                string description = line.substr(pos7+1,pos8-pos7-1);

                ui->packageDescriptionShow->addItem(QString::fromStdString(description));
                return;
            }
        }
    }

public:
    void FillTripsNames(Ui::addUsers *ui){
        fillTripsNames(ui);
    }
    void FillTripsNames(Ui::updateUsers *ui){
        fillTripsNames(ui);
    }
    void FillTripsNames(Ui::updatePackage *ui){
        fillTripsNames(ui);
    }
    void FillTripsNames(Ui::searchPackage *ui){
        fillTripsNames(ui);
    }
    void FillTripsNames(Ui::deletePackage *ui){
        fillTripsNames(ui);
    }
    void setDescriptionText(Ui::addUsers *ui){
        showDescription(ui);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class countPackages: protected packages{
protected:
    int returnTotalPackages() override{
        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
        string line;
        int i=0;
        while (getline(inFile, line)) {
            i++;
        }
        return i;
    }
public:
    int getTotalcountOfPackages(){
        return returnTotalPackages();
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class displayPackages : protected packages{
    void getPackages(QTreeWidget* ui) override{
        ui->setColumnCount(6);
        QFont font("Century Gothic", 15, QFont::Bold);
        ui->model()->setHeaderData(0, Qt::Horizontal, "Package Name", Qt::DisplayRole);
        ui->model()->setHeaderData(0, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(1, Qt::Horizontal, "Price", Qt::DisplayRole);
        ui->model()->setHeaderData(1, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(2, Qt::Horizontal, "Limit Allow", Qt::DisplayRole);
        ui->model()->setHeaderData(2, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(3, Qt::Horizontal, "Duration", Qt::DisplayRole);
        ui->model()->setHeaderData(3, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(4, Qt::Horizontal, "Booking", Qt::DisplayRole);
        ui->model()->setHeaderData(4, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(5, Qt::Horizontal, "Departure", Qt::DisplayRole);
        ui->model()->setHeaderData(5, Qt::Horizontal, font, Qt::FontRole);
        ui->setColumnWidth(0, 300);
        ui->setColumnWidth(1, 100);
        ui->setColumnWidth(2, 150);
        ui->setColumnWidth(3, 170);
        ui->setColumnWidth(4, 290);
        ui->setColumnWidth(5, 250);
        ui->header()->setSectionResizeMode(QHeaderView::Fixed);
        QHeaderView* header = ui->header();
        header->setDefaultAlignment(Qt::AlignHCenter);
        ui->setStyleSheet("QTreeView::item { border-right: 1px solid #000; }");

        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
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

            string packageName = line.substr(pos2+1, pos3-pos2-1);
            string price = line.substr(0, pos1);
            string travellersAllowed = line.substr(pos1+1, pos2-pos1-1);
            string duration = line.substr(pos4+1, pos5-pos4-1);
            string bookingStarts = line.substr(pos9+1, pos10-pos9-1);
            string departure = line.substr(pos10+1, pos11-pos10-1);

            QTreeWidgetItem *item = new QTreeWidgetItem(ui);
            item->setText(0, QString::fromStdString(packageName));
            item->setText(1, QString::fromStdString(price));
            item->setText(2, QString::fromStdString(travellersAllowed));
            item->setText(3, QString::fromStdString(duration));
            item->setText(4, QString::fromStdString(bookingStarts));
            item->setText(5, QString::fromStdString(departure));

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
        getPackages(ui);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class displayPackagesAscDesc{
protected:
    void swapData(Node& a, Node& b) {
        swap(a.packageName, b.packageName);
        swap(a.price, b.price);
        swap(a.travellersAllowed,b.travellersAllowed);
        swap(a.bookingStarts,b.bookingStarts);
        swap(a.departure,b.departure);
        swap(a.duration,b.duration);
    }
    Node* selectionSortDescending(Node* head) {
        if (head == NULL){
            return nullptr;
        }

        Node* current = head;

        while (current) {
            Node* maxNode = current;
            Node* temp = current->next;

            while (temp) {
                if (temp->travellersAllowed > maxNode->travellersAllowed) {
                    maxNode = temp;
                }
                temp = temp->next;
            }

            swapData(*current, *maxNode);

            current = current->next;
        }
        return head;
    }
    Node* selectionSortAscending(Node* head) {
        if (head == NULL){
            return nullptr;
        }

        Node* current = head;

        while (current) {
            Node* minNode = current;
            Node* temp = current->next;

            while (temp) {
                if (temp->travellersAllowed < minNode->travellersAllowed) {
                    minNode = temp;
                }
                temp = temp->next;
            }

            swapData(*current, *minNode);

            current = current->next;
        }
        return head;
    }
    Node* insertionSortAsc(Node* head) {
        if (!head || !head->next) {
            return head;
        }
        Node* sorted = nullptr;

        while (head) {
            Node* current = head;
            head = head->next;

            if (!sorted || current->price < sorted->price) {
                current->next = sorted;
                sorted = current;
            }
            else {
                Node* temp = sorted;
                while (temp->next && temp->next->price < current->price) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }

        head = sorted;
        return head;
    }

    Node* insertionSortDesc(Node* head) {
        if (!head || !head->next) {
            return head;
        }
        Node* sorted = nullptr;

        while (head) {
            Node* current = head;
            head = head->next;

            if (!sorted || current->price > sorted->price) {
                current->next = sorted;
                sorted = current;
            }
            else {
                Node* temp = sorted;
                while (temp->next && temp->next->price > current->price) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }

        head = sorted;
        return head;
    }

    Node* getPackageStoreInLL(Node*&head, Node*&tail, const string &packageName, int price, int travellersAllowed, const string&duration, const string&bookingStarts, const string&departure) {
        Node* newNode = new Node(packageName,price,travellersAllowed,duration,bookingStarts,departure);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        return tail;
    }

    Node* readFromFile(int doS) {
        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
        string line;
        Node* head = NULL;
        Node* tail = head;
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

            string packageName = line.substr(pos2+1, pos3-pos2-1);
            string price = line.substr(0, pos1);
            string travellersAllowed = line.substr(pos1+1, pos2-pos1-1);
            string duration = line.substr(pos4+1, pos5-pos4-1);
            string bookingStarts = line.substr(pos9+1, pos10-pos9-1);
            string departure = line.substr(pos10+1, pos11-pos10-1);
            tail = getPackageStoreInLL(head, tail, packageName,stoi(price),stoi(travellersAllowed),duration, bookingStarts,departure);
        }
        if(doS == 1)
            head= insertionSortDesc(head);
        else if(doS==2)
            head = insertionSortAsc(head);
        else if(doS==3)
            head = selectionSortDescending(head);
        else
            head = selectionSortAscending(head);
        inFile.close();
        return head;
    }
    void Display(QTreeWidget *ui, int doS){
        ui->setColumnCount(6);
        QFont font("Century Gothic", 15, QFont::Bold);
        ui->model()->setHeaderData(0, Qt::Horizontal, "Package Name", Qt::DisplayRole);
        ui->model()->setHeaderData(0, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(1, Qt::Horizontal, "Price", Qt::DisplayRole);
        ui->model()->setHeaderData(1, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(2, Qt::Horizontal, "Limit Allow", Qt::DisplayRole);
        ui->model()->setHeaderData(2, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(3, Qt::Horizontal, "Duration", Qt::DisplayRole);
        ui->model()->setHeaderData(3, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(4, Qt::Horizontal, "Booking", Qt::DisplayRole);
        ui->model()->setHeaderData(4, Qt::Horizontal, font, Qt::FontRole);
        ui->model()->setHeaderData(5, Qt::Horizontal, "Departure", Qt::DisplayRole);
        ui->model()->setHeaderData(5, Qt::Horizontal, font, Qt::FontRole);
        ui->setColumnWidth(0, 300);
        ui->setColumnWidth(1, 100);
        ui->setColumnWidth(2, 150);
        ui->setColumnWidth(3, 170);
        ui->setColumnWidth(4, 290);
        ui->setColumnWidth(5, 250);
        ui->header()->setSectionResizeMode(QHeaderView::Fixed);
        QHeaderView* header = ui->header();
        header->setDefaultAlignment(Qt::AlignHCenter);
        ui->setStyleSheet("QTreeView::item { border-right: 1px solid #000; }");
        ui->clear();
        Node*head = readFromFile(doS);
        Node* temp = head;
        while (temp!=NULL) {
            string packageName = temp->packageName;
            string price = to_string(temp->price);
            string travellersAllowed = to_string(temp->travellersAllowed);
            string duration = temp->duration;
            string bookingStarts = temp->bookingStarts;
            string departure = temp->departure;
            QTreeWidgetItem *item = new QTreeWidgetItem(ui);
            item->setText(0, QString::fromStdString(packageName));
            item->setText(1, QString::fromStdString(price));
            item->setText(2, QString::fromStdString(travellersAllowed));
            item->setText(3, QString::fromStdString(duration));
            item->setText(4, QString::fromStdString(bookingStarts));
            item->setText(5, QString::fromStdString(departure));

            for (int i = 0; i < ui->columnCount(); i++) {
                item->setTextAlignment(i, Qt::AlignHCenter);
                item->setFont(i, QFont("century-gothic", 11, QFont::Bold));
            }
            ui->addTopLevelItem(item);
            temp=temp->next;
        }
    }
public:
    void displayCustomersInAscDesc(QTreeWidget *ui, int doS){
        Display(ui, doS);
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class addPackages : protected packages{
private:
    bool add(Ui::addPackage *ui) override{
        if(!ui->packageNameEdit->text().isEmpty() && !ui->bookingStartsEdit->text().isEmpty() && !ui->departureEdit->text().isEmpty() &&
            !ui->durationEdit->text().isEmpty() && !ui->foodEdit->text().isEmpty() && !ui->hotelEdit->text().isEmpty() &&
            !ui->NumOfTravellersEdit->text().isEmpty() && !ui->packageDescriptionEdit->text().isEmpty() && !ui->pricePerPersonEdit->text().isEmpty() &&
            !ui->transportEdit->text().isEmpty())
        {
            string packageName = ui->packageNameEdit->text().toStdString();
            string destination = ui->destinationEdit->text().toStdString();
            string price = ui->pricePerPersonEdit->text().toStdString();
            string numOfParticipants = ui->NumOfTravellersEdit->text().toStdString();
            string hotel = ui->hotelEdit->text().toStdString();
            string bookingStarts = ui->bookingStartsEdit->text().toStdString();
            string departure = ui->departureEdit->text().toStdString();
            string food = ui->foodEdit->text().toStdString();
            string transport = ui->transportEdit->text().toStdString();
            string duration = ui->durationEdit->text().toStdString();
            string packageDescription = ui->packageDescriptionEdit->text().toStdString();

            ofstream outFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt", ios::app);
            outFile << price << "\t" << numOfParticipants << "\t" << packageName << "\t" << destination << "\t" << duration << "\t"
                    << hotel << "\t" << transport << "\t"<< packageDescription << "\t" << food << "\t" << bookingStarts << "\t"
                    << departure << endl;
            outFile.close();
            return true;
        }
        else{
            QMessageBox::information(nullptr, "Fill Form", "All Information Should Be Filled");
            return false;
        }
    }
public:
    bool addPack(Ui::addPackage *ui){
        return add(ui);
    }
    bool validateInput(Ui::addPackage *ui, int i) {
        if(i==1){
            QString text = ui->bookingStartsEdit->text();
            QRegularExpression dateRegex("^\\d{1,2} to \\d{1,2} of [a-zA-Z]+$");
            QRegularExpressionMatch match = dateRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
        else if(i==2){
            QString text = ui->departureEdit->text();
            QRegularExpression dateRegex("^\\d{1,2} of [a-zA-Z]+$");
            QRegularExpressionMatch match = dateRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
        else{
            QString text = ui->durationEdit->text();
            QRegularExpression dateRegex("^\\d{1,2}\\s*Nights\\s*(and|&)\\s*\\d{1,2}\\s*Days$");
            QRegularExpressionMatch match = dateRegex.match(text);
            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class updatePackages : protected packages{
private:
    void fill(Ui::updatePackage *ui) override{
        string package = ui->packageSelect->currentText().toStdString();

        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
        string line;
        while (getline(inFile, line)) {
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);
            string packageName = line.substr(pos2+1, pos3-pos2-1);

            if(package == packageName){
                size_t pos4 = line.find('\t', pos3+1);
                size_t pos5 = line.find('\t', pos4+1);
                size_t pos6 = line.find('\t', pos5+1);
                size_t pos7 = line.find('\t', pos6+1);
                size_t pos8 = line.find('\t', pos7+1);
                size_t pos9 = line.find('\t', pos8+1);
                size_t pos10 = line.find('\t', pos9+1);
                size_t pos11 = line.find('\t', pos10+1);

                string destination = line.substr(pos3+1, pos4-pos3-1);
                string price = line.substr(0, pos1);
                string numOfParticipants = line.substr(pos1+1, pos2-pos1-1);
                string hotel = line.substr(pos5+1, pos6-pos5-1);
                string bookingStarts = line.substr(pos9+1, pos10-pos9-1);
                string departure = line.substr(pos10+1, pos11-pos10-1);
                string food = line.substr(pos8+1, pos9-pos8-1);
                string transport = line.substr(pos6+1, pos7-pos6-1);
                string duration = line.substr(pos4+1, pos5-pos4-1);
                string packageDescription = line.substr(pos7+1, pos8-pos7-1);

                ui->packageNameEdit->setText(QString::fromStdString(packageName));
                ui->destinationEdit->setText(QString::fromStdString(destination));
                ui->pricePerPersonEdit->setText(QString::fromStdString(price));
                ui->NumOfTravellersEdit->setText(QString::fromStdString(numOfParticipants));
                ui->hotelEdit->setText(QString::fromStdString(hotel));
                ui->bookingStartsEdit->setText(QString::fromStdString(bookingStarts));
                ui->departureEdit->setText(QString::fromStdString(departure));
                ui->foodEdit->setText(QString::fromStdString(food));
                ui->transportEdit->setText(QString::fromStdString(transport));
                ui->durationEdit->setText(QString::fromStdString(duration));
                ui->packageDescriptionEdit->setText(QString::fromStdString(packageDescription));
                return;
            }
        }
    }

    bool update(Ui::updatePackage *ui) override{
        if(!ui->packageNameEdit->text().isEmpty() && !ui->bookingStartsEdit->text().isEmpty() && !ui->departureEdit->text().isEmpty() &&
            !ui->durationEdit->text().isEmpty() && !ui->foodEdit->text().isEmpty() && !ui->hotelEdit->text().isEmpty() &&
            !ui->NumOfTravellersEdit->text().isEmpty() && !ui->packageDescriptionEdit->text().isEmpty() && !ui->pricePerPersonEdit->text().isEmpty() &&
            !ui->transportEdit->text().isEmpty())
        {
            string filename = "C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt";
            string package = ui->packageSelect->currentText().toStdString();
            ifstream inFile(filename);
            ofstream outFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/temp.txt");
            string line;
            while (getline(inFile, line)) {
                size_t pos1 = line.find('\t');
                size_t pos2 = line.find('\t', pos1+1);
                size_t pos3 = line.find('\t', pos2+1);
                string packageName = line.substr(pos2+1, pos3-pos2-1);
                if(package == packageName){

                    string packageName = ui->packageNameEdit->text().toStdString();
                    string destination = ui->destinationEdit->text().toStdString();
                    string price = ui->pricePerPersonEdit->text().toStdString();
                    string numOfParticipants = ui->NumOfTravellersEdit->text().toStdString();
                    string hotel = ui->hotelEdit->text().toStdString();
                    string bookingStarts = ui->bookingStartsEdit->text().toStdString();
                    string departure = ui->departureEdit->text().toStdString();
                    string food = ui->foodEdit->text().toStdString();
                    string transport = ui->transportEdit->text().toStdString();
                    string duration = ui->durationEdit->text().toStdString();
                    string packageDescription = ui->packageDescriptionEdit->text().toStdString();

                    outFile << price << "\t" << numOfParticipants << "\t" << packageName << "\t" << destination << "\t" << duration << "\t"
                            << hotel << "\t" << transport << "\t"<< packageDescription << "\t" << food << "\t" << bookingStarts << "\t"
                            << departure << endl;
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
    void fillEdit(Ui::updatePackage *ui){
        fill(ui);
    }
    bool updatePack(Ui::updatePackage *ui){
        return update(ui);
    }
    bool validateInput(Ui::updatePackage *ui, int i) {
        if(i==1){
            QString text = ui->bookingStartsEdit->text();
            QRegularExpression dateRegex("^\\d{1,2} to \\d{1,2} of [a-zA-Z]+$");
            QRegularExpressionMatch match = dateRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
        else if(i==2){
            QString text = ui->departureEdit->text();
            QRegularExpression dateRegex("^\\d{1,2} of [a-zA-Z]+$");
            QRegularExpressionMatch match = dateRegex.match(text);

            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
        else{
            QString text = ui->durationEdit->text();
            QRegularExpression dateRegex("^\\d{1,2}\\s*Nights\\s*(and|&)\\s*\\d{1,2}\\s*Days$");
            QRegularExpressionMatch match = dateRegex.match(text);
            if (!match.hasMatch()) {
                return false;
            }
            return true;
        }
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class searchPackages : protected packages{
private:
    void search(Ui::searchPackage *ui) override{
        ui->packageDetailsView->clear();
        ifstream inFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt");
        string line;
        string package = ui->packageSelect->currentText().toStdString();
        while (getline(inFile, line)) {

            QFont font("Century Gothic", 12, QFont::Bold);
            size_t pos1 = line.find('\t');
            size_t pos2 = line.find('\t', pos1+1);
            size_t pos3 = line.find('\t', pos2+1);
            string packageName = line.substr(pos2+1, pos3-pos2-1);

            if(package == packageName){
                ui->packageDetailsView->setColumnCount(10);
                for(int i =0;i<10;i++){
                    ui->packageDetailsView->model()->setHeaderData(i, Qt::Horizontal, font, Qt::FontRole);
                    ui->packageDetailsView->setColumnWidth(i, 450);
                }
                ui->packageDetailsView->setColumnWidth(3, 600);
                ui->packageDetailsView->header()->setSectionResizeMode(QHeaderView::Fixed);
                QHeaderView* header = ui->packageDetailsView->header();
                header->setDefaultAlignment(Qt::AlignHCenter);
                ui->packageDetailsView->setStyleSheet("QTreeView::item { border-right: 1px solid #000; }");
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

                string destination = line.substr(pos3+1, pos4-pos3-1);
                string price = line.substr(0, pos1);
                string numOfParticipants = line.substr(pos1+1, pos2-pos1-1);
                string hotel = line.substr(pos5+1, pos6-pos5-1);
                string bookingStarts = line.substr(pos9+1, pos10-pos9-1);
                string departure = line.substr(pos10+1, pos11-pos10-1);
                string food = line.substr(pos8+1, pos9-pos8-1);
                string transport = line.substr(pos6+1, pos7-pos6-1);
                string duration = line.substr(pos4+1, pos5-pos4-1);
                string packageDescription = line.substr(pos7+1, pos8-pos7-1);

                QTreeWidgetItem *item = new QTreeWidgetItem(ui->packageDetailsView);
                item->setText(0, "Package Name: " + QString::fromStdString(packageName));
                item->setText(1, "Price Per Person: " + QString::fromStdString(price));
                item->setText(2, "Num. Of Travellers Allowed: " + QString::fromStdString(numOfParticipants));
                item->setText(3, "Destination: " + QString::fromStdString(destination));
                item->setText(4, "Duration: " + QString::fromStdString(duration));
                item->setText(5, "Booking Starts: " + QString::fromStdString(bookingStarts));
                item->setText(6, "Departure: " + QString::fromStdString(departure));
                item->setText(7, "Hotel: " + QString::fromStdString(hotel));
                item->setText(8, "Food: " + QString::fromStdString(food));
                item->setText(9, "Transport: " + QString::fromStdString(transport));
                ui->packageDescriptionShow->clear();
                ui->packageDescriptionShow->addItem(QString::fromStdString(packageDescription));

                for (int i = 0; i < 10; i++) {
                    item->setTextAlignment(i, Qt::AlignHCenter);
                    item->setFont(i, QFont("century-gothic", 10, QFont::Bold));
                }
                ui->packageDetailsView->addTopLevelItem(item);
                inFile.close();
                return;
            }
        }
        QMessageBox::critical(nullptr, "Error", "Customer record not found.");
    }
public:
    void searchPack(Ui::searchPackage *ui){
        search(ui);
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class deletePackages : protected packages{
private:
    void Delete(Ui::deletePackage *ui) override{
        if(ui->checkBox->isChecked()){
            string filename = "C:/Users/ND.COM/Documents/TravelAgencyMSystem/packages.txt";
            string package = ui->packageSelect->currentText().toStdString();
            ifstream inFile(filename);
            ofstream outFile("C:/Users/ND.COM/Documents/TravelAgencyMSystem/temp.txt");
            string line;
            while (getline(inFile, line)) {
                size_t pos1 = line.find('\t');
                size_t pos2 = line.find('\t', pos1+1);
                size_t pos3 = line.find('\t', pos2+1);
                string packageName = line.substr(pos2+1, pos3-pos2-1);
                if(package == packageName){
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
    void deletePack(Ui::deletePackage *ui){
        Delete(ui);
    }
};

#endif // TRIPPACKAGES_H
