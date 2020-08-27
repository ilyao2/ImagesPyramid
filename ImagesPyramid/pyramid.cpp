#include "pyramid.h"
#include <QDebug>

Pyramid::Pyramid(QImage& img)
{
    const int K = 2;

    int lowSize = (img.width() < img.height()) ? img.width() : img.height();

    layersCount = floor(log(lowSize) / log(K));

    for (int i = 0; i < layersCount; i++)
    {
        QImage* temp;
        temp = new QImage(img.scaled(img.width()/(i+1), img.height()/(i+1)));
        images.append(temp);
    }
}

Pyramid::Pyramid(const Pyramid& obj)
{
    Clear();
    for (int i = 0; i < obj.images.length(); i++)
    {
        images.append(new QImage(*obj.images[i]));
    }
}

Pyramid::~Pyramid()
{
    Clear();
}

void Pyramid::Clear()
{
    for(int i = 0; i<layersCount; i++)
    {
        delete images.back();
        images.pop_back();
    }
}

const QImage& Pyramid::getLayer(int id)
{
    if (id < 0 || id >= layersCount)
        throw std::out_of_range("Out of range");
    return *images.at(id);
}
