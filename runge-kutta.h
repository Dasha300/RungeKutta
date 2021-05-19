#ifndef __RUNGEKUTTA_C__
#define __RUNGEKUTTA_C__

#define OK 0
#define NOK -1

typedef struct {
    double Tenv, T, k, tend;
} kettlebc_t;

typedef struct {
    size_t len;
	size_t maxlen;
    double *y;
}traject_t;

double f(double x, double y, const kettlebc_t * k);

double rungeKutta(const kettlebc_t * k, traject_t * y, 
			double h, double eps);
			
void done_traject(traject_t *y);

void init_traject(traject_t *y, size_t size);

#endif //__RUNGEKUTTA_C__
