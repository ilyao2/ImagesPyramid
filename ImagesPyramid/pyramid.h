#ifndef PYRAMID_H
#define PYRAMID_H

#include <QImage>
#include <cmath>


class Pyramid
{
private:
    QList<QImage*> images;
    int layersCount = 0;
    void Clear();
public:
    Pyramid(QImage&);
    Pyramid(const Pyramid&);
    ~Pyramid();
    const QImage& getLayer(int id);



};

#endif // PYRAMID_H
