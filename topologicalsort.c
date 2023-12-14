//program to perfrom topological sort

#include<stdio.h>
#include<stdlib.h>

int n,adjacent[10][10],i,j,c,f,in,visit[10],temp;


int indegree(int v)
{
	f=0;
	for(c=1;c<=n;c++)
	{
		if(adjacent[c][v]==0 && visit[v]!=-1)
		{
			f++;
		}
	}
	if(f==temp)
		return 1;
	else
		return 0;
}


int main()
{
	printf("no of vertices :: ");

	//storing no of vertices
	scanf("%d",&n);
	temp=n;
	printf("\nenter adjacentacency matrix!\n");

	//storing the adjacent matrix
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&adjacent[i][j]);
		}
	}
	for(i=1;i<=n;i++)
		visit[i]=i;
	printf("\ntopological ordering is :\n\n");
	i=1;
	while(i<=n)
	{
		in=indegree(i);
		if(in==1 && visit[i]!=-1)
		{
			printf("%d-->",i);
			temp--;
			visit[i]=-1;
			for(j=1;j<=n;j++)
			{
				adjacent[i][j]=-1;
				adjacent[j][i]=-1;
			}
			i=1;
			continue;
		}
		i++;
	}
	return 0;
}
