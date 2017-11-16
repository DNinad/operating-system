#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
 
int count=0,re;
pthread_mutex_t mutexcount;
pthread_mutexattr_t mythread; 

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
	
		re=pthread_mutex_lock(&mutexcount);	
		if(re==0)
		{
		count--;
		printf("Dec:%d\n",count);
		pthread_mutex_unlock(&mutexcount);
		}
		else
		{
			printf("error\n");
		}
	}
}

int main()
{
	pthread_t tidInc,tidDec;
	pthread_mutexattr_init(&mythread);
	pthread_mutexattr_settype(&mythread,PTHREAD_MUTEX_ERRORCHECK);
	pthread_mutex_init(&mutexcount,&mythread);
	pthread_create(&tidInc,NULL,IncThread,NULL);
	pthread_create(&tidDec,NULL,DecThread,NULL);
	pthread_join(tidInc,NULL);
	pthread_join(tidDec,NULL);
	pthread_mutex_destroy(&mutexcount);
	pthread_mutexattr_destroy(&mythread);
	return 0;	

}
