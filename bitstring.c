#include<stdio.h>
#include<stdlib.h>
int u[10]={9,5,11,56,72,34,65,33,90,99};
void display(int *array);
int main()
{
	int universal[10]={1,1,1,1,1,1,1,1,1,1};
	int a[10]={1,0,1,0,1,0,1,0,1,0};
	int b[10]={1,0,0,1,1,0,0,1,0,1};
	int aUb[10],anb[10],a_differ_b[10],b_differ_a[10];
	//aUb for union array
	//anb for intersection array
	//a_differ_b for a difference b
	//b_differ_a for b difference a
	int i;
	printf("THE UNIVERSAL SET IS :\n");
	display(universal);
	printf("\n");
	printf("THE A SET IS :\n");
	display(a);
	printf("THE B SET IS :\n");
	display(b);
	printf("THE A union B SET IS :\n");
	for(i=0;i<10;++i)
	{
		aUb[i]=a[i]||b[i];
	}
	display(aUb);
	printf("THE A intersection B SET IS :\n");
	for(i=0;i<10;++i)
	{
		anb[i]=a[i]&&b[i];
	}
	display(anb);
	printf("THE A-B SET IS :\n");
	for(i=0;i<10;++i)
	{
		if(a[i]==1)
		{
			a_differ_b[i]=a[i]-b[i];
		}
		else
		{
			a_differ_b[i]=0;
		}
	}
	display(a_differ_b);
	printf("THE B-A SET IS :\n");
	for(i=0;i<10;++i)
	{
		if(b[i]==1)
		{
			b_differ_a[i]=b[i]-a[i];
		}
		else
		{
			a_differ_b[i]=0;
		}
	}
	display(b_differ_a);
}

void display(int *array)
{
	int *temparray=array;
	int i;
	for(i=0;i<10;++i)
	{
		if(*temparray==1)
		{
			printf("%d, ",u[i]);	
		}
		++temparray;
		
	}
	printf("\n\n");
}
