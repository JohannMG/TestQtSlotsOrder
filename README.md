# Understand if Qt Signals emitted block execution. Yes They do.
Thought events would be queue after scope. 
Emitted events execution 


```
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DogWalker walker(nullptr);
    walker.walkSomeDogs();

    return a.exec();
}
```



```
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
    dog1.youShouldBark();   //emits barkWithString("Bark");


    qDebug() << "Telling dog 2 to bark";
    dog2.youShouldBark();   //emits barkWithString("Bark");

    qDebug() << "Ending DogWalker::walkSomeDogs";

}

void DogWalker::LogDogBark(QString barkString)
{
    qDebug() << "dogsays:" + barkString;
}

```

// How this executes
/*
Start Logging Dogs          
Telling dog 1 to bark
"dogsays:Bark"                  // emitted before continuing 
Telling dog 2 to bark
"dogsays:Bark"                  // emitted before walkSomeDogs() end 
Ending DogWalker::walkSomeDogs

*/
