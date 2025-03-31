#include<stdio.h>

void swap(int a[], int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void heapify(int a[],int n)
{
	for(int i=(n/2)-1; i>=0; i--)
	{
		int j=2*i +1; //lchild
		while(j<n)
		{
			if(j+1<n && a[j]<a[j+1])
			{
				j += 1;
			}

			if(a[i]<a[j])
			{
				swap(a,i,j);
				i=j;
				j=2*i + 1;
			}

			else
			{
				break;
			}
		}
	}
}

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main()
{
	int a[]={5,10,30,20,35,40,15};
	int n=7;

	heapify(a,n);

	printf("Heapify print: \n");
	print(a,n);
	printf("\n");

	return 0;
}