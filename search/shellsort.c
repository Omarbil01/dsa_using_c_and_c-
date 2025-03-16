#include<stdio.h>

void shellsort(int a[],int n)
{
	int gap;
	int i,j;

	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			int temp=a[i];
			j=i-gap;
			while(j>=0 && a[j]>temp)
			{
				a[j+gap]=a[j];
				j=j-gap;
			}
			a[j+gap]=temp;
		}
	}
}

int main()
{
	int a[]={12,10,8,5,2};
	int n=5;

	shellsort(a,n);

	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}