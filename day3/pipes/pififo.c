#include<stdio.h>


unsigned char buffer[120];
int main()
{
	int fd;
	mkfifo("desd");
	fd=open("desd",0_RDONLY);
	read(fd,buffer,120);
	printf("Reader:-%s sent \n",buffer);
	close(fd);
	return 0;


}
