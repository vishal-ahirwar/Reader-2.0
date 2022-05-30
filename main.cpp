//Copyright(c) 2022 vishal ahirwar. all rights reserved.
#include "mainwindow.h"

#include <QApplication>
std::string file_path{};

int main(int argc, char *argv[])
{
  for(size_t i=0;i<argc;++i)printf("%s ",argv[i]);
   if(argc>=2)file_path=argv[1];
  QApplication a(argc, argv);
  if(argc>=2)
    {
        file_path=argv[1];
    };
  MainWindow w(nullptr,file_path);


  w.show();
  return a.exec();
}
