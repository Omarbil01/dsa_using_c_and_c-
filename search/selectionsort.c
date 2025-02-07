#include<stdio.h>

void swap(int *x,int *y)
{

	int temp=*x;
	*x=*y;
	*y=temp;
}

void selectionsort(int a[],int n)
{
	int i,j,k;

	for(i=0;i<n-1;i++)
	{
		//n-1 passes will take place
		for(j=k=i;j<n;j++)
		{
			//j will scan the array, and k will
			//find min element
			if(a[j]<a[k])
			{
				k=j;
			}
		}
		swap(&a[i],&a[k]);
		//now we have min element which is
		//at k, we will swap the elements
		//
		//above steps will happen till n-1 passes
	}
}

int main()
{
	int a[]={8,7,5,3,2};
	int n=5;
	int i;

	selectionsort(a,n);

	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}