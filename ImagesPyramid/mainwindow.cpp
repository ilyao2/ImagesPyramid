#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageViewer = new QLabelImageViewer(ui->imageLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete imageViewer;
}


void MainWindow::on_actionUpload_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Выбери!!!", "", "Images (*.png *.jpg)");
    if (!path.isNull())
    {
        QImage image(path);
        imageViewer->ViewImage(image);
    }
}
