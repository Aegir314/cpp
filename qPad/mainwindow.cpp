#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("QPad");
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    mFilename = "";
    ui->textEdit->setPlainText("");
    ui->statusBar->showMessage("New file",2000);
}

void MainWindow::on_actionOpen_triggered()
{
   QString file = QFileDialog::getOpenFileName(this,"Open a file");

   if (!file.isEmpty()){
       QFile sFile(file);
       if (sFile.open(QFile::ReadOnly | QFile::Text)){
            mFilename=file;
            QTextStream in (&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);
            ui->statusBar->showMessage("File opened",2000);
       }
   }
}

void MainWindow::on_actionSave_triggered()
{
    if (mFilename.isEmpty()){
        on_actionSave_As_triggered();
    }
    QFile sFile (mFilename);
    if (sFile.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out (&sFile);
        out<<ui->textEdit->toPlainText();
        ui->statusBar->showMessage("File saved",2000);
        sFile.flush();
        sFile.close();

    }

}

void MainWindow::on_actionSave_As_triggered()
{

    QString file = QFileDialog::getSaveFileName(this,"Save a file");

    if (!file.isEmpty()){
        mFilename = file;
        on_actionSave_triggered();
    }
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();


}

void MainWindow::on_actionFind_triggered()
{
     QString a = QInputDialog::getText(this,"Find","Enter search:");
     if (!a.isEmpty()){
         ui->textEdit->find(a);
     }
}

void MainWindow::on_actionReplace_triggered()
{
    on_actionFind_triggered();
    QString a = QInputDialog::getText(this,"Replace","Repace with:");
    if (!a.isEmpty()){
        QTextCursor cursor (ui->textEdit->textCursor());
        cursor.insertText(a);
    }
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"About","<center><b>QPad</b></center><br>Notepad fork made in qt");
}
