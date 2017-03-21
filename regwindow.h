#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>

namespace Ui {
class RegWindow;
}

class RegWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegWindow(QWidget *parent = 0);
    ~RegWindow();

private slots:
    void on_btn_reg_clicked();

private:
    Ui::RegWindow *ui;
};

#endif // REGWINDOW_H
