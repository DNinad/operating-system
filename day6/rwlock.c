#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

int completed=0;
pthread_mutex_t rwmutex;

int main()
{
	pthread_t intid,lcdtid,sertid;
	pthread_rwthread_init(&rwlock,NULL);
	pthread_create(&intid,NULL,inthread,NULL);
	pthread_create(&lcdtid,NULL,lcdthread,NULL);
	pthread_create(&sertid,NULL,serhread,NULL);
	pthread_join(intid,NULL);
	pthread_join(lcdtid,NULL);
	pthread_join(sertid,NULL);
}
