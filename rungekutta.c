#include "stdio.h"
#include "malloc.h"
#include "assert.h"
#include "math.h"
#include "runge-kutta.h"

void init_traject(traject_t *y, size_t size) {
	y->y =(double *)malloc(sizeof(double)*size);
	y->len=0;
	y->maxlen=size;
}

void done_traject(traject_t *y) {
	free(y->y);
	y->y=NULL;
	y->len = 0;
}

double f(double x, double y, const kettlebc_t * k){
	return -k->k*(y-k->Tenv);
} 

  
// Находит значение y для заданного x, используя размер шага h
// и начальное значение y0 в x0.

double rungeKutta(const kettlebc_t * k, traject_t * y, 
			double h, double eps) 

{ 

    // Подсчитать количество итераций, используя размер шага или

    // высота шага h


  

    double k1, k2, k3, k4; 

  
	
    y->y[0] = k->T;
	y->y[1] = k->T;
	double t = 0; 
	double T = k->T;
	size_t i = 0;

    do { 
		if (i >= y->maxlen) break;
		y->y[i++] = T;
        // Применить формулы Рунге Кутты, чтобы найти

        // следующее значение T

        k1 = h*f(t, T,k); 

        k2 = h*f(t + 0.5*h, T + 0.5*k1,k); 

        k3 = h*f(t + 0.5*h, T + 0.5*k2,k); 

        k4 = h*f(t + h, T + k3,k); 

  

        // Обновить следующее значение T

        T = T + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);; 

  

        // Обновляем следующее значение x

        t = t + h; 
    } while (T-k->Tenv>eps || t>k->tend);
	
	y->len=i+1;
  

    return 0; 

} 
