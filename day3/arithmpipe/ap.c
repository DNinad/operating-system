#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int fd[2],a,b,sum=0,fd1[2];
pid_t id;
char s[100];
char buffer[120];
int main()
{

	pipe(fd);
	pipe(fd1);
	id=fork();
	
	if(0==id)
	{
			
		close(fd[1]);
		close(fd1[0]);
	
		read(fd[0],buffer,120);
		a=atoi(buffer);
		
		read(fd[0],buffer,120);
		b=atoi(buffer);
		printf("%d	%d",a,b);
		sum=a+b;
		printf("sa %d\n",sum);
		sprintf(s,"%d",sum);
		strcpy(buffer,s);

		write(fd1[1],buffer,20);
	}
	/*else if(buffer==0)		
		printf("read error"); 	
	*/
	else{	
	close(fd[0]);
	close(fd1[1]);

	write(fd[1],"6\n",20);
	write(fd[1],"5\n",20);

	read(fd1[0],buffer,120);
	printf("sum=%d\n",(atoi(buffer)));

	close(fd[1]);
	close(fd1[0]);
	}
	return 0;
}
