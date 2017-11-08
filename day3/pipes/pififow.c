
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
 #include <unistd.h>

unsigned char buffer[120];
int main()
{
	int fd;
	mkfifo("desd",S_IRUSR | S_IWUSR);
	fd=open("desd",O_WRONLY);
	write(fd,"hii\n",120);
	
	close(fd);
	

	return 0;


}
