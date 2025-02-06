#include<stdio.h>

void swap(int *x,int *y)
{

	int temp=*x;
	*x=*y;
	*y=temp;
}

void bubblesort(int a[],int n)
{
	int flag;
	for(int i=0;i<n-1;i++)
	//bubblesort takes n-1 passes
	//n is length of list, if 
	//length is 5, then 5-1=4 
	//passes will take place
	{
		flag=0;
		//flag is to check if list
		//is already sorted
		for(int j=0;j<n-1-i;j++)
		//n-1-i will also look at 
		//passes, if n-1-i becomes
		//0, then no passes can take 
		//place and j is used for swapping
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
}

int main()
{
	int a[]={8,7,5,3,2};
	int n=5;
	int i;

	bubblesort(a,n);

	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}