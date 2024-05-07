//race condition
#include<stdio.h>
#include<omp.h>

int main()
{
	int tid,nthreads;	
	#pragma omp parallel  num_threads(4)
	{
		tid = omp_get_thread_num();
		printf("Hello World in to %d\n" ,tid);

		if (tid == 1)
		{
			nthreads = omp_get_num_threads();
			printf("Number of threads %d \n",nthreads);
		}
	}
}
