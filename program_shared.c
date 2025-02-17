#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define N 30
int main(int argc, char *argv[])
{
	int nthreads,tid,i,chunk;
	float a[N],b[N],c[N],d[N];
	for(i=0;i<N;i++)	
	{
		a[i] = i * 1.5;
		b[i] = i + 22.35;
		c[i] = d[i] = 0.0;
	}
	#pragma omp parallel shared(a,b,c,nthreads) private(i,tid) 
	{
		tid = omp_get_thread_num();
		
		if(tid == 0)
		{
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n", nthreads);
			
		}
		#pragma omp sections nowait
		{
			#pragma omp section
			{
				printf("Thread %d doing section 1\n",tid);
				for(i=0;i<N;i++)
				{
					c[i] = a[i] +b[i];
					printf("Thread %d: c[%d] = %f\n",tid,i,c[i]);		
				}
			}

		 	#pragma omp section
                        {
                                printf("Thread %d doing section 2\n",tid);
                                for(i=0;i<N;i++)
                                {
                                        c[i] = a[i] * b[i];
                                        printf("Thread %d: c[%d] = %f\n",tid,i,c[i]);           
                                }
                        }
		}
	}
}

