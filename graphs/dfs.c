#include<stdio.h>
#include "queue.h"

void dfs(int G[][7], int start, int n)
{
	static int visited[7]={0};
	int j;

	if(visited[start]==0)
	{
		printf("%d ",start);
		visited[start]=1;
		for(j=1;j<n;j++)
		{
			if(G[start][j] == 1 && visited[j] == 0)
			{
				dfs(G,j,n);
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


	dfs(G,2,7);
	//we are doing dfs using adjacency matrix g, we are starting our search from 
	//element 1 and there are 7 rows and columns in the matrix
	printf("\n");

	return 0;
}