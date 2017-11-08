#include<stdio.h>

#include"arith.h"

int main()
{
	int a,b,c,n=0;
	printf("Enter the values of a and b and c(for add,sub only):-");
	scanf("%d%d%d",&a,&b,&c);
	printf("Enter the number for factorial:- ");
	scanf("%d",&n);
	
	printf("The addition is:-%d\n",add(a,b,c));
	printf("The substraction is:-%d\n",sub(a,b,c));
	printf("The  multiplication is:-%d\n",mul(a,b));
	printf("The  division is:-%d\n",div(a,b));
	printf("the factorial is:-%d",fact(n));	
	task2();
	return 0;
}



