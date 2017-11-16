#include<stdio.h>

#include <unistd.h>

int main()
{
pid_t  id;//fork(void);

printf("\n Before fork\n");
id=fork();
printf("\n after fork\n");
return 0;

}
