#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define CHUNKSIZE 7
#define N 30
int main(int argc, char *argv[])
{
	int nthreads,tid,i,chunk;
	float a[N],b[N],c[N];
	for(i=0;i<N;i++)	
		a[i] = b[i] = i *2.0;
	chunk = CHUNKSIZE;
	#pragma omp parallel shared(a,b,c,nthreads,chunk) private(i,tid) num_threads(4)
	{
		tid = omp_get_thread_num();
		printf("hello World from thread = %d\n", tid);
		if(tid == 0)
		{
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n", nthreads);
			
		}
		#pragma omp for schedule(dynamic,chunk) 
		
		for(i=0;i<N;i++) 
		{
			c[i] = a[i] + b[i];
			printf("Thread %d: c[%d] = %f\n",tid,i,c[i]);
		}
		
	}
}
