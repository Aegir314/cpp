#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("data.db");
    if (mydb.open())
        ui->label_3->setText(tr("Connected"));
    else
        ui->label_3->setText(tr("Failed to connect"));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_create_pushButton_clicked()
{
    QString username(ui->username->text());
    QString password(ui->passwords->text());

    if(!mydb.isOpen())
        qFatal("Failed to open the database.");
    QSqlQuery qry;
    if (username.size()>0 && password.size()>0){
        qry.exec(QString("create table some (username varchar (30), password varchar(30))"));
        if (qry.exec(QString("insert into some values('"+username+"','"+password+"')")))
            ui->label_3->setText("<b>Account created!</b>");
        else
            ui->label_3->setText("<b>Failed to create account!</b>");
    }
    else {
        ui->label_3->setText("<b>Username or password empty!</b>");
    }

    qry.exec(QString("select * from some"));

    while(qry.next()){
        qDebug() << "Username: "<<qry.value(0).toString();
        qDebug() << "Password: "<<qry.value(1).toString();
    }

}
