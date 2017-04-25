#include <stdlib.h>
#include <iostream>

int max1 = 0;
int min1 = 32000;
int k = -1;

struct Node       //Структура являющаяся звеном списка
{
    int x;     //Значение x будет передаваться в список
    Node *Next,*Prev; //Указатели на адреса следующего и предыдущего элементов списка
};

class List   //Создаем тип данных Список
{
    Node *Head,*Tail; //Указатели на адреса начала списка и его конца
public:
    List():Head(NULL),Tail(NULL){}; //Инициализируем адреса как пустые
    ~List(); //Деструктор
    void Show(); //Функция отображения списка на экране
    void AddEnd(int x); //Функция добавления элементов в список
    void AddStart(int x);
    void del();
};
void List::del() {
    Node *temp = Head;
    Node *temp_next = temp->Next;
    if (k == 1) {
        while (temp != NULL) {
            if (temp->x == max1) {
                temp_next = temp;
            }
            if (temp->x == min1) {
                temp_next->Next = temp;
                temp->Prev = temp_next;
            }
        temp = temp->Next;
        }
    }
    if (k == 0) {
        while (temp != NULL) {
            if (temp->x == min1) {
                temp_next = temp;
            }
            if (temp->x == max1) {
                temp_next->Next = temp;
                temp->Prev = temp_next;
            }
            temp = temp->Next;
        }
    }
}

List::~List() //Деструктор
{
    while (Head) //Пока по адресу на начало списка что-то есть
    {
        Tail=Head->Next; //Резервная копия адреса следующего звена списка
        delete Head; //Очистка памяти от первого звена
        Head=Tail; //Смена адреса начала на адрес следующего элемента
    }
}

void List::AddEnd(int x)
{
    Node *temp=new Node; //Выделение памяти под новый элемент структуры
    temp->Next=NULL;  //Указываем, что изначально по следующему адресу пусто
    temp->x=x;//Записываем значение в структуру

    if (Head!=NULL) //Если список не пуст
    {
        temp->Prev=Tail; //Указываем адрес на предыдущий элемент в соотв. поле
        Tail->Next=temp; //Указываем адрес следующего за хвостом элемента
        Tail=temp; //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->Prev=NULL; //Предыдущий элемент указывает в пустоту
        Head=Tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
    }
}

void List::AddStart(int x)
{
    Node *temp=new Node; //Выделение памяти под новый элемент структуры
    temp->Prev=NULL;  //Указываем, что изначально по следующему адресу пусто
    temp->x=x;//Записываем значение в структуру

    if (Tail!=NULL) //Если список не пуст
    {
        temp->Next=Head; //Указываем адрес на предыдущий элемент в соотв. поле
        Head->Prev=temp; //Указываем адрес следующего за хвостом элемента
        Head=temp; //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->Next=NULL; //Предыдущий элемент указывает в пустоту
        Head=Tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
    }
}

void List::Show()
{
//ВЫВОДИМ СПИСОК С КОНЦА
    Node *temp=Tail;
    //Временный указатель на адрес последнего элемента
    while (temp!=NULL) //Пока не встретится пустое значение
    {
        std::cout<<temp->x<<" "; //Выводить значение на экран
        if (temp->x > max1){
            max1 = temp->x;
            k = 1;
        }
        if (temp->x < min1){
            min1 = temp->x;
            k = 0;
        }
        temp=temp->Prev; //Указываем, что нужен адрес предыдущего элемента
    }
    std::cout<<"\n";

    //ВЫВОДИМ СПИСОК С НАЧАЛА
    temp=Head; //Временно указываем на адрес первого элемента
    while (temp!=NULL) //Пока не встретим пустое значение
    {
        std::cout<<temp->x<<" "; //Выводим каждое считанное значение на экран
        temp=temp->Next; //Смена адреса на адрес следующего элемента
    }
    std::cout<<"\n";
}

int main ()
{
    system("CLS");
    List lst; //Объявляем переменную, тип которой есть список
    lst.AddEnd(100); //Добавляем в список элементы
    lst.AddEnd(200);
    lst.AddStart(900);
    lst.AddStart(888);
    lst.AddStart(5000);

    lst.Show(); //Отображаем список на экране

    std::cout << max1<<std::endl<<min1<<std::endl;
    lst.del();
    lst.Show();
    system("PAUSE");
}