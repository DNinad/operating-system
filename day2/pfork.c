#include<stdio.h>

#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t id;
	

	printf("Before fork  %d %d\n",getpid(),getppid());
		
	id = fork();
	
	printf("after fork  %d %d\n",getpid(),getppid());
	
	return 0;
}
