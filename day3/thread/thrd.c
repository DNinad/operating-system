#include<stdio.h>
#include <pthread.h>


//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);


void *helloThread(void *data){
printf("Hello\n");}

int main(){

	pthread_t tid;
	printf("Before the thread creation\n");
	pthread_create(&tid,NULL,helloThread,NULL);

	printf("After the thread creation\n");
	pthread_join(tid,NULL);
	
	return 0;

}

