#include "pyramid.h"

Pyramid::Pyramid(QImage& img, float k)
{
    if(k <= 1)
        throw std::out_of_range("The coefficient must be greater than 1");
    K = k;
    rootImage = new QImage(img);

    int lowSize = (img.width() < img.height()) ? img.width() : img.height();

    layersCount = floor(log(lowSize) / log(K)) + 1;

    for (int i = 0; i < layersCount; i++)
    {
        QImage* temp = nullptr;
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
    images.clear();
    if (rootImage != nullptr)
        delete rootImage;
}

void Pyramid::Clear()
{
    for(int i = 0; i<layersCount; i++)
    {
        if (images[i] != nullptr)
        {
            delete images[i];
            images[i] = nullptr;
        }
    }
}

const QImage& Pyramid::getLayer(int id)
{
    if (id < 0 || id >= layersCount)
        throw std::out_of_range("Out of range");
    if (images[id] == nullptr)
        images[id] = new QImage(rootImage->scaled(rootImage->width()/pow(K,id), rootImage->height()/pow(K,id), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    return *images.at(id);
}

const QImage& Pyramid::getRootImage() const
{
    return *rootImage;
}

int Pyramid::getLayersCount()
{
    return layersCount;
}
