#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int a=10;
pthread_t tidread1,tidread2,tidwrite1,tidwrite2;
pthread_rwlock_t rwlock;

void *read1(void * data)
{
	sleep(2);
	printf("I am in readlock1\n");
	pthread_rwlock_rdlock(&rwlock);
	printf("value1:- %d\n",a);
	sleep(2);
	pthread_rwlock_unlock(&rwlock);

}

void *read2(void *data)
{
	sleep(2);
	printf("I am in readlock2\n");
	pthread_rwlock_rdlock(&rwlock);

	printf("value2:-%d\n",a);
	sleep(2);
	pthread_rwlock_unlock(&rwlock);
}

void *write1(void *data)
{
	//sleep(2);
	printf("I am in writelock1\n");
	pthread_rwlock_wrlock(&rwlock);
	a=a+10;
	
	printf("i am wrinting1\n");
	sleep(6);
	pthread_rwlock_unlock(&rwlock);
	
	
}

void *write2(void *data)
{	sleep(2);
	printf("i am in writelock2\n");
	pthread_rwlock_wrlock(&rwlock);
	a=a+20;
	//sleep(4);
	printf("i am wrinting2\n");
	pthread_rwlock_unlock(&rwlock);

}


int main()
{
	pthread_rwlock_init(&rwlock,NULL);
	pthread_create(&tidread1,NULL,read1,NULL);
	pthread_create(&tidread2,NULL,read2,NULL);
	pthread_create(&tidwrite1,NULL,write1,NULL);
	pthread_create(&tidwrite2,NULL,write2,NULL);
	

	pthread_join(tidread1,NULL);
	pthread_join(tidread2,NULL);
	pthread_join(tidwrite1,NULL);
	pthread_join(tidwrite2,NULL);
	
	pthread_rwlock_destroy(&rwlock);		
}
