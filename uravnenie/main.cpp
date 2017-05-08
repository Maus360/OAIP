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
    std::cout << "Hello, World!" << std::endl;
    for (double i = -12; i <= 5; i+=0.5){
        if(f(i)*f(i+0.5)<0)
            std::cout << Metod1(i, i+0.5, 0.1) << std::endl;
    }
    return 0;
}