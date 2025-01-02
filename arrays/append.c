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
	printf("Elements are: ");
	for(i=0;i<a1.length;i++)
	{
		printf("%d ",a1.a[i]);
	}
}

void append(struct arr *a1,int x) //we are going to the address to modify the array thats why pass by refernce is used
//array will not change using pass by value 
{
	if(a1->length < a1->size)
	{
		a1->a[a1->length++]=x;
	}

}

int main()
{
	struct arr a1;
	int n,i;
	printf("Enter size of the array: ");
	scanf("%d",&a1.size);
	a1.a=(int *)malloc(a1.size*sizeof(int)); // creating array in heap for c,malloc used for dynamic memory allocation
	a1.length=0;
	printf("Enter amount of number to be inserted in array: ");
	scanf("%d",&n);

	printf("Enter all the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a1.a[i]);
	}
	a1.length=n;

	int x;

	printf("Enter a number to append: ");
	scanf("%d",&x);

	append(&a1,x);
	display(a1);

	free(a1.a);

	return 0;
}