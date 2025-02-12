#include<stdio.h>

void merge(int a[],int l,int m,int h)
{
	int i,j,k;
	int b[100];

	i=l;
	j=m+1;
	k=l;

	while(i<=m && j<=h)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}

	for(;i<=m;i++)
	{
		b[k++]=a[i];
	}
	for(;j<=h;j++)
	{
		b[k++]=a[j];
	}

	for(int i=l;i<=h;i++)
	{
		a[i]=b[i];
	}
}

void mergesort(int a[],int n)
{
	int p,l,h,mid,i;
	//p is for number of passes
	//for array of length 8
	//log(length) passes will
	//take plce i.e-3

	for(p=2;p<=n;p=p*2)
	{
		for(i=0;i+p-1<n;i=i+p)
		{
			//array divided to length of 2
			//so that merging will get easier
			l=i;
			h=i+p-1;
			mid=(l+h)/2;
			//sorting and merging will take place

			merge(a,l,mid,h);

		}
	}
	if(p/2<n)
	{
		//meaning if elements are left
		//in any divided array

		merge(a,0,p/2 - 1,n-1);
	}
}



int main()
{
	int a[]={12,10,8,5,2};
	int n=5;

	mergesort(a,5);

	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}