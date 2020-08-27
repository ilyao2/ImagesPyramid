#ifndef QLABELIMAGEVIEWER_H
#define QLABELIMAGEVIEWER_H

#include "ImageViewer.h"
#include <QLabel>

class QLabelImageViewer : public ImageViewer
{
private:
    QLabel* label;
public:
    QLabelImageViewer(QLabel* label);
    void ViewImage(const QImage& img) override;

};

#endif // QLABELIMAGEVIEWER_H
