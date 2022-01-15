#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
//#include "queueInterface.h"

struct List {
   int val;
   List *next = NULL;
};

//class Queue: public QueueInterface
class Queue
{
private:
    List *Data = NULL;
    List *Marked = NULL;
public:
    Queue();
    Queue(int*);

    virtual ~Queue() {};

    virtual List* getHead();
    virtual List* getLastElement();

    virtual List* findElement(int);
    virtual List* getPreElement(List*);

    virtual List* getMarkedElement();
    virtual void setMarkedElement(List*);

    virtual List* createElement(int);

    virtual void addElement(List*, List*);

    virtual void changeElements(List*, List*);

    void deleteElement(List*);
    void deleteElement(List*, bool);
    bool DeleteList();



    bool isElementsNeighbour(List*, List*);
    void changeNeighbourElements(List*, List*);
    void changeFarElements(List*, List*);
};

#endif // QUEUE_H
