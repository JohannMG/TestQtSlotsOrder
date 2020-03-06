#ifndef DOGBARK_H
#define DOGBARK_H

#include <QObject>
#include <QString>

class DogBark : public QObject
{
    Q_OBJECT
public:
    explicit DogBark(QObject *parent = nullptr);

signals:
    void barkWithString(QString barkString);

public slots:
    void youShouldBark();
};

#endif // DOGBARK_H
