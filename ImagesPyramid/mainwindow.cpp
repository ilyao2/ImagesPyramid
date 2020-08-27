#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionUpload_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Выбери!!!", "", "Images (*.png *.jpg)");
    if (!path.isNull())
    {
        QImage image(path);
        ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    }
}
