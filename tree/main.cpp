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
    if (lol->value == value) {
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

tree *dellist(tree *proot, int inf){
    tree *ps = proot, *pr = proot, *w, *v;
    while ((ps!=NULL)&&(ps->value!=inf)){
        pr=ps;
        if (inf<ps->value) ps = ps->l;
        else ps = ps->r;
    }
    if (ps==NULL) return proot;

    if ((ps->l==NULL) && (ps->r==NULL)){
        if (pr==ps){
            delete(ps);
            return NULL;
        }
        if (ps->l == ps) pr->l=NULL;
        else pr->r = NULL;
        delete(ps);
        return proot;
    }
    if (ps->l == NULL) {
        if (ps == pr) {
            ps = ps->r;
            delete (pr);
            return ps;
        }
        if (pr->l == ps) pr->l = ps->r;
        else pr->r = ps->r;
        delete (ps);
        return proot;
    }
    if (ps->r==NULL){
        if (ps==pr){
            ps = ps->l;
            delete(pr);
            return ps;
        }
        if (pr->l ==ps) pr->l = ps->l;
        else pr->r = ps->l;
        delete(ps);
        return proot;
    }
    w = ps->l;
    if (w->r == NULL)
        w->r = ps->r;
    else{
        while(w->r!=NULL){
            v=w;
            w=w->r;
        }
        v->r = w->l;
        w->l = ps->l;
        w->r = ps->r;
    }
    if (ps==pr){
        delete(ps);
        return w;
    }
    if (pr->l == ps)
        pr->l=w;
    else
        pr->r = w;
    delete(ps);
    return proot;
}

int count = 0;
void task(tree *lol){
    //std::cout << count << std::endl;
    if (lol->l==NULL and lol->r==NULL) return;

    if (lol->l == NULL or lol->r == NULL) count++;

    if (lol->l!=NULL){
        task(lol->l);
    }
    if (lol->r!=NULL){
        task(lol->r);
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
    std::cout<<std::endl;
    quickSort(a, 0, n-1);
    tree *lol = add(0, n-1, a);
    show(lol);
    std::cout<<std::endl;
    //std::cout<<search(lol, 5)<<std::endl;
    //dellist(lol, 3);
    //show(lol);

    task(lol);
    std::cout << count << std::endl;
}