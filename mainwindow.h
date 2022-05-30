//Copyright(c) 2022 vishal ahirwar. all rights reserved.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent,const std::string file_path);
  ~MainWindow();

private slots:

  void on_commandLinkButton_2_clicked();

  void on_commandLinkButton_3_clicked();
   void on_commandLinkButton_clicked();
public:
   void openFile(const std::string file_temp="");
private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
