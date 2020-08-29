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
        PyramidsNames.clear();


        for(int i = 0; i < urlList.length(); i++)
        {
            QString path = urlList[i].path().remove(0,1);
            QImage image(path);
            Pyramid* tempPyramid = new Pyramid(image);
            PyramidsNames[tempPyramid] = urlList[i].fileName();
            pyramids.append(tempPyramid);
            std::sort(pyramids.begin(), pyramids.end(), CompPyramids);
        }


        ui->fileComboBox->clear();
        for (int i = 0; i < pyramids.length(); i++)
        {
            ui->fileComboBox->addItem(PyramidsNames[pyramids[i]], i);
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

bool MainWindow::CompPyramids(const Pyramid* p1, const Pyramid* p2)
{
    const QImage& img1 = p1->getRootImage();
    const QImage& img2 = p2->getRootImage();
    int d1 = img1.width()*img1.width() + img1.height()*img1.height();
    int d2 = img2.width()*img2.width() + img2.height()*img2.height();
    return d1 < d2;
}
