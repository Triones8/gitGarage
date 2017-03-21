#include "loginwindow.h"
#include <QApplication>
#include <QIcon>
#include <QPushButton>
#include <QBitmap>
#include <QMessageBox>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    LoginWindow w;
    w.setWindowTitle("CYN登录");
    w.resize(800, 600);

    w.show();
    return a.exec();
}


