#include "qlabelimageviewer.h"

QLabelImageViewer::QLabelImageViewer(QLabel* label)
{
    this->label = label;
}

void QLabelImageViewer::ViewImage(QImage& img)
{
    if(label != nullptr)
        label->setPixmap(QPixmap::fromImage(img));
}
