#include "dogbark.h"

#include <QString>

DogBark::DogBark(QObject *parent) : QObject(parent)
{
    //nop
}

void DogBark::youShouldBark()
{
    QString bark = "Bark";
    emit barkWithString(bark);
}
