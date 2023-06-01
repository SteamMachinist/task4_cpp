#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "../graph/Graph.h"

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr, QString filename = "", Graph<string> graph = *new Graph<string>(*new list<string>{}));
    ~GraphWindow();

protected:
    void focusInEvent(QFocusEvent *event) override;
    void drawGraph(QMap<QString, QPointF> positions);
    QMap<QString, QPointF> getRandomPositions();

public:
    QGraphicsScene *scene;
    Ui::GraphWindow *ui;
    QString filename;
    Graph<string> graph;
};

#endif // GRAPHWINDOW_H
