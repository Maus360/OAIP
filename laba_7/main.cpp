#include <iostream>
#include <math.h>

double f(double x){
    return pow(x,3) + 10*pow(x,2) - 50;
}

double Metod1(double x0,double x1) {
    double y0,y1,x2;
    y0=f(x0);
    y1=f(x1);
    x2=x1-y1*(x1-x0)/(y1-y0);
    x0=x1; 	x1=x2; 	y0=y1; 	y1=f(x2);
    x2=x1-y1*(x1-x0)/(y1-y0);


    std::cout<<x2<<" ";   // Возвращаем значение, для которого достигнута точность
}

int main() {
    std::cout << "Hello World!" << std::endl;
    std::cout << Metod1(-12, 5) << std::endl;
    return 0;
}