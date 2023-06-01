#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "gui/mainwindow.h"
#include "graph/Graph.h"
#include "graph/GraphUtils.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
    return QApplication::exec();

//    Graph<string> graph = GraphUtils::graphFromFile(R"(D:\c++ projects\task4_cpp\files\graph1.txt)");
//    Graph<string> graph2 = graph.getSpanningTree();
//    cout << GraphUtils::graphToString(graph) << endl;
//    cout << GraphUtils::graphToString(graph2);
}