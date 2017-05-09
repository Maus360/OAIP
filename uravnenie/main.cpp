#include <iostream>
#include <cmath>

double f(double x){
    return pow(x,3)+10*pow(x,2)-50;
}


double Metod1(double x0,double x1,double eps) {
    double y0,y1,x2,de;
    y0=f(x0);	   y1=f(x1);
    do  {
        x2=x1-y1*(x1-x0)/(y1-y0);
        de=fabs(x1-x2);
        x0=x1; 	x1=x2; 	y0=y1; 	y1=f(x2);
    }   while (de>eps);
    return x2;	    // Возвращаем значение, для которого достигнута точность
}


int main() {
    double a, b, h;
    std::cout << "Введите a" << std::endl;
    std::cin >> a;
    std::cout << "Введите b" << std::endl;
    std::cin >> b;
    std::cout << "Введите h" << std::endl;
    std::cin >> h;
    for (double i = a; i <= b; i+=h){
        if(f(i)*f(i+h)<0) {
            std::cout << Metod1(i, i + h, 0.000000000001) << std::endl;
            std::cout << f(Metod1(i, i + h, 0.00000000001)) << std::endl;
        }
    }
    return 0;
}