#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
 
int count=0;
pthread_mutex_t mutexcount;
 

void *IncThread(void *data)
{
	while(1)
	{
		pthread_mutex_lock(&mutexcount);
		count++;
		printf("Inc:%d\n",count);
		pthread_mutex_unlock(&mutexcount);
	}
}

void *DecThread(void *data)
{
	while(1)
	{	
		pthread_mutex_lock(&mutexcount);
		count--;
		printf("Dec:%d\n",count);
		pthread_mutex_unlock(&mutexcount);
	}
}

int main()
{
	pthread_t tidInc,tidDec;
	pthread_mutex_init(&mutexcount,NULL);
	pthread_create(&tidInc,NULL,IncThread,NULL);
	pthread_create(&tidDec,NULL,DecThread,NULL);
	pthread_join(tidInc,NULL);
	pthread_join(tidDec,NULL);
	pthread_mutex_destroy(&mutexcount);
	return 0;	

}
