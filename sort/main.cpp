
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "fstream"
#include <stdio.h>
#include "cstring"
#include "climits"
#include "typeinfo"
#include "iomanip"

using namespace std;
const int limit=20;

struct ceh{
    string name;
    int value;
    int number;

};
struct ceh_mas{
    string name;
    int value;
    int number;
};
inline void eatline(){
    while (cin.get() != '\n')
    continue;
}

void quickSort(ceh_mas arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2].value;

    /* partition */
    while (i <= j) {
        while (arr[i].value < pivot)
            i++;
        while (arr[j].value > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
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
const char * file1 = "text.txt";
const char * file2 = "rez.txt";
int main()
{
    setlocale(LC_ALL, "Russian");
    fstream fout;
    int action;
    int num;
    fstream dout;
    ceh ceh1;
    int i = 0, j=0;

    ceh_mas *val = new ceh_mas[100];
    while (true){
        //system("cls");
            cout << "0.Выход\n1.Cоздать\n2.Просмотр\n3.Вывод на печать\n";
            cout << endl;
            cin >> action;
        switch (action)
        {
            case 0:
                return 0;
            case 1:
                eatline();
                cout << "Название цеха:";
                getline(cin,ceh1.name);
                cout << "Кол-во продукции:";
                cin >> ceh1.value;
                cout << "Номер Цеха:";
                cin >> ceh1.number;

                fout.open(file1, ios::out | ios::binary | ios::app);
                if (!fout.is_open()){
                    cerr << "Файл не открыт";
                    exit(1);
                }
                fout.write((char *)&ceh1, sizeof ceh1);
                fout.close();
                break;
                // fout.open(file1, ios::in | ios::binary | ios::app);//
            case 2:
                fout.open(file1, ios::in | ios::binary | ios::app);
                fout.seekg(0);
                if (!fout.is_open()){
                    cerr << "Файл не открыт";
                    exit(1);
                }
                while (fout.read((char *)&ceh1, sizeof ceh1)){
                    cout << "Название цеха:" << ceh1.name << "\nНомер цеха:" << ceh1.number
                    << "\nКол-во продукции:" << ceh1.value << endl;
                }
                fout.close();
                system("pause");
                break;
            case 3:

                cout << "Введите номер цеха:";
                cin >> num;

                fout.open(file1, ios::in | ios::binary);
                dout.open(file2, ios::out | ios::binary);


                while (fout.read((char *)&ceh1, sizeof ceh1)) {
                    if (ceh1.number == num) {

                        val[i].value = ceh1.value;
                        val[i].number = ceh1.number;
                        val[i].name = ceh1.name;

                        i++;



                        cout << i << endl;
                        cout << "----3----------------------------" << endl;
                        cout << "Название цеха:" << ceh1.name << "\nНомер цеха:" << ceh1.number
                             << "\nКол-во продукции:" << ceh1.value << endl;
                    }
                }
                for (int k = 0; k < i; k++) cout << val[k].value << endl;
                quickSort(val, 0, i-1);
                cout << "--------------------------------" << endl;
                for (int k = 0; k < i; k++) cout<< "Название цеха:" << val[k].name << "\nНомер цеха:" << val[k].number
                                                << "\nКол-во продукции:" << val[k].value << endl;


                fout.close();
                dout.close();
                break;
            default:
                break;

        }
    }

}