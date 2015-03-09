#include "login.h"
#include "ui_login.h"
#include <QtSql>
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QSqlQuery qry;
    if (qry.exec(QString("select * from some where username='"+ui->username->text()+
                         "'and password='"+ui->password->text()+"'"))){
        bool emmited = false;
        while(qry.next()){
            if (ui->username->text() == qry.value(0).toString()){
                emit(logged(true));
                emmited = true;
                break;
            }


        }

        if (!emmited) emit(logged(false));
        this->close();
    }

}
