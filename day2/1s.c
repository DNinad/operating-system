#include<stdio.h>

#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t id;

	int a=0;//b=3,c=0;

	printf("Before fork  %d %d\n",getpid(),getppid());	

	id=fork();
	printf("print parent1 %d\n",a);
	a++;	
	sleep (1);
	printf("print parent1 %d\n",a);
	sleep (1);	
	a++;
	printf("print parent1 %d\n",a);
	a++;
	
	
	//printf("after fork  %d %d\n",getpid(),getppid());
	printf("after fork  %d %d\n",getpid(),getppid());
	//printf("print parent2 %d\n",a);
	sleep (2);
	a+=200;
	printf("print parent2 %d\n",a);
	sleep (2);
	a++;
	printf("print parent2 %d\n",a);
	a++;
	
	return 0;
}
