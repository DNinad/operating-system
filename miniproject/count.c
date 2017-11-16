#define _GNU_SOURCE 
#include<stdio.h>

#include<stdlib.h>
#include<string.h>

	FILE *fp;
	char ch[1000];
	int *a,count=0,c=0;
	char file[100];
	char word[100];

void filecount()
{
	fp=fopen(file,"r");
	
	//word[100]=ch[100];
	while(fgets(ch,1000,fp) != NULL)
	{
		if(strstr(ch,word)==NULL)
		{
			count++;
			printf("matched found in :%d\n",c);
		}
		c++;
		
		fgets(ch,1000,fp);
	}
	printf("%d\n",count);
	fclose(fp);
}

int main()
{
	printf("enter file name to search :");
	//scanf("%[^\n]s",file);
	gets(file);

	printf("enter word to search in file :");
	//scanf("%[^\n]s",word);
	gets(word);
	filecount();
	//printf("%s",word);	
	
}
