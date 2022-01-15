#include <iostream>
#include "src/queue/queue.h"
#include "src/app/app.h"

int main()
{
    int *array = new int[6] { 1, 2, 3, 4, 5, '\0' };
    //Queue *A = new Queue;
    Queue *A = new Queue(array);
    App *MyApp = new App(A);
    MyApp->Init();
}
