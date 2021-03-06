#include <stdio.h>
#include <math.h>

/* definizione della funzione di cui si vuole calcolare
   lo zero                                              */
double func(double);

int main() {

    /* numero di iterazioni */
    int n;
    /* punti di partenza, soluzione, soluzioni vecchia, precisione
       desiderata, errore                                          */
    double a,a0,b0,b,c,c_old,eps,err;

    FILE *infile;
    FILE *outfile;

    /* apertura del file di input e lettura delle variabili */
    infile = fopen("bisez2.in","r");
    if (infile != NULL) {
	fscanf(infile,"%lf",&a0);
	fscanf(infile,"%lf",&b0);
	fscanf(infile,"%lf",&eps);
    }
    else {
	fprintf(stderr,"errore nel file di input!\n");
	return 1;
    }

    /* check per vedere se l'intervallo considerato e' adatto
       all'uitilizzo del metodo di bisezione                  */
    if(func(a0)*func(b0) > 0.) {
	fprintf(stderr,"attenzione! l'intervallo inserito non e' corretto!\n");
	return 2;
    }

    /* inizializzazione delle variabili */
    n = 0;
    a = a0;
    b = b0;

    /* apertura del file di output e scrittura della intestazione */
    outfile = fopen("bisez2.out","w");
    fprintf(outfile,"-----------------------------------------------------------------------------\n");
    fprintf(outfile,"| it |      c     |      f(c)     |      a     |      b     |       err     |\n");
    fprintf(outfile,"-----------------------------------------------------------------------------\n");
  

    /* la condizione del while e' determinata dalla precisione cercata */
    do {
	/* aggiornamento del numero di iterazioni eseguite */
	n++;
	c = 0.5*(a+b);
	/* test per determinare se lo zero e' nella meta' sinistra o destra */
	if (func(a)*func(c) < 0.) {
	    b = c;
	}
	else {
	    a = c;
	}
	err = fabs(c - c_old);
	fprintf(outfile,"| %2d | %10.8f | %+e | %10.8f | %10.8f | %+e |\n",n,c,func(c),a,b,err);
	c_old = c;
    }
    while(err > eps);

    /* risultato finale a schermo */
    fprintf(stdout,"Zero calcolato nell'intervallo (%f,%f) con precisione %e.\n c = %12.10f in %d iterazioni\n",a0,b0,eps,c,n);

    return 0;
}

/* funzione studiata */
double func(double x) {
    double y;
    y = exp(x)*sin(x)-x*x*x;
    return y;
} 
