#include<stdio.h>
#include "queue.h"

void bfs(int G[][7], int start, int n)
{
	int i=start;
	int j;
	int visited[7]={0};

	printf("%d ",i);
	visited[i]=1;
	enqueue(i);

	while(!isEmpty())
	{
		i=dequeue();
		for(j=1;j<n;j++)
		{
			if(G[i][j] == 1 && visited[j] == 0)
			{
				printf("%d ",j);
				visited[j]=1;
				enqueue(j);
			}
		}
	}
}

int main()
{
	int G[7][7]={{0,0,0,0,0,0,0},
				 {0,0,1,1,0,0,0},
				 {0,1,0,0,1,0,0},
				 {0,1,0,0,1,0,0},
				 {0,0,1,1,0,1,1},
				 {0,0,0,0,1,0,0},
				 {0,0,0,0,1,0,0}};


	bfs(G,1,7);
	//we are doing bfsusing adjacency matrix g, we are starting our search from 
	//element 1 and there are 7 rows and columns in the matrix
	printf("\n");

	return 0;
}