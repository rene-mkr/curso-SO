/*
 ============================================================================
 Name        : suma.c
 Author      : Rene
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : ejemplo con pthreads
 ============================================================================
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum=0; /* this data is shared by the thread(s) */
void* runner(void *param); /* the thread */
int main(int argc, char *argv[]) {
	pthread_t tid; /* the thread identifier */
	pthread_attr_t attr; /* set of attributes for the thread */
	if (argc != 2) {
		fprintf(stderr, "usage: a.out <integer value>\n");
		/*exit(1);*/
		return -1;
	}
	if (atoi(argv[1]) < 0) {
		fprintf(stderr, "Argument %d must be non-negative\n", atoi(argv[1]));
		/*exit(1);*/
		return -1;
	}

	/* Mi limite es el parametro que recibo */
	int lim = atoi(argv[1]);
	
	int lim1[]= {1,lim};
	
	/* get the default attributes */
	pthread_attr_init(&attr);

	/* create the thread 1*/
	pthread_create(&tid, &attr, runner, &lim1);

	/* create the thread 1*/
	pthread_create(&tid, &attr, runner, &lim1);
	
	/* now wait for the thread to exit */
	pthread_join(tid, NULL);
	printf("sum = %d\n", sum);
}
/**
 * The thread will begin control in this function
 */
void* runner(void *param) {
	int *par= (int *)param;
	int lower=par[0];
	int i, upper = par[1];
	if (upper > 0) {
		for (i = lower; i <= upper; i++)
			sum += i;
	}
	pthread_exit(0);
}
