#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "gui/mainwindow.h"
#include "graph/Graph.h"
#include "utils/FileUtils.h"

using namespace std;

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow *mainwindow = new MainWindow();
//    mainwindow->show();
//    return QApplication::exec();

    FileUtils fileUtils;
    Graph<string> graph = fileUtils.graphFromFile("graph1.txt");
    Graph<string> graph2 = graph.getSpanningTree();
    cout << "a";
}
