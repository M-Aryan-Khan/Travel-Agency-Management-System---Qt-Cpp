#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "system.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_LoginButton_clicked();

    void on_eye_clicked();

private:
    Ui::Login *ui;
    System sys;
};
#endif // LOGIN_H