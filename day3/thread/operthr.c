#include<stdio.h>
#include<pthread.h>
int count=0;

void *IncThread(void *data){
while(1)
{
count++;
printf("Inc:%d\n",count);
}

}
void *DecThread(void *data){
while(1)
{
count--;
printf("Dec:%d\n",count);
}
}
int main(){
	pthread_t tidInc,tidDec;
	pthread_create(&tidInc,NULL,IncThread,NULL);
	pthread_create(&tidDec,NULL,DecThread,NULL);
	pthread_join(tidInc,NULL);
	pthread_join(tidDec,NULL);
	return 0;	

}
