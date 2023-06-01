/********************************************************************************
** Form generated from reading UI file 'graphwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWINDOW_H
#define UI_GRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphWindow
{
public:
    QAction *actionSave_As;
    QAction *actionGet_Spanning_Tree;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *GraphWindow)
    {
        if (GraphWindow->objectName().isEmpty())
            GraphWindow->setObjectName(QString::fromUtf8("GraphWindow"));
        GraphWindow->resize(717, 506);
        actionSave_As = new QAction(GraphWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionGet_Spanning_Tree = new QAction(GraphWindow);
        actionGet_Spanning_Tree->setObjectName(QString::fromUtf8("actionGet_Spanning_Tree"));
        centralwidget = new QWidget(GraphWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

        horizontalLayout->addWidget(graphicsView);

        GraphWindow->setCentralWidget(centralwidget);

        retranslateUi(GraphWindow);

        QMetaObject::connectSlotsByName(GraphWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GraphWindow)
    {
        GraphWindow->setWindowTitle(QCoreApplication::translate("GraphWindow", "Graph", nullptr));
        actionSave_As->setText(QCoreApplication::translate("GraphWindow", "Save As", nullptr));
#if QT_CONFIG(tooltip)
        actionSave_As->setToolTip(QCoreApplication::translate("GraphWindow", "Save As", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave_As->setShortcut(QCoreApplication::translate("GraphWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionGet_Spanning_Tree->setText(QCoreApplication::translate("GraphWindow", "Get Spanning Tree", nullptr));
#if QT_CONFIG(tooltip)
        actionGet_Spanning_Tree->setToolTip(QCoreApplication::translate("GraphWindow", "Get Spanning Tree", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionGet_Spanning_Tree->setShortcut(QCoreApplication::translate("GraphWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class GraphWindow: public Ui_GraphWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWINDOW_H
