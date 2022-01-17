# cpp-queueA-cli
Курс по программированию ННГТУ.

Задание: консольное приложение по работе с очередью.

- Класс работы с очередью.
- Интерфейс очереди. `Возникают непонятные ошибки при компиляции.`
- Класс приложения. Интерпретатор команд

Проект в QT Creator.

```cpp
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
