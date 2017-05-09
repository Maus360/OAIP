#include <iostream>
#include <stack>

using namespace std;

int max1 = 0;
int min1 = 32000;
    struct stek{
    int value;
    stek *next, *head;
};


void add(int x, stek *&stack){
    stek *temp = new stek;
    temp->value = x;
    temp ->next = stack->head;
    stack->head = temp;
}


int k;
void show(stek *stack){
    stek *temp = stack->head;
    while (temp!=NULL){
        cout<<temp->value<<" ";
        if (temp->value>max1) {
            k = 1;
            max1 = temp->value;
        }
        if (temp->value<min1){
            min1 = temp->value;
            k=0;
        }
        temp = temp->next;
    }
    cout<<endl;
    cout<<min1<<endl;
    cout<<max1<<endl;
}


void del(stek *stack) {
    cout<<k<<endl;
    stek *temp = stack->head;
    stek *temp_next = temp->next;
    if (k == 0) {
        while (temp != NULL) {
            //cout<<temp->value<<endl;
            if (temp->value == max1) {
                temp_next = temp;
            }
            if (temp->value == min1) {
                temp_next->next = temp;
            }
            temp = temp->next;
        }
    }
    if (k == 1) {
        while (temp != NULL) {
            if (temp->value == min1) {
                temp_next = temp;
            }
            if (temp->value == max1) {
                temp_next->next = temp;
            }
            temp = temp->next;
        }
    }
}


void Delete(stek *List)
{
    stek *dop = new stek;
    dop = List->head;
    List->head = List->head->next;
    delete dop;

}


void Sort2(stek *List)
{
    stek *dop = new stek;
    stek *dop1 = new stek;
    int arr;
    add(10, List);
    dop = List->head->next;
    dop1 = List->head->next;
    while (dop1 != NULL)
    {
        dop = List->head->next;
        while (dop->next != NULL)
        {
            if (dop->value > dop->next->value)
            {
                arr = dop->value;
                dop->value = dop->next->value;
                dop->next->value = arr;
            }
            dop = dop->next;
        }
        dop1 = dop1->next;
    }
    Delete(List);
}


int main() {
    stek *p = new stek;

    p->head = NULL;

    add(100,p);
    add(200,p);
    add(150,p);
    add(500,p);
    add(70,p);
    add(700,p);
    add(300,p);
    add(45,p);
    add(90,p);
    add(300,p);
    //add(10,p);



 //   show(p);
 //   Sort2(p);
    show(p);
    del(p);
    show(p);
    Sort2(p);
    show(p);

}