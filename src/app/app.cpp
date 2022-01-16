#include "app.h"

App::App(Queue *Type)
{
    this->queueProvider = Type;
}

void App::Init()
{
    this->menu();
}

void App::menu()
{
    // Данные на экран для наглядности
    this->PrintList();

    this->printMenuLines();

    cout << "\n\nВыберите пункт меню.\n";
    int Menu = this->input();

    this->cleanScreen();

    Menu = this->executeOperation(Menu);

    if (Menu == 0) {
        this->cleanScreen();
        this->SayGoodbye();
    }
    else {
        this->menu();
    }


}

void App::printMenuLines()
{
    cout << " 0 - Exit\n";
    cout << " 1 - Создать список\n";
    cout << " 2 - Распечатать список\n";
    cout << " 3 - Вставить элемент в конец списка\n";
    cout << " 4 - Вставить элемент в начало списка\n";
    cout << " 5 - Вставить элемент в после конкретного\n";
    cout << " 6 - Удалить 1 с конца\n";
    cout << " 7 - Удалить 1 с начала\n";
    cout << " 8 - Удалить определенный элемент\n";
    cout << " 9 - Удалить весь список\n";
    cout << "10 - Поменять крайние местами\n";
    cout << "11 - Поменять определенный элемент с первым\n";
    cout << "12 - Поменять определенный элемент с последним\n";
    cout << "13 - Определенный элемент первым\n";
    cout << "14 - Определенный элемент последним\n";
}

int App::executeOperation(int Op)
{
    switch (Op) {
        case 1: this->CreateList(); this->cleanScreen(); break;
        case 2: this->PrintList(); break;
        case 3: this->append();this->cleanScreen(); break;
        case 4: this->insert(); this->cleanScreen(); break;
        case 5: this->insertInto(); this->cleanScreen(); break;

        case 6: this->pop(); this->cleanScreen(); break;
        case 7: this->shift(); this->cleanScreen(); break;
        case 8: this->shiftInto(); this->cleanScreen(); break;

        case 9: this->DeleteList(); this->cleanScreen(); break;
        case 10: this->change1(); this->cleanScreen(); break;
        case 11: this->change2(); this->cleanScreen(); break;
        case 12: this->change3(); this->cleanScreen(); break;
        case 13: this->change4(); this->cleanScreen(); break;
        case 14: this->change5(); this->cleanScreen(); break;
        default: Op = 0;
    }

    return Op;
}

void App::CreateList()
{
    // Данные на экран для наглядности
    this->cleanScreen();
    this->PrintList();

    cout << "Создание структуры\nPress 0 to exit\n\n";
    int Value = this->input();

    while (Value != 0) {

        this->queueProvider->addElement(
                    this->queueProvider->createElement(Value),
                    this->queueProvider->getLastElement());


        // Данные на экран для наглядности
        this->cleanScreen();
        this->PrintList();

        cout << "Создание структуры\nPress 0 to exit\n\n";
        Value = this->input();

    }
}

void App::PrintList()
{
    cout << "Data: ";

    int i = 0;
    List *Current = this->queueProvider->getHead();

    while (Current) {
        cout << Current->val;
        if (Current->next) cout << ", ";
        Current = Current->next;
        i++;
    }


    cout << "\nCount: "<< i << endl;
    cout << "-----------------------------------------------------------------"<< endl;
    if (this->msg) cout << ">>>>> " << this->msg << endl;
    this->msg = NULL;
}

void App::DeleteList()
{
    if (this->queueProvider->DeleteList()){
        this->exception("All elements were deleted");
    }

}

void App::append()
{
    cout << "Добавление нового элемента в конец\n";
    int Value = this->input();

    this->queueProvider->addElement(
                this->queueProvider->createElement(Value),
                this->queueProvider->getLastElement()
                );
}

void App::insert()
{
    cout << "Добавление нового элемента в начало\n";
    int Value = this->input();

    this->queueProvider->addElement(
                this->queueProvider->createElement(Value),
                NULL
                );
}

