#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

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
	pthread_mutex_unlock(&completemutex);
}

void *upthread(void *data)
{
	pthread_mutex_lock(&completemutex);
	printf("");
	
	completed=1;
	printf("updated the complete\n");
	printf("relase the lock");
	pthread_mutex_unlock(&completemutex);
}

int main()
{
	pthread_t waittid,uptid;
	pthread_mutex_init(&completemutex,NULL);
	pthread_create(&waittid,NULL,waitthread,NULL);
	pthread_create(&uptid,NULL,upthread,NULL);
	pthread_join(waittid,NULL);
	pthread_join(uptid,NULL);
	
}
