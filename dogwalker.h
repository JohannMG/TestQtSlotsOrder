#ifndef DOGWALKER_H
#define DOGWALKER_H

#include <QObject>
#include "dogbark.h"

class DogWalker : public QObject
{
    Q_OBJECT
public:
    explicit DogWalker(QObject *parent = nullptr);
    void walkSomeDogs();

signals:

public slots:
    void LogDogBark(QString barkString);

};

#endif // DOGWALKER_H
