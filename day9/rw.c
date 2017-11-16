#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
/* Initialize read-write lock RWLOCK using attributes ATTR, or use
   the default values if later is NULL.  */
/*extern int pthread_rwlock_init (pthread_rwlock_t *__restrict __rwlock,
				const pthread_rwlockattr_t *__restrict
				__attr) __THROW __nonnull ((1));

/* Destroy read-write lock RWLOCK.  */
/*extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock)
     __THROW __nonnull ((1));*/

pthread_rwlock_t rwlock;
pthread_t tidread1, tidwrite1, tidread2, tidwrite2;
int a=10;
void  *read1thread(void *data)
{
	sleep(2);
	printf("I am in read 2\n");
	pthread_rwlock_rdlock(&rwlock);
	printf("read:1%d\n",a);
	sleep(2);
	printf("I am in read1 rwlock\n");
	pthread_rwlock_unlock(&rwlock);
	
}
void  *read2thread(void *data)
{
	sleep(2);
	printf("I am in read 2\n");
	pthread_rwlock_rdlock(&rwlock);
	printf("read:2%d\n",a);
	sleep(2);
	printf("I am in read2 rwlock\n");
	pthread_rwlock_unlock(&rwlock);
	
}
void  *write1thread(void *data)
{
	
	printf("I am in write 1\n");
	pthread_rwlock_wrlock(&rwlock);
	a=a+1;
	sleep(4);
	printf("%d",a);
	pthread_rwlock_unlock(&rwlock);
	
}




void  *write2thread(void *data)
{
	
	printf("I am in write 2\n");
	pthread_rwlock_wrlock(&rwlock);
	printf("I am in write2 rwlock\n");
	a=a+1;
	sleep(4);
	printf("%d",a);
	pthread_rwlock_unlock(&rwlock);
}



int main()
{
	pthread_rwlock_init(&rwlock,NULL);
	pthread_create(&tidread1,NULL,read1thread,NULL);
	pthread_create(&tidread2,NULL,read2thread,NULL);
	pthread_create(&tidwrite1,NULL,write1thread,NULL);
	pthread_create(&tidwrite2,NULL,write2thread,NULL);
	


	pthread_join(tidread1,NULL);
	pthread_join(tidread2,NULL);
	pthread_join(tidwrite1,NULL);
	pthread_join(tidwrite2,NULL);
	pthread_rwlock_destroy(&rwlock);


}






