#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
Q_OBJECT

public:
MyClass(); // Konstruktor
~MyClass(); //Destruktor

Q_INVOKABLE QString getString()
     const {
        return  "Funktionsaufruf erfolgreich";
     }

signals:
void setlabeltext(QString text);

public slots:
void cppSlot(QString msg); // Slot wie gehabt

};

#endif // MYCLASS_H
