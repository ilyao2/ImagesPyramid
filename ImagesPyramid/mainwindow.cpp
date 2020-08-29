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
    if (p != nullptr)
        delete p;
}


void MainWindow::on_actionUpload_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Выберите изображение", "", "Images (*.png *.jpg)");
    if (!path.isNull())
    {
        QImage image(path);
        if(p!=nullptr)
            delete p;
        p = new Pyramid(image);
        ui->layersComboBox->clear();
        for (int i = 0; i < p->getLayersCount(); i++)
        {
            ui->layersComboBox->addItem("Layer: " + QString::number(i),i);
        }
    }
}

void MainWindow::on_layersComboBox_currentIndexChanged(int index)
{
    int layerId = ui->layersComboBox->itemData(index).toInt();
    const QImage& layer = p->getLayer(layerId);
    imageViewer->ViewImage(layer);
    ui->sizeLabel->setText("Size: " + QString::number(layer.width()) + "x" + QString::number(layer.height()));
}
