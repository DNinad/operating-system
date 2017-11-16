#include<stdio.h>

#include"arith.h"

int main()
{
	int a,b,c,d;
	printf("Enter the values of a and b and c and d(for add,sub only):-");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("The addition is:-%d",add(a,b,c,d));
	printf("The substraction is:-%d",sub(a,b,c));
	//printf("The  multiplication is:-%d",mul(a,b));
	//printf("The  division is:-%d",div(a,b));

	return 0;
}



