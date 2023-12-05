#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int parent[MAX];
int v,i,j,cost[MAX][MAX],edgecount,count=1,mincost,c,rno,cno,v1,v2;
int find(int i)
{ 
	return parent[i]; 
} 
						  
int uni(int i,int j)
{
	if(i!=j)
	{  
		parent[j]=i; 
		return 1; 
	} 
	return 0; 
} 
	 
	 
int main(){  
	printf("Total no of v :: ");
	scanf("%d",&v);
	for(i=1;i<=v;i++)
		 parent[i]=i;
	//Get edge weight matrix from user	
	for(i=1;i<=v;i++)
	{
		for(j=i+1;j<=v;j++)
		{
			if(i!=j)
			{
				printf("enter the cost[%d][%d]||cost[%d][%d]:",i,j,j,i);
				scanf("%d",&cost[i][j]);
				cost[j][i]=cost[i][j];
				if(cost[i][j]==0)
					{
					   cost[i][j]=999;
					   cost[j][i]=999;
					}
			}
		}
	}
	
	edgecount = v-1;
	
	while(count <= edgecount)
	{
	c=999;
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=v;j++)
			{
				if(cost[i][j] < c)
				{
						c = cost[i][j];
						v1 = rno =  i;
						v2 = cno=  j;
				}
			}
		}   
		rno  = find(rno);  
		cno = find(cno);  
		if(uni(rno,cno))
		{  
			printf("\nEdge %d is (%d -> %d) with cost : %d ",count++,v1,v2,c);
			mincost = mincost + c;
		}
		cost[v1][v2] = cost[v2][v1] = 999;
	}    
	printf("\n Minimum cost=%d",mincost);  
	return 0;
} 
					  				  

