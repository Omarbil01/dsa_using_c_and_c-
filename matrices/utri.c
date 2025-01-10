#include<stdio.h>

int main()
{
	int matrix[5][5];
	int i,j;

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i<=j)
			{
				printf("Enter index %i,%i: ",(i+1),(j+1));
				scanf("%d",&matrix[i][j]);
			}
			else
			{
				matrix[i][j]=0;
			}
		}
	}

	printf("Upper triangular matrix: ");
	printf("\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%i ",matrix[i][j]);
		}
		printf("\n");
	}

	printf("Upper traingular elements: ");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i<=j)
			{
				printf("%i ",matrix[i][j]);
			}
		}
	}
	printf("\n");
	return 0;
}