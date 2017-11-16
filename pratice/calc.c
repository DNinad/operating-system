#include<stdio.h>

#include"arith.h"

int main()
{
	int a,b;
	
	printf("Enter the values of a and b:-");
	scanf("%d%d",&a,&b);
	printf("The addition is:-%d\n",add(a,b));
	printf("The substraction is:-%d\n",sub(a,b));
	printf("The  multiplication is:-%d\n",mul(a,b));
	printf("The  division is:-%d\n",div(a,b));
	
	

	return 0;
}



