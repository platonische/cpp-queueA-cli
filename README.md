# cpp-queueA-cli
The class' task for realising queue in cli app

-Класс работы с очередью.
-Интерфейс очереди. Возникают непонятные оцибки при компиляции.
-Класс приложения. Интерпретатор команд

```
#include <iostream>
#include "src/queue/queue.h"
#include "src/app/app.h"

int main()
{
    // Без данных
    //Queue *A = new Queue;

    // С загруженными данными
    int *array = new int[6] { 1, 2, 3, 4, 5, '\0' };
    Queue *A = new Queue(array);

    App *MyApp = new App(A);
    MyApp->Init();
}
```
