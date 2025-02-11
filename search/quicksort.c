#include<stdio.h>

void swap(int *x,int *y)
{

	int temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int a[],int l,int h)
{
	int pivot=a[l];
	int i=l;
	int j=h;
	//we are taking first element 
	//as pivot and i will find 
	//bigger element than pivot and j 
	//will find smaller element than 
	//pivot

	do
	{
		do
		{
			i++;
			//finds bigger elenment than
			//pivot element
		}while(i<h && a[i]<=pivot);

		do
		{
			j--;
			//finds smaller element than
			//pivot element
		}while(a[j]>pivot);

		if(i<j)
		{
			swap(&a[i],&a[j]);
			//i finds high element and 
			//j finds low element than pivot and swapping
			//will take place iff i<j
		}while(i<j);
	}while(i<j);

	swap(&a[l],&a[j]);
	//swapping of pivot element 
	//with where a[j] is
		return j;
		//returns pivot index
}

void quicksort(int a[],int l,int h)
{
	int j;
	if(l<h)
	{
		j=partition(a,l,h);
		//index where pivot element is returned
		quicksort(a,l,j);
		//sorting of left side from low to pivot
		quicksort(a,j+1,h);
		//sorting of right side from
		//pivot+1 to high
	}
}

int main()
{
	int a[]={12,10,8,5,2,65535};
	int n=6;
	int l=0;

	quicksort(a,l,n-1);

	for(int i=0;i<n-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}