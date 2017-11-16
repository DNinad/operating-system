#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
int count=0;
pthread_mutexattr_t mythread;
pthread_mutex_t mutexcount;

void *IncThread(void *data)
{
	while(1)
	{
		pthread_mutex_lock(&mutexcount);
		pthread_mutex_lock(&mutexcount);
		count++;
		printf("Inc:%d\n",count);
		pthread_mutex_unlock(&mutexcount);
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
	pthread_mutexattr_init(&mythread);
	pthread_mutexattr_settype(&mythread,PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mutexcount,&mythread);	
	pthread_create(&tidInc,NULL,IncThread,NULL);
	pthread_create(&tidDec,NULL,DecThread,NULL);
	pthread_join(tidInc,NULL);
	pthread_join(tidDec,NULL);
	pthread_mutex_destroy(&mutexcount);
	pthread_mutexattr_destroy(&mythread);
	return 0;	

}
