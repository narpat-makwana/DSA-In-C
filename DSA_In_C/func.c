#include<stdio.h>


int sum(int a,int b)
	{
		int c = a + b;
		return c;
	}
		
int main()
{
	int num1,num2;
	printf("\n Enter the first number: ");
	scanf("%d",&num1);
	printf("\n Enter the second number: ");
	scanf("%d",&num2);
	printf("\n The Sum os Num =%d",sum(num1,num2));
	return 0;
	
}
	

