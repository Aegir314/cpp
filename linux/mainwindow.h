#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>

#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void readFile();

    void writeFile();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionCreate_desktop_triggered();

    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
