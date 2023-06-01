#include <QFileDialog>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphwindow.h"
#include "../graph/GraphUtils.h"

MainWindow::MainWindow(QObject *)
    : QMainWindow(nullptr), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuBar->addAction(ui->actionHelp);
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui->actionSpanning_Tree, SIGNAL(triggered()), this, SLOT(getSpanningTree()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file",
                                                    "../files", "Text files (*.txt)");
    if (filename.isEmpty())
    {
        return;
    }
    Graph<string> graph = GraphUtils::graphFromFile(filename.toStdString());
    GraphWindow *graphWindow = new GraphWindow(this, filename, graph);
    currentGraphWindow = graphWindow;
    ui->mdiArea->addSubWindow(graphWindow);
    graphWindow->show();
}

void MainWindow::saveAs()
{
    if (currentGraphWindow == nullptr) {
        return;
    }
    QString saveFilePath = QFileDialog::getSaveFileName(nullptr, "Save File", QDir::homePath(), "Text Files (*.txt)");
    if (!saveFilePath.isEmpty())
    {
        QFile file(saveFilePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            string gs = GraphUtils::graphToString(currentGraphWindow->graph);
            stream << QString::fromStdString(gs);
            file.close();
        }
        currentGraphWindow->filename = saveFilePath;
        currentGraphWindow->setWindowTitle("Graph " + saveFilePath);
    }
}

void MainWindow::getSpanningTree()
{
    if (currentGraphWindow == nullptr) {
        return;
    }
    Graph<string> spanningTree = currentGraphWindow->graph.getSpanningTree();
    GraphWindow *graphWindow = new GraphWindow(this, "", spanningTree);
    currentGraphWindow = graphWindow;
    graphWindow->show();
}