#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "regwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();


private slots:
    void on_btn_login_clicked();

    void on_btn_fgt_clicked();

private:
    Ui::LoginWindow *ui;
    RegWindow reg;
};

#endif // LOGINWINDOW_H
