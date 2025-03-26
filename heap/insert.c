#include <stdio.h>

void insert(int a[],int n)
{
	int i=n;
	int temp;
	temp=a[i];

	while(i>1 && temp>a[i/2])
	{
		a[i]=a[i/2];
		i /= 2;
	}	
	a[i]=temp;
}

int main()
{
	int a[]={0,45,35,15,30,10,12,0};

	for(int i=2;i<=6;i++)
	{
		insert(a,i);
	}

	printf("Displaying: \n");
	for(int i=2;i<=6;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}