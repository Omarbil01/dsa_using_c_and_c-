#include<stdio.h>
#define SIZE 10

int hash(int key)
{
	return key%SIZE;
}

int probe(int h[],int key)
{
	int index=hash(key);
	int i=0;

	while(h[(index +i*i) % SIZE] != 0)
	{
		i++;
	}

	return (index + i*i)%SIZE;
}

void insert(int h[],int key)
{
	int index=hash(key);

	if(h[index] != 0)
	{
		index=probe(h,key);
	}

	h[index]=key;

}

int search(int h[],int key)
{
	int index=hash(key);
	int i=0;
	
	while(h[(index+i*i)%SIZE] != key)
	{
		i++;
	}

	return(index + i*i)%SIZE;
}

int main()
{
	int h[10]={0};

	insert(h,23);
	insert(h,43);
	insert(h,13);
	insert(h,27);

	int x=search(h,13);

	printf("Key found at index %d ",x);
	printf("\n");

	return 0;
}