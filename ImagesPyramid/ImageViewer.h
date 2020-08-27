#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QImage>

class ImageViewer
{
public:
    virtual void ViewImage(QImage&) = 0;
    virtual ~ImageViewer() = default;
};
#endif // IMAGEVIEWER_H
