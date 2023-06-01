#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphwindow.h"
#include "../graph/Graph.h"

namespace Ui
{
class MainWindow;
}

class MainWindow: public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QObject * = nullptr);
    ~MainWindow();

    GraphWindow *currentGraphWindow{};

private:
    Ui::MainWindow *ui;

public slots:
    void open();
    void saveAs();
    void getSpanningTree();
};

#endif // MAINWINDOW_H
