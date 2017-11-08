#include<stdio.h>
#include<stdlib.h>

int completed=0;
pthread_mutex_t completemutex;
pthread_cond_t conditinalvar;

void *waitthread(void *data)
{
	pthread_mutex_lock(&completemutex);
	printf("");
	while(completed==0)
	{
		printf("waiting for update\n");
	}
	printf("relase the lock");
}

void *waitthread(void *data)
{
	pthread_mutex_lock(&completemutex);
	printf("");
	
	completed=1;
	printf("update\n");
	

	printf("relase the lock");
}
