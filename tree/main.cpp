#include <iostream>

struct tree{
    int value=NULL;
    tree *r=NULL;
    tree *l = NULL;
} *proof;

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    };


    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
tree * add(int l , int r , int mas[]){
    tree *lol;

    if (l>r){
        return NULL;
    }
    int m = (l+r)/2;
    lol = new tree;

    lol->value = mas[m];
    lol->l = add(l, m-1, mas);
    lol->r = add(m+1, r, mas);
    return lol;
}

void show(tree *lol){
    if (lol==NULL) return;

    show(lol->l);
    std::cout<<lol->value<<" ";
    show(lol->r);

}

int search(tree *lol, int value) {
    if (lol->value > value) {
        return value;
    }
    if (lol->value > value) {
        search(lol->r, value);
    }

    if (lol->value < value) {
        search(lol->l, value);
    }
    else{
        return 404;
    }

}

int main(){
    int n;
    int size;
    std::cout<<"Введите количество элементов" <<std::endl;
    std::cin>>n;
    int *a = new int[n];
    for (int i=0;i<n;i++) {
        std::cout<<"Введите "<<i+1<<"-й элемент"<<std::endl;
        std::cin>>a[i];


    }
    for (int i = 0; i<n; i++) std::cout<<a[i]<<" ";
    std::cout<<std::endl;
    quickSort(a, 0, n-1);

    tree *lol = add(0, n-1, a);

    show(lol);
    search(lol, 5);
}