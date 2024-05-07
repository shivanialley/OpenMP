#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char *argv[])
{
	int nthreads,tid;
	#pragma omp parallel private(nthreads,tid) num_threads(4)
	{
		tid = omp_get_thread_num();
		printf("hello World from thread = %d\n", tid);
		if(tid == 0)
		{
			nthreads = omp_get_num_threads();
				
			printf("Number of threads = %d\n", nthreads);
			
		}
	}
}
