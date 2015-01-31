#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    readFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFile()
{
    QString filename = "/proc/partitions";
    QFile file (filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() <<"Couldnt open file for reading.";
    }
    QTextStream in(&file);
    QString device;
    device=in.readAll();
    QStringList listOfDevices;
    listOfDevices<<"sda1"<<"sda2"<<"sda3"<<"sda4"<<"sda5"<<"sda6"<<"sda7";
    for (int i=0;i<listOfDevices.size();i++){
        if (device.contains(listOfDevices[i])){
            ui->comboBox->addItem("/dev/"+listOfDevices[i]);
        }
    }
    file.close();
}
void MainWindow::writeFile()
{
    QString filename = QInputDialog::getText(this,"FileName","Name: ")+".desktop";
    QFile file (filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() <<"Couldnt open file for reading.";
    }
    QTextStream out (&file);
    Dialog a;
    a.show();
    a.exec();
    if(!a.isRejected){
        out<<"[Desktop Entry]\n"<<"Name="+a.arguments[0]+"\n"
           <<"Comment="+a.arguments[1]+"\n"<<"GenericName="+a.arguments[2]+"\n"
           <<"Exec="+a.arguments[3]+"\n"<<"TryExec="+a.arguments[3]+"\n"
           <<"Categories="+a.arguments[4]+"\n"<<"Terminal="+a.arguments[5]+"\n"
           <<"Type="+a.arguments[6]+"\n"<<"Version="+a.arguments[7]+"\n"
           <<"Icon="+a.arguments[8]+"\n";
        ui->statusBar->showMessage(".desktop entry created",2000);
    }

    out.flush();
    file.close();
}


void MainWindow::on_pushButton_clicked()
{
    QProcess process;
    process.start("lxterminal -e udisksctl mount -b '/dev/sda3'");
    if(process.waitForFinished()){
        QProcess process1;
        process1.start("lxterminal -e mpd");
        if(process1.waitForFinished()){
            QProcess process2;
            process2.start("lxterminal -e ncmpcpp");
            process2.waitForFinished();
            ui->statusBar->showMessage("Music started",2000);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString user_Choice = QInputDialog::getText(this,"Are you sure?","Are you sure <y/n>");
    if (user_Choice!="y" && user_Choice !="n") {
        QMessageBox::critical(this,"Error","Didnt understand: "+user_Choice);
        return;
    }
    else if (user_Choice =="n") return;
    else {
        QProcess process;
        process.start("lxterminal -e udisksctl mount -b "+ui->lineEdit->text());
        process.waitForFinished();
        ui->statusBar->showMessage("Disk mounted",2000);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->lineEdit->setText(ui->comboBox->currentText());
     ui->statusBar->showMessage("Disk selected",2000);
}

void MainWindow::on_actionCreate_desktop_triggered()
{
    writeFile();
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}
