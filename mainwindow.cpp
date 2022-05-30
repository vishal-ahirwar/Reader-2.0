//Copyright(c) 2022 vishal ahirwar. all rights reserved.
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<fstream>
#include<iostream>
#include<QFileDialog>
#include<QMessageBox>
#include<stdlib.h>
MainWindow::MainWindow(QWidget *parent,const std::string file_path)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  if(!file_path.empty())
  this->openFile(file_path);

}

MainWindow::~MainWindow()
{
  delete ui;
}
void MainWindow::openFile(const std::string file_temp)
{
  QString fileName{};
  if(!file_temp.empty())
    {
        fileName=file_temp.c_str();
    }
  fileName=this->ui->lineEdit->text();
  if(fileName.isEmpty())
    {
        fileName=QFileDialog::getOpenFileName(this,"Open File(File Reader) ...","./");
        this->ui->lineEdit->setText(fileName);
    }
  FILE* file;
  file=fopen(fileName.toStdString().c_str(),"r");
  if(file)
    {
      QString str;
      int c= getc(file);
      while(c!=EOF)
        {
          str.append(QChar(c));
          c=getc(file);
        };
      this->ui->textEdit->setText(str);
      fclose(file);
    }else
    {
      /*
    QMessageBox(Icon icon, const QString &title, const QString &text,
                StandardButtons buttons = NoButton, QWidget *parent = nullptr,
                Qt::WindowFlags flags = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);*/
      QMessageBox::warning(this,"Error","File Not Found!");
    };

};

void MainWindow::on_commandLinkButton_clicked()
{
    this->openFile();
}


void MainWindow::on_commandLinkButton_2_clicked()
{
  if(!this->ui->lineEdit->text().isEmpty())
    {

      std::fstream file;
      file.open(this->ui->lineEdit->text().toStdString().c_str(),std::ios::out);
      if(file.is_open())
        {
          file<<(this->ui->textEdit->toPlainText().toStdString());
        };
      file.close();
    }else
    {
      std::cerr<<"false running ..\n";
    }
}


void MainWindow::on_commandLinkButton_3_clicked()
{
         this->destroy();
         exit(0);
}

