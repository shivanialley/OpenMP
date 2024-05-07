#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
	int cores,nthreads,tid,maxt,inpar;
	#pragma omp parallel
	{
		tid = omp_get_thread_num();
		if(tid == 3)
		{
			printf("Thread %d getting Info..\n",tid);
			cores = omp_get_num_procs();
			nthreads = omp_get_num_threads();
			maxt = omp_get_max_threads();
			inpar = omp_in_parallel();

			printf("Number of cores = %d\n", cores);
			printf("Number of threads = %d\n", nthreads);
			printf("Max threads = %d\n", maxt);
			printf("In Parallel? = %d\n", inpar);
		}
	}
}
