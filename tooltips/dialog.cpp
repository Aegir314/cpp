#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushButton->setToolTip("<font color='red'>Hello</font> <b>World</b><ul><li>Item 1</li><li>Item 2</li></ul>");
    ui->pushButton->setWhatsThis("<h1>whaaa</h1><br><a href='www.google.com'>Google</a>");
    linkFilter  *filter = new linkFilter(this);
    this->installEventFilter(filter);
    connect(filter,SIGNAL(linkClicked(QString)),this,SLOT(ShowLink(QString)));


    ui->pushButton_2->setToolTip("<img src=':/files/add.png'> Add SOmething");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::ShowLink(const QString &Link){
    QMessageBox::information(this,"Link clicked",Link);
}
