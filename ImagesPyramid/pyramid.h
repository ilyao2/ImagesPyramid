#ifndef PYRAMID_H
#define PYRAMID_H

#include <QImage>
#include <cmath>


class Pyramid
{
private:
    QImage* rootImage;
    QList<QImage*> images;
    int layersCount = 0;
    int K = 2;
    void Clear();
public:
    Pyramid(QImage&, int k = 2);
    Pyramid(const Pyramid&);
    ~Pyramid();
    const QImage& getLayer(int id);
    const QImage& getRootImage();



};

#endif // PYRAMID_H
