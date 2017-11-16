#include<stdio.h>

#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t id;
	pid_t pid;pid_t ppid;
	ppid=getppid();
	pid=getpid();

	printf("Before fork  %d \n",pid);
	printf("Before fork  %d \n",ppid);
		
	id = fork();
	printf("after fork  %d \n",pid);

	id = fork();
	printf("after fork2  %d \n",getpid());
		
	
	return 0;
}
