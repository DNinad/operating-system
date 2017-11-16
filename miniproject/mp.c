#include<stdio.h>
#include<string.h>
#include<sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>

int fd[2],o,file_pipes[2],data_processed,some_data;
char a[20],ch,*ele;
const char *name;
FILE *fp;
//char ch;

pid_t id,fork_result;
void statdir()
{
	pipe(fd);
	id = fork();

	if(0!=id)
	{	

		scanf("%s",a);
		write(fd[1],a,20);
	}	
	else
	{
		read(fd[0],a,20);
		execl(a,a,"-a","-l",NULL);

	}
}

void stringl()
{
	ch=getc(fp);
			
	while(ch!=EOF)
	{
		//fp=fopen("1.txt","r");	
		printf("%c",ch);
		//scanf("%c",ele);
		//strcmp(fp,ele);
		ch=getc(fp);
				
	}
	fclose(fp);
}
void delduplicate()
{
	
	
	char buffer[100]="fdupes -d ";
	strcat(buffer,a);
	system(buffer);
	
}
void duplicatefiles()
{
	
	scanf("%s",a);
	char buffer[100]="fdupes -r ";
	strcat(buffer,a);
	system(buffer);
	delduplicate();
}



int main()
{
	
	printf("enter option to do opertion\n1.statisticsof directory\n 2.string occurrence nd line number\n 3.duplicates and delete duplicate files in directory\n 4.file log\n ");
		
		scanf("%d",&o);
		switch(o)
		{
		case 1:
			statdir();
			break;
		
		case 2:
			system("ls");
			//scanf("%[^\n]s",name);
			fp=fopen("1.txt","r");	
			
			stringl();
			break;
			
		case 3:
			duplicatefiles();
			break;
	
		case 4:
			
			break;
		
		
	}
	
}
