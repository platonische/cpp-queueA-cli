#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

#include <iostream>
#include "queue.h"
//struct List {
//   int val;
//   List *next = NULL;
//};

class QueueInterface
{
public:

    QueueInterface();
//    virtual ~QueueInterface(){};

    virtual List* getHead();
    virtual List* getLastElement();

    virtual List* findElement(int);
    virtual List* getPreElement(List*);

    virtual List* getMarkedElement();
    virtual void setMarkedElement(List*);

    virtual List* createElement(int);

    virtual void addElement(List*, List*);

    virtual void changeElements(List*, List*);

    virtual void deleteElement(List*);
    virtual void deleteElement(List*, bool);
    virtual bool DeleteList();
};

#endif // QUEUEINTERFACE_H
