#include "queue.h"

Queue::Queue()
{

}

Queue::Queue(int* inputData)
{
    int i = 0;
    while (inputData[i] != '\0') {
        this->addElement(
                    this->createElement(inputData[i]),
                    this->getLastElement()
                    );
        i++;
    }
}

// Добавить элемент после элемента, либо в начало
void Queue::addElement(List* El, List* Position = NULL)
{
    if(Position) {
        El->next = Position->next;
        Position->next = El;
    }
    //Вставка в начало
    else {
        El->next = this->Data;
        this->Data = El;
    }
}


bool Queue::DeleteList()
{
    List* Current = this->getHead();
    while (Current) {
        this->deleteElement(Current);
    }
    return true;
}


void Queue::deleteElement(List* A){
    this->deleteElement(A,true);
}

void Queue::deleteElement(List* A, bool isClean = true)
{
    if (A){
        List *PreA = this->getPreElement(A);

        if (PreA) PreA->next = A->next;
        else this->Data = A->next;

        if (isClean) {
            delete [] A;
            A = NULL;
        }
    }
    else {
//        this->exception("Nothing to delete.");
    }


}

void Queue::changeElements(List *A, List *B)
{
    if (this->isElementsNeighbour(A,B)){
        this->changeNeighbourElements(A,B);
    }
    else {
        this->changeFarElements(A,B);
    }
}

void Queue::changeFarElements(List *A, List *B)
{
    // Предыдущие элементы
    List *PreA = this->getPreElement(A);
    List *PreB = this->getPreElement(B);

    // Меняем ссылки в самих элементах
    List* ANext = A->next;
    List* BNext = B->next;

    A->next = BNext;
    B->next = ANext;


    // Меняем ссылки в педшествующих элементах
    if (PreA) PreA->next = B;
    if (PreB) PreB->next = A;


    //Меняем голову
    bool isHead = false;
    if (A == this->Data && !isHead) {
        this->Data = B;
        isHead = true;
    }
    if (B == this->Data && !isHead) {
        this->Data = A;
        isHead = true;
    }
}

void Queue::changeNeighbourElements(List *A, List *B) {

    List *First, *Second, *SecondNext, *Pre;

    if (A->next == B) First = A;
    if (B->next == A) First = B;

    Second = First->next;
    SecondNext = Second->next;
    Pre = this->getPreElement(First);

    if (Pre) Pre->next = Second;
    else this->Data = Second;

    Second->next = First;
    First->next = SecondNext;
}

bool Queue::isElementsNeighbour(List *A, List *B)
{
    return A->next == B || B->next == A;
}

List* Queue::findElement(int Value)
{
    if (!this->Data) return NULL;

    List *Current = this->Data;
    while (Current && Current->val != Value) {
        Current = Current->next;
    }

    return Current;
}

List* Queue::getPreElement(List* El)
{
    if (!this->Data) return NULL;

    List *Current = this->Data;
    List *Preview = NULL;
    while (Current && Current != El) {
        Preview = Current;
        Current = Current->next;
    }

    return Preview;
}

List* Queue::getLastElement()
{
    if (!this->Data) return NULL;

    List *Current = this->Data;

    while (Current->next) {
        Current = Current->next;
    }

    return Current;
}



List* Queue::createElement(int Value)
{
    List *Elem = new List;
    Elem->val = Value;

    return Elem;
}

List* Queue::getHead()
{
    return this->Data;
}

List* Queue::getMarkedElement()
{
    List* Marked = this->Marked;
    //this->Marked = NULL;

    return Marked;
}
void Queue::setMarkedElement(List* Elem)
{
        this->Marked = Elem;
}
