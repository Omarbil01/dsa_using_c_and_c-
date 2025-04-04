#include<stdio.h>
#include "chain.h"

int hash(int key)
{
	return key%10;
}

void insert(struct node *H[],  int key)
{
	int index=hash(key);
	sortinsert(&H[index],key);

}

int main()
{
	struct node *HT[10];
	struct node *temp;
	int i;

	for(i=0;i<10;i++)
	{
		HT[i]=NULL;
	}

	insert(HT,12);
	insert(HT,32);

	temp=search(HT[hash(12)],12);

	if(temp != NULL)
	{
   		printf("%d\n ", temp->data);
    }
	else
	{
    	printf("Element not found\n");
    }
	return 0;	
}