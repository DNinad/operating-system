#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
 #include <unistd.h>

int fd;
unsigned char buffer[120];
int main()
{
	
	
	fd=open("desd",O_RDONLY);
	read(fd,buffer,120);
	printf("Reader:-%s\n",buffer);
	close(fd);
	return 0;


}
