#include "qlabelimageviewer.h"

QLabelImageViewer::QLabelImageViewer(QLabel* label)
{
    this->label = label;
}


QLabelImageViewer::QLabelImageViewer(const QLabelImageViewer& obj)
{
    label = obj.label;
}

void QLabelImageViewer::ViewImage(const QImage& img)
{
    if(label != nullptr)
        label->setPixmap(QPixmap::fromImage(img));
}
