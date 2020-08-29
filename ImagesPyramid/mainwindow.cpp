#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
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
    for (Pyramid* p : pyramids)
    {
        if (p != nullptr)
            delete p;
    }
}


void MainWindow::on_actionUpload_triggered()
{
    QList<QUrl> urlList = QFileDialog::getOpenFileUrls(this, "Выберите изображение", QUrl(), "Images (*.png *.jpg)");
    if (!urlList.isEmpty())
    {
        for (Pyramid* p : pyramids)
        {
            if (p != nullptr)
                delete p;
        }
        pyramids.clear();
        for(int i = 0; i < urlList.length(); i++)
        {
            QImage image(urlList[i].path().remove(0,1));
            pyramids.append(new Pyramid(image));
        }
        ui->fileComboBox->clear();
        for (int i = 0; i < pyramids.length(); i++)
        {
            ui->fileComboBox->addItem(urlList[i].fileName(), i);
        }
    }
}

void MainWindow::on_layersComboBox_currentIndexChanged(int index)
{
    int layerId = ui->layersComboBox->itemData(index).toInt();
    int pyramidId = ui->fileComboBox->currentData().toInt();
    const QImage& layer = pyramids[pyramidId]->getLayer(layerId);

    imageViewer->ViewImage(layer.scaled(pyramids[pyramidId]->getRootImage().size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->sizeLabel->setText("Size: " + QString::number(layer.width()) + "x" + QString::number(layer.height()));
}

void MainWindow::on_fileComboBox_currentIndexChanged(int index)
{
    int pyramidId = ui->fileComboBox->itemData(index).toInt();
    ui->layersComboBox->clear();
    for (int i = 0; i < pyramids[pyramidId]->getLayersCount(); i++)
    {
        ui->layersComboBox->addItem("Layer: " + QString::number(i),i);
    }
}
