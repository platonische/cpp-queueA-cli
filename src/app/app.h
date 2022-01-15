#ifndef APP_H
#define APP_H

#include <QProcess>
//#include "src/queue/queueInterface.h"
#include "src/queue/queue.h"

using namespace std;

class App
{
private:
    Queue *queueProvider;
    const char *msg;

public:
    App(Queue *);
    void Init();


    void menu();
    void printMenuLines();
    int executeOperation(int);


    void SayGoodbye();

    void CreateList();
    void PrintList();
    void DeleteList();
    void append();
    void insert();
    void insertInto();

    void pop();
    void shift();
    void shiftInto();


    void change1();
    void change2();
    void change3();
    void change4();
    void change5();


    void exception(const char*);
    void cleanScreen();
    int input();

};

#endif // APP_H
