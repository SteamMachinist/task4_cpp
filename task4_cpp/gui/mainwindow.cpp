#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file",
                                                    "../resources", "Text resources (*.txt)");
    ui->centralwidget->findChild<QTextBrowser *>("textBrowser")->setText(filename);
}
