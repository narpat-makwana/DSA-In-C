#include<stdio.h>
#define SIZE 20

int n,a[SIZE];

void main()
{
	void accept();
	void display();
	void insertionsort();
	
	printf("\n Enter how many Num U have: ");
	scanf("%d",&n);
	
	accept();
	
	printf("\n Array before Sort:\n");
	display();
	
	if(n>2)
	{
		insertionsort();
	}
	
	printf("\n Array after sort:\n");
	printf("\n\n");
	display();
	printf("\n\n");
	
	
}

void accept()
{
	int i;
	printf("\n Enter the %d element:",n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);	
	}
	
}

void display()
{
	int i;
	for(i=0;i<n;++i)
	{
		printf("\t%d",a[i]);
	}		
}

void insertionsort()
{
	int i,j,temp;
	
	for(i=1;i<n;++i)
	{
		temp = a[i];
		j = i-1;
		
		while(j>=0 && a[j]>=temp)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
		
	}
	
	
}

