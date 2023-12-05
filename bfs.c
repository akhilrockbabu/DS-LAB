#include<stdio.h>
#include<stdlib.h>
int q[10],visited[10],i,j,n,adj[20][20],v,front=1,rear=0,item;
void insert(int v);
int del();
void insert(int v)
{
	rear++;
	q[rear]=v;
}
int del()
{
	v=q[front];
	front++;
	return v;
}
int main()
{
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		visited[i]=0;
	}
	printf("enter the adjacency matrix:\n");
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			printf("adj[%d][%d]:",i,j);
			scanf("%d",&adj[i][j]);
			printf("\n");
		}
	}
	insert(1);
	printf("Spanning tree edges are:\n");
	for(i=1;i<=n;++i)
	{
		item=del();
		visited[item]=1;
		for(j=i+1;j<=n;j++)
		{
			if(adj[item][j]==1 && visited[j]==0)
			{
				insert(j);
				visited[j]=1;
				printf("edge(%d,%d)\n",item,j);
			}
		}
	}
	return 0;
}

/*enter the number of vertices
5
enter the adjacency matrix:
adj[1][1]:0
adj[1][2]:1
adj[1][3]:1
adj[1][4]:0
adj[1][5]:0
adj[2][1]:1
adj[2][2]:0
adj[2][3]:0
adj[2][4]:1
adj[2][5]:1
adj[3][1]:1
adj[3][2]:0
adj[3][3]:0
adj[3][4]:1
adj[3][5]:0
adj[4][1]:0
adj[4][2]:1
adj[4][3]:1
adj[4][4]:0
adj[4][5]:0
adj[5][1]:0
adj[5][2]:1
adj[5][3]:0
adj[5][4]:0
adj[5][5]:0
Spanning tree edges are:
edge(1,2)
edge(1,3)
edge(2,4)
edge(2,5)
*/
			
	
