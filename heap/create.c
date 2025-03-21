#include <stdio.h>
#include <stdlib.h>

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
    int i,key;
    int size=15;
	int a[size];
	int n=0;
	
	printf("Enter the size of the heap: ");
	scanf("%d",&n);
	
	if(n>0 && n <= size)
	{
	    int count=0;
	    for(i=0;i<n;i++)
	    {
	        printf("Enter the value to be added: ");
	        scanf("%d",&key);
	        insert(a,&count,key);
	    }
	    
	    printf("Displaying: \n");
	    display(a,n);
	}
	
	else
	{
	    printf("Enter size less than 14\n");
	}

	printf("\n");

	return 0;
}