#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// fibonacci sequence size.
int n;                    

//Fibonacci sequence.
int *fibSeq;                    

//Global variable for counting threads
//it is used in main and thread work
int i;                      

void *runn(void *arg);

/*
	Compile:
	gcc -pthread fib.c -o fib.out
	
	Execute:
	./fib.out n
	
	(n stands for the length of the Fibonacci Sequence and 
	the number of threads that is going to be created)
*/

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Use the given format:./fib.out <number of threads/fibonacci seq. size>\n");
        return -1;
    }                          

    n = atoi(argv[1]);
    fibSeq = (int *)malloc(sizeof(int)*n);
    pthread_t *threads = (pthread_t *) malloc(n * sizeof(pthread_t));
    pthread_attr_t attr;        

    pthread_attr_init(&attr);

    for (i = 0; i < n; i++)
    {
        pthread_create(&threads[i], &attr, runn, NULL);
        pthread_join(threads[i], NULL);
    }                           

    printf("\nThe Fibonacci sequence.:\n");
    int k;

    for (k = 0; k < n; k++)
    {
        printf("%d\n", fibSeq[k]);
    }                           
    return 0;
}                               

void *runn(void *arg)
{
	//int id = (int)arg;
    if (i == 0)
    {
        fibSeq[i] = 0;
        pthread_exit(0);
    }                           

    if (i == 1)
    {
        fibSeq[i] = 1;
        pthread_exit(0);
    }                           
    else
    {
        fibSeq[0] = 0;
        fibSeq[1] = 1;

        int p, pp, fibp, fibpp;

        p = (i - 1);
        pp = (i - 2);
        fibp = fibSeq[p];
        
        fibpp = fibSeq[pp];
        
        fibSeq[i] = fibSeq[i - 1] + fibSeq[i - 2];
        
        pthread_exit(0);        
    }                           
}                               
