#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

//#include "header.h"

unsigned buffer[120];
int main(int argc,char const *argv[])
{
	int fd1[2],fd2[2],fd,a[2],res;
	//a[2],res;
	pid_t id;
	pipe(fd1);
	pipe(fd2);
	//char a1[2];

	id=fork();
	if(id!=0)
	{
		printf("enter values of a and b:-\n");
		scanf("%d%d",a,a+1);
		//a[0]=atol(argv[1]);
		//a[1]=atol(argv[2]);
		write(fd1[1],a,sizeof(a));
		read(fd2[0],&res,sizeof(res));
		printf("result=%d\n",res);

			
	}	


	else
	{
		read(fd1[0],a,sizeof(a));
		res=a[0]+a[1];
		write(fd2[1],&res,sizeof(res));


	}

	return 0;


}
