#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void swap(int *x,int *y)
{

	int temp=*x;
	*x=*y;
	*y=temp;
}

int findmax(int a[], int n)
{
	int x=INT_MIN;

	for(int i=0;i<n;i++)
	{
		if(a[i]>x)
		{
			x=a[i];
		}
	}
	return x;
}
  
void countsort(int a[],int n)
{
	int max;
	int *c;
	max=findmax(a,n);
	c=(int *)malloc(sizeof(int)*(max+1));

	for(int i=0;i<max+1;i++)
	{
		c[i] = 0;
	}

	for(int i=0;i<n;i++)
	{
		c[a[i]]++;
	}

	int i=0;
	int j=0;

	while(i<max+1)
	{
		if(c[i]>0)
		{
			a[j++]=i;
			c[i]--;
		}
		else
		{
			i++;
		}
	}

}

int main()
{
	int a[]={8,7,5,3,2,2,5,13,22,13,17,19};
	int n=12;
	int i;

	countsort(a,n);

	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}