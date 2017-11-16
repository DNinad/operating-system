#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
 //int sem_init(sem_t *sem, int pshared, unsigned int value);
//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
int a,b,sum=0;
sem_t input2calcsem;
sem_t calc2inputsem; 

void *inputThread(void *data){
	while(1)
	{
		sem_wait(&calc2inputsem);
		scanf("%d",&a);
		scanf("%d",&b);	
		sem_post(&input2calcsem);
	}
}


void *calcThread(void *data){
	while(1)
	{
		sem_wait(&input2calcsem);
		sum=a+b;
		printf("sum=%d\n",sum);
		sem_post(&calc2inputsem);
	}
}
int main(){
	pthread_t inputTid,calcTid;
	sem_init(&input2calcsem,0,0);
	sem_init(&calc2inputsem,0,1);
	pthread_create(&inputTid,NULL,inputThread,NULL);
	pthread_create(&calcTid,NULL,calcThread,NULL);
	pthread_join(calcTid,NULL);
	pthread_join(inputTid,NULL);
	sem_destroy(&input2calcsem);
	sem_destroy(&calc2inputsem);

	return 0;	

}
