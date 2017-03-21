#include "regwindow.h"
#include "ui_regwindow.h"

RegWindow::RegWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegWindow)
{
    ui->setupUi(this);
}

RegWindow::~RegWindow()
{
    delete ui;
}

void RegWindow::on_btn_reg_clicked()
{
    this->show();
    this->setWindowTitle("CYN");
}
