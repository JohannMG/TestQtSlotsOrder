#include "dogwalker.h"

#include <QDebug>

DogWalker::DogWalker(QObject *parent) : QObject(parent)
{

}

void DogWalker::walkSomeDogs()
{
    DogBark dog1(this);
    DogBark dog2(this);

    connect(&dog1,&DogBark::barkWithString,
            this, &DogWalker::LogDogBark);
    connect(&dog2,&DogBark::barkWithString,
            this, &DogWalker::LogDogBark);

    qDebug() << "Start Logging Dogs";
    qDebug() << "Telling dog 1 to bark";
    dog1.youShouldBark();
    qDebug() << "Telling dog 2 to bark";
    dog2.youShouldBark();
    qDebug() << "Ending DogWalker::walkSomeDogs";

}

void DogWalker::LogDogBark(QString barkString)
{
    qDebug() << "dogsays:" + barkString;
}

// How this executes
/*
Start Logging Dogs
Telling dog 1 to bark
"dogsays:Bark"
Telling dog 2 to bark
"dogsays:Bark"
Ending DogWalker::walkSomeDogs

*/
