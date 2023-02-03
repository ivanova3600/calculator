#include "mywindow.h"
#include "ui_mywindow.h"
#include "calc.h"

void MyWindow::clicked_1()
{
       ui->lineEdit->insert("1");
}

void MyWindow::clicked_2()
{
       ui->lineEdit->insert("2");
}

void MyWindow::clicked_3()
{
       ui->lineEdit->insert("3");
}

void MyWindow::clicked_4()
{
       ui->lineEdit->insert("4");
}

void MyWindow::clicked_5()
{
       ui->lineEdit->insert("5");
}

void MyWindow::clicked_6()
{
       ui->lineEdit->insert("6");
}

void MyWindow::clicked_7()
{
       ui->lineEdit->insert("7");
}

void MyWindow::clicked_8()
{
       ui->lineEdit->insert("8");
}

void MyWindow::clicked_9()
{
       ui->lineEdit->insert("9");
}

void MyWindow::clicked_0()
{
       ui->lineEdit->insert("0");
}

void MyWindow::clicked_plus()
{
       ui->lineEdit->insert("+");
}

void MyWindow::clicked_m()
{
       ui->lineEdit->insert("-");
}

void MyWindow::clicked_u()
{
       ui->lineEdit->insert("*");
}

void MyWindow::clicked_d()
{
       ui->lineEdit->insert("/");
}

void MyWindow::clicked_st()
{
       ui->lineEdit->insert("^");
}

void MyWindow::okClicked()
{
    QString str = ui->lineEdit->text();
    string text = str.toUtf8().constData();
    calc c(text);
    c.Parsing();
    double rezult = c.getRezult();
    QString str1 = QString::number(rezult);
    for(int i = 0; i < str1.size(); i++)
        if(str1[i]=='.'){
            str1[i]=',';
            break;
        }
    ui->lineEdit->clear();
    ui->lineEdit->setText(str1);
}

void MyWindow::clicked_point()
{
       ui->lineEdit->insert(",");
}

void MyWindow::clicked_obr()
{
       ui->lineEdit->insert("(");
}

void MyWindow::clicked_clbr()
{
       ui->lineEdit->insert(")");
}

void MyWindow::on_clicked()
{
    ui->ok->setEnabled(ui->lineEdit->hasAcceptableInput());
}

void MyWindow::clicked_sin()
{
       ui->lineEdit->insert("sin");
}

void MyWindow::on_actionHelp_2_triggered()
{
    QMessageBox mb;
    mb.setText("This is an engineering calculator\nUse the full parenthesis of the expression");
    mb.exec();

}

void MyWindow::on_actionClose_2_triggered()
{
    close();
}

void MyWindow::clicked_Close()
{
    ui->lineEdit->clear();
}

void MyWindow::clicked_cos()
{
       ui->lineEdit->insert("cos");
}

void MyWindow::clicked_tg()
{
       ui->lineEdit->insert("tg");
}

void MyWindow::clicked_arcsin()
{
       ui->lineEdit->insert("arcsin");
}

void MyWindow::clicked_arccos()
{
       ui->lineEdit->insert("arccos");
}

void MyWindow::clicked_arctg()
{
       ui->lineEdit->insert("arctg");
}

void MyWindow::clicked_arcctg()
{
       ui->lineEdit->insert("arcctg");
}

void MyWindow::clicked_ctg()
{
       ui->lineEdit->insert("ctg");
}

void MyWindow::clicked_ln()
{
       ui->lineEdit->insert("ln");
}
