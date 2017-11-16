#include<stdio.h>
#include <unistd.h>

int fd[2];
pid_t id;
unsigned char buffer[120];
int main(int argc, char *argv[])
{
	pipe(fd);
	id=fork();
	if(0==id){
		
	
	close(fd[1]);
	read(fd[0],buffer,120);
	printf("child:%s\n",buffer);

	
	}
	else if(buffer==0)
		
		printf("read error"); 
	
	
	
	else{
		
	close(fd[0]);

	write(fd[1],"hi\n",3);
	close(fd[1]);
	}
}
