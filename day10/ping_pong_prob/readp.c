#include<unistd.h>
#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<semaphore.h>
#include<string.h>
#define MAX 128
void main()
{
	int fd1,fd2;
	sem_t *sem1, *sem2;
	char *str1, *str2;
	char msg[MAX];
	
	fd1 = shm_open("shrdbuf1", O_CREAT | O_RDWR,0600);
	fd2 = shm_open("shrdbuf2", O_CREAT | O_RDWR,0600);
	
	ftruncate(fd1,MAX);
	ftruncate(fd2,MAX);
	
	str1 = mmap(NULL,MAX,PROT_WRITE | PROT_READ,MAP_SHARED,fd1,0);
	str2 = mmap(NULL,MAX,PROT_WRITE | PROT_READ,MAP_SHARED,fd2,0);

	sem1=sem_open("/sem1",O_CREAT,0600,1);
	sem2=sem_open("/sem2",O_CREAT,0600,0);

	while(1)
	{
		sem_wait(sem2);
		sem_post(sem1);
		strcpy(msg,str2);
		puts(msg);
		sem_wait(sem1);
		strcpy(msg,str1);
		puts(msg);
		sem_post(sem2);
		
	}	
	

}
