#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *head=(struct node *)malloc(sizeof(struct node));
	struct node *first=(struct node *)malloc(sizeof(struct node));
	struct node *second=(struct node *)malloc(sizeof(struct node));

	head->data=5;
	head->next=first;

	first->data=11;
	first->next=second;

	second->data=16;
	second->next=NULL;

	struct node *temp=head;
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");

	free(head);
	free(first);
	free(second);

	return 0;
}
