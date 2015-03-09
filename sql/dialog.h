#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_create_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QSqlDatabase mydb;
};

#endif // DIALOG_H
