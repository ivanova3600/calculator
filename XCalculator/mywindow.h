#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>


namespace Ui {
class MyWindow;
}

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = 0);
    ~MyWindow();

private:
    Ui::MyWindow *ui;
private slots:
    void clicked_1();
    void clicked_2();
    void clicked_3();
    void clicked_4();
    void clicked_5();
    void clicked_6();
    void clicked_7();
    void clicked_8();
    void clicked_9();
    void clicked_0();
    void clicked_plus();
    void clicked_m();
    void clicked_u();
    void clicked_d();
    void clicked_st();
    void okClicked();
    void clicked_point();
    void clicked_obr();
    void clicked_clbr();
    void clicked_sin();
    void clicked_cos();
    void clicked_tg();
    void clicked_arcsin();
    void clicked_arccos();
    void clicked_arctg();
    void clicked_ctg();
    void clicked_arcctg();
    void clicked_ln();
    void on_clicked();
    void on_actionHelp_2_triggered();
    void on_actionClose_2_triggered();
    void clicked_Close();
};


#endif // MYWINDOW_H
