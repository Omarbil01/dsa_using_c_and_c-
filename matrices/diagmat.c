#include<stdio.h>

int main()
{
	int matrix[5][5];
	int i,j;

	printf("Enter diagonal matrix element: ");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i == j)
			{
				scanf("%i",&matrix[i][j]);
			}
			else
			{
				matrix[i][j]=0;
			}

		}
	}

	printf("Diagonal elements: ");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i == j)
			{
				printf("%i ",matrix[i][j]);
			}

		}
	}
	printf("\n");

	printf("Whole matrix: \n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%i ",matrix[i][j]);

		}
		printf("\n");
	}

	return 0;
}