void App::insertInto()
{
    cout << "Вставка элемента после указанного\nБудет произведен поиск по значению\n";
    int Value = this->input();
    this->queueProvider->setMarkedElement(this->queueProvider->findElement(Value));

    //Если надется значение, то Current существует
    if (this->queueProvider->getMarkedElement()) {
        cout << "Добавление нового элемента после "<< Value << "\n";
        Value = this->input();

        this->queueProvider->addElement(
                    this->queueProvider->createElement(Value),
                    this->queueProvider->getMarkedElement()
                    );
        this->queueProvider->setMarkedElement(NULL);
    }
    else {
        this->exception("Не удалось найти значение для вставки после него.");
    }
}

// Удаление первого
void App::shift()
{
    this->queueProvider->deleteElement(this->queueProvider->getHead(),true);
}

// Удаление по поиску
void App::shiftInto()
{
    cout << "Будет произведено удаление элемента по значению.\n";
    int Value = this->input();

    this->queueProvider->setMarkedElement(this->queueProvider->findElement(Value));

    if (this->queueProvider->getMarkedElement()) {
        this->queueProvider->deleteElement(this->queueProvider->getMarkedElement(), true);
        this->queueProvider->setMarkedElement(NULL);
    }
    // Нет попадания
    else {
        this->exception("Элемент для удаления не найден");
    }

}

// Удаление последнего
void App::pop()
{
    this->queueProvider->deleteElement(this->queueProvider->getLastElement(),true);
}

// first and end
void App::change1()
{
    this->queueProvider->changeElements(
                this->queueProvider->getHead(),
                this->queueProvider->getLastElement()
                );
}

// found with first
void App::change2()
{

    cout << "Будет произведена смена найденного элемента с первым\n";
    int Value = this->input();

    this->queueProvider->setMarkedElement(this->queueProvider->findElement(Value));

    if (this->queueProvider->getMarkedElement()) {

        this->queueProvider->changeElements(
                    this->queueProvider->getHead(),
                    this->queueProvider->getMarkedElement()
                    );
        this->queueProvider->setMarkedElement(NULL);
    }
    else {
        //не найден
        this->exception("Элемент не найден");
    }
}

// found with last
void App::change3()
{
    cout << "Будет произведена смена найденного элемента с последним\n";
    int Value = this->input();

    this->queueProvider->setMarkedElement(this->queueProvider->findElement(Value));

    if (this->queueProvider->getMarkedElement()) {

        this->queueProvider->changeElements(
                    this->queueProvider->getMarkedElement(),
                    this->queueProvider->getLastElement()
                    );
        this->queueProvider->setMarkedElement(NULL);
    }
    else {
        //не найден
        this->exception("Элемент не найден");
    }
}

// found to start
void App::change4()
{
    cout << "Элемент будет перемещен в начало\n";
    int Value = this->input();

    this->queueProvider->setMarkedElement(this->queueProvider->findElement(Value));

    if (this->queueProvider->getMarkedElement()) {
        this->queueProvider->deleteElement(this->queueProvider->getMarkedElement(), false);
        this->queueProvider->addElement(this->queueProvider->getMarkedElement(),NULL);
        this->queueProvider->setMarkedElement(NULL);
    }
    else {
        //не найден
        this->exception("Элемент не найден");
    }
}

// found to finish
void App::change5()
{
    cout << "Элемент будет перемещен в конец\n";
    int Value = this->input();

    this->queueProvider->setMarkedElement(this->queueProvider->findElement(Value));

    if (this->queueProvider->getMarkedElement()
            && this->queueProvider->getMarkedElement() != this->queueProvider->getLastElement()) {

        this->queueProvider->deleteElement(this->queueProvider->getMarkedElement(), false);
        this->queueProvider->addElement(
                    this->queueProvider->getMarkedElement(),
                    this->queueProvider->getLastElement());
        this->queueProvider->setMarkedElement(NULL);
    }
    else {
        //не найден
        this->exception("Элемент не найден");
    }
}

int App::input()
{
    int Input;
    cout << "Введите число: ";
    cin >> Input;

    return Input;
}

void App::SayGoodbye()
{
    cout << "GoodBye\n";
}

void App::exception(const char* text){
    this->msg = text;
}

void App::cleanScreen()
{
    QProcess::execute("clear");
    //printf("\033[3J");
}
