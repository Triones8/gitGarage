#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "regwindow.h"
#include "ui_regwindow.h"
#include <QMessageBox>
#include <QWidget>
#include <QPalette>
#include<QWizard>
#include<QWizardPage>
#include<QLabel>
#include<QVBoxLayout>
#include<QPixmap>
#include <QString>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->btn_fgt->setShortcut(Qt::Key_Return);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
void LoginWindow::on_btn_login_clicked()
{
    QString str_id = ui->edt_id->text();
    QString str_pw = ui->edt_pw->text();
    //if(login(str_id, str_pw)){};
}

void LoginWindow::on_btn_fgt_clicked()
{
    this->hide();
    reg.show();
    reg.setWindowTitle("CYN注册");
    //reg.exec();
}
