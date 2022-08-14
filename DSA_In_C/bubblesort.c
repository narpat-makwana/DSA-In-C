#include<stdio.h>
#define SIZE 20

int n,a[SIZE];

void main()
{
	void accept();
	void display();
	void bubblesort();
	
	printf("\n Enter how many no You have:\n");
	scanf("%d",&n);
	
	accept();
	printf("\n Array before sort :");
	printf("\n\n");
	
	display();
	
	if(n>2)
	{
		bubblesort();
	}
	printf("\n Array after sort:");
	printf("\n\n");
	display();
	printf("\n\n");	
}

void accept()
{
	int i;
	printf("\n Enter %d elements: ",n);
	
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	
}

void display()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
}

void bubblesort()
{
	int i,j,temp,flag;
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<n-1-i;++j)
		{
			flag=0;
			if(a[j]>a[j+1])
			{
				flag=1;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		if(flag == 0)
		{
			break;
		}
	}
}

