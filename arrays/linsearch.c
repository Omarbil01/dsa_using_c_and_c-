#include<stdio.h>
#include<stdlib.h>

struct arr
{
	int *a;
	int size;
	int length;
};

void display(struct arr a1)
{
	int i;
	for(i=0;i<a1.length;i++)
	{
		printf("%d ",a1.a[i]);
	}
	printf("\n ");
}

int linearsearch(struct arr a1,int key)
{
	int i;
	for(i=0;i<a1.length;i++)
	{
		if(key==a1.a[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	struct arr a1;
	int i,x;
	printf("Enter the size of the array: ");
	scanf("%d",&a1.size);
	a1.a=(int *)malloc(a1.size*sizeof(int));

	printf("Enter the length of the array: ");
	scanf("%d",&a1.length);
	if(a1.length>a1.size)
	{
		return -1;
	}

	printf("Enter the elements of the array: ");
	for(i=0;i<a1.length;i++)
	{
		scanf("%d",&a1.a[i]);
	}
	printf("\n");
	display(a1);
	printf("Enter the key to search: ");
	scanf("%d",&x);
	printf("%d \n",linearsearch(a1,x));

	free(a1.a);

	return 0;
}