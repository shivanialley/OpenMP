#include<stdio.h>
#include<omp.h>

int main(int argc, char** argv)
{
	#pragma omp parallel
	printf("Welcome to CDAC Bangalore  %d \n",omp_get_thread_num());
}
