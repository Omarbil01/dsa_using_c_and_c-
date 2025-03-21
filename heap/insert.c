#include <stdio.h>

void insert(int a[],int *n,int key)
{
	int i = *n;
	a[i]=key;
	(*n)++;

	while(i>=1 && a[i]>a[(i-1)/2])
	{
		int temp=a[i];
		a[i]=a[(i-1)/2];
		a[(i-1)/2]=temp;

		i = (i-1)/2;
	}	
}

void display(int a[],int n)
{
	printf("Max heap: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main()
{
	int a[15]={45,35,15,30,10,12};
	int n=6;

	int key=48;
	insert(a,&n,key);

	printf("Displaying: \n");
	display(a,n);
	printf("\n");

	return 0;
}