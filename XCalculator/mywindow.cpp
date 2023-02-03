#include "mywindow.h"
#include "ui_mywindow.h"
#include <QRegExp>


MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);

    ui->ok->setEnabled(false);
    QRegExp expr("[\\d(sin)(cos)(tg)(ctg)(ln)(arcsin)(arccos)(arctg)(arcctg),+-/*^\(\)]*");
    ui->lineEdit->setValidator(new QRegExpValidator(expr,this));

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(clicked_1()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(clicked_2()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(clicked_3()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(clicked_4()));
    connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(clicked_5()));
    connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(clicked_6()));
    connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(clicked_7()));
    connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(clicked_8()));
    connect(ui->pushButton_9,SIGNAL(clicked(bool)),this,SLOT(clicked_9()));
    connect(ui->pushButton_0,SIGNAL(clicked(bool)),this,SLOT(clicked_0()));
    connect(ui->pl,SIGNAL(clicked(bool)),this,SLOT(clicked_plus()));
    connect(ui->m,SIGNAL(clicked(bool)),this,SLOT(clicked_m()));
    connect(ui->d,SIGNAL(clicked(bool)),this,SLOT(clicked_d()));
    connect(ui->u,SIGNAL(clicked(bool)),this,SLOT(clicked_u()));
    connect(ui->st,SIGNAL(clicked(bool)),this,SLOT(clicked_st()));
    connect(ui->ok,SIGNAL(clicked()),this,SLOT(okClicked()));
    connect(ui->open_bracket,SIGNAL(clicked(bool)),this,SLOT(clicked_obr()));
    connect(ui->close_bracket,SIGNAL(clicked(bool)),this,SLOT(clicked_clbr()));
    connect(ui->point,SIGNAL(clicked(bool)),this,SLOT(clicked_point()));
    connect(ui->sin,SIGNAL(clicked(bool)),this,SLOT(clicked_sin()));
    connect(ui->cos,SIGNAL(clicked(bool)),this,SLOT(clicked_cos()));
    connect(ui->tg,SIGNAL(clicked(bool)),this,SLOT(clicked_tg()));
    connect(ui->arcsin,SIGNAL(clicked(bool)),this,SLOT(clicked_arcsin()));
    connect(ui->arccos,SIGNAL(clicked(bool)),this,SLOT(clicked_arccos()));
    connect(ui->arctg,SIGNAL(clicked(bool)),this,SLOT(clicked_arctg()));
    connect(ui->ctg,SIGNAL(clicked(bool)),this,SLOT(clicked_ctg()));
    connect(ui->arcctg,SIGNAL(clicked(bool)),this,SLOT(clicked_arcctg()));
    connect(ui->ln,SIGNAL(clicked(bool)),this,SLOT(clicked_ln()));



    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(on_clicked()));
    connect(ui->Clear,SIGNAL(clicked(bool)),this,SLOT(clicked_Close()));

}

MyWindow::~MyWindow()
{
    delete ui;
}

