#include<stdio.h>
#include<omp.h>

int main()
{
#pragma omp parallel
	printf("Hello World %d \n",omp_get_thread_num());

}
