#include <stdio.h>
#include <limits.h>
#include<stdint.h>
#define I INT32_MAX

int edges[3][9]={{1,1,2,2,3,4,4,5,5},
				 {2,6,3,7,4,5,7,6,7},
				 {25,5,12,10,8,16,14,20,18}};


int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};

int included[9]={0};

int t[2][6];

void kunion(int u,int v)
{
	if(set[u]<set[v])
	{
		set[u] += set[v];
		set[v] = u;
	}

	else
	{
		set[v] += set[u];
		set[u] = v;
	}
}


int find(int u)
{
	int x=u;
	int v=0;

	while(set[x] > 0)
	{
		x=set[x];
	}

	while(u != x)
	{
		v=set[u];
		set[u]=x;
		u=v;
	}

	return x;
}

int main()
{
	int i=0;
	int j,k,u,v;
	int min=I;
	int vertice=7;
	int e=9;

	while(i<vertice-1)
	{
		min=I;
		for(j=0;j<e;j++)
		{
			if(included[j] == 0 && edges[2][j]<min)
			{
				min=edges[2][j];
				u=edges[0][j];
				v=edges[1][j];

				k=j;

			}
		}

		//check for cycle

		if(find(u) != find(v))
		{
			t[0][i]=u;
			t[1][i]=v;

			kunion(find(u),find(v));
			i++;
		}

		included[k]=1;
	}

	printf("Minimum cost edges that travel to all edges are: \n");
	for(i=0;i<vertice-1;i++)
	{
		printf("( %d, %d )",t[0][i],t[1][i]);
	}
	printf("\n");
}