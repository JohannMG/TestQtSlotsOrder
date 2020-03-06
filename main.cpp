#include <QCoreApplication>
#include "dogwalker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DogWalker walker(nullptr);
    walker.walkSomeDogs();

    return a.exec();
}
