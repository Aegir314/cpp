#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    loggedIn(false)
{
    ui->setupUi(this);
    connect(&l,SIGNAL(logged(bool)),this,SLOT(print(bool)));
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    d.show();
}

void MainWindow::on_pushButton_2_clicked()
{

    l.show();

}

void MainWindow::print(bool a)
{
    a ? QMessageBox::information(this,"Login status","Sucessfully logged in")
        : QMessageBox::information(this,"Login status","Failed to log in");
    if (a) loggedIn = true;

}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_4_clicked()
{
    if (loggedIn){
        QSqlQuery qry;
        if (!qry.exec ("DELETE FROM some")) qDebug()<<qry.lastError();

    } else {
        QMessageBox::warning(this,"Login status","You are not logged in!");
    }

}
