#include <stdio.h>
#include<stdlib.h>
#include <time.h>

int main()
{
    double **a, **b, **mul;
    int i,j,k;

    //allocation for rows
    a = (double **) malloc(sizeof(double *) * 1024);
    b = (double **) malloc(sizeof(double *) * 1024);
    mul = (double **) malloc(sizeof(double *) * 1024);

    //allocation for columns
    for(i=0; i<1024; i++)
 	a[i] = (double *)malloc(sizeof(double) * 1024);
    for(i=0; i<1024; i++)
 	b[i] = (double *)malloc(sizeof(double) * 1024);
    for(i=0; i<1024; i++)
 	mul[i] = (double *)malloc(sizeof(double) * 1024);

 	for(i=0; i<1024; i++)
	for(j=0; j<1024; j++)
		a[i][j]=1;

    for(i=0; i<1024; i++)
	for(j=0; j<1024; j++)
		b[i][j]=1;

    clock_t t;
    t = clock();
	//multiplication matrix c (c = a*b)
    for(i=0; i<1024; i++)
    {
        for(j=0; j<1024; j++)
        {
            mul[i][j] = 0;
            for(k=0; k<1024; k++)
            mul[i][j] = mul[i][j] + a[i][k] * b[k][j];
        }
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("%f seconds to execute meat portion \n", time_taken);

    return 0;
}
