#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <random>
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

    drawGraph(getRandomPositions());

    ui->graphicsView->show();

    addAction(ui->actionSave_As);
    addAction(ui->actionGet_Spanning_Tree);
    connect(ui->actionSave_As, SIGNAL(triggered()), parent, SLOT(saveAs()));
    connect(ui->actionGet_Spanning_Tree, SIGNAL(triggered()), parent, SLOT(getSpanningTree()));
}

QMap<QString, QPointF> GraphWindow::getRandomPositions() {
    QMap<QString, QPointF> positions = *new QMap<QString, QPointF>();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, min(this->geometry().width(), this->geometry().height()));
    for (const auto& [key, val] : graph.adjacency)
    {
        positions[QString::fromStdString(key)] = QPointF(distr(gen), distr(gen));
    }
    return positions;
}

void GraphWindow::drawGraph(QMap<QString, QPointF> positions) {
    QMap<QString, QGraphicsEllipseItem*> nodes;
    QMap<QString, QList<QGraphicsLineItem*>> edges;

    for (const auto& [nodeName, neighbors] : graph.adjacency)
    {
        QGraphicsEllipseItem* node = new QGraphicsEllipseItem(-10, -10, 20, 20);
        node->setPos(positions[QString::fromStdString(nodeName)]);
        node->setBrush(QBrush(Qt::white));
        node->setPen(QPen(Qt::black));
        scene->addItem(node);
        nodes[QString::fromStdString(nodeName)] = node;

        for (const auto& neighborName : neighbors)
        {
            QList<QGraphicsLineItem*>& edgeList = edges[QString::fromStdString(nodeName)];
            QPointF pos1 = node->pos();
            QPointF pos2 = positions[QString::fromStdString(neighborName)];
            QGraphicsLineItem* edge = new QGraphicsLineItem(pos1.x(), pos1.y(), pos2.x(), pos2.y());
            edge->setPen(QPen(Qt::black, 2));
            scene->addItem(edge);
            edgeList.append(edge);
        }
    }

    for (const auto& e : nodes.toStdMap())
    {
        auto nodeName = e.first;
        auto node = e.second;
        QGraphicsTextItem* label = new QGraphicsTextItem(nodeName, node);
        label->setDefaultTextColor(Qt::black);
        label->setFont(QFont("Arial", 10, QFont::Bold));
        label->setPos(-8, -12);
        node->setToolTip(nodeName);
    }
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
