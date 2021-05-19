#include "stdio.h"
#include "malloc.h"
#include "assert.h"
#include "math.h"
#include "runge-kutta.h"

#define TRSIZE 1024
#define H 0.9
#define EPS 0.001

int cauchie_kettle(kettlebc_t * k){
    k->Tenv=24;
    k->T=100;
    k->k=0.01;
    k->tend=100;
    return OK;
}


int out_traject(const traject_t * y) {
	assert (y->len>=0);
	for (size_t i = 0; i<y->len; i++){
		printf("T[%i]=%10.5f\n", i,  y->y[i]);
		
	};
}

int main() 

{ 
	kettlebc_t k;
	traject_t y;
	init_traject(&y, TRSIZE);
    printf("Euler modeler for kettle\n");
	cauchie_kettle(&k);
	rungeKutta(&k,&y, H, EPS);
	out_traject(&y);
	done_traject(&y);
    return 0;

}
