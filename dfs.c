#include<stdio.h>
#include<stdlib.h>
int s[10],visited[10],i,j,n,adj[20][20],v,top=0,item;
void push(int v);
int pop();
void push(int v)
{
	top++;
	s[top]=v;
}
int pop()
{
	v=s[top];
	top--;
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
	push(1);
	printf("Spanning tree edges are:\n");
	for(i=1;i<=n;++i)
	{
		item=pop();
		printf("%d-->",item);
		visited[item]=1;
		for(j=i+1;j<=n;j++)
		{
			if(adj[item][j]==1 && visited[j]==0)
			{
				push(j);
				visited[j]=1;
			}
		}
	}
	return 0;
}

				
	
