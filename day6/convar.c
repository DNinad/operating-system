#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

int completed=0;
pthread_mutex_t completemutex;
pthread_cond_t conditionalvar;

void *waitthread(void *data)
{
	pthread_mutex_lock(&completemutex);
	printf("wait got mutex\n");
	while(completed==0)
	{
		printf("waiting for update\n");
		pthread_cond_wait(&conditionalvar,&completemutex);
	}
	printf("wt:relase the lock\n");
	pthread_mutex_unlock(&completemutex);
}

void *upthread(void *data)
{
	pthread_mutex_lock(&completemutex);
	printf("update got mutex\n");
	
	completed=1;
	printf("updated the complete\n");
	printf("up:relase the lock\n");
	pthread_mutex_unlock(&completemutex);
	pthread_cond_signal(&conditionalvar);
}

int main()
{
	pthread_t waittid,uptid;
	pthread_mutex_init(&completemutex,NULL);
	pthread_cond_init(&conditionalvar,NULL);
	pthread_create(&waittid,NULL,waitthread,NULL);
	pthread_create(&uptid,NULL,upthread,NULL);
	pthread_join(waittid,NULL);
	pthread_join(uptid,NULL);
	return 0;
}
