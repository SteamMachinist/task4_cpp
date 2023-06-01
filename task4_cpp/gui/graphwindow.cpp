#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "graphwindow.h"
#include "ui_graphwindow.h"
#include "mainwindow.h"

GraphWindow::GraphWindow(QWidget *parent, QString filename, Graph<string> graph) :
    QMainWindow(parent),
    ui(new Ui::GraphWindow), filename(filename), graph(graph)
{
    ui->setupUi(this);
    setWindowTitle("Graph " + filename);

    scene = new QGraphicsScene(this);;
    ui->graphicsView->setScene(scene);

    QGraphicsRectItem* rectItem = new QGraphicsRectItem(QRectF(50, 50, 200, 100));
    rectItem->setBrush(Qt::red);
    scene->addItem(rectItem);

    ui->graphicsView->show();

    addAction(ui->actionSave_As);
    addAction(ui->actionGet_Spanning_Tree);
    connect(ui->actionSave_As, SIGNAL(triggered()), parent, SLOT(saveAs()));
    connect(ui->actionGet_Spanning_Tree, SIGNAL(triggered()), parent, SLOT(getSpanningTree()));
}

GraphWindow::~GraphWindow()
{
    delete ui;
}

void GraphWindow::focusInEvent(QFocusEvent *event)
{
    MainWindow *w =qobject_cast<MainWindow*> (parent());
    w->currentGraphWindow = this;
    QWidget::focusInEvent(event);
}
