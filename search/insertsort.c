#include<stdio.h>

void insertionsort(int a[],int n)
{
	int x;
	for(int i=1;i<n;i++)
	{
		//index at second index,
		//and another at i-1 index
		int j=i-1;
		x=a[i];

		while(j>-1 && a[j]>x)
		{
			//checking if elements at left are bigger or smaller
			//if smaller then keep going back
			//if bigger, then element should be at next index of smaller 
			//value
			a[j+1]=a[j];
			j--;
		}
		//if element is smaller, x element 
		//will be at smaller+1 index
		a[j+1]=x;
	}
}

int main()
{
	int a[]={12,10,8,5,2};
	int n=5;

	insertionsort(a,n);

	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}