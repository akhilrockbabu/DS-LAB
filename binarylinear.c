#include<stdio.h>
void binary();
void linear();
void read();
int a[25],n;
int main()
{
	int c;
	printf("enter the no of elements\n");
	scanf("%d",&n);
	while(1)
	{
		printf("MENU\n--------\n1.Linear Search\n2.Binary Search\n3.Exit\nEnter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:linear();
			break;
			case 2:binary();
			break;
			case 3:return 0;
			deafult:printf("wrong choice\n");
		}
	}
}

void read()
{
	int i;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
}

void linear()
{
	int i,item,loc=-1;
	printf("enter %d elements in array\n",n);
	read();
	printf("THE ARRAY YOU ENTERED\n");
	for(i=1;i<=n;++i)
		printf("%d\n",a[i]);
	printf("enter the item to search\n");
	scanf("%d",&item);
	for(i=1;i<=n;++i)
	{
		if(a[i]==item)
		{
			loc=i;
			break;
		}
	}
	if(loc==-1)
		printf("%d is not found\n",item);
	else
		printf("%d found at position %d\n",item,loc);
}

void binary()
{
	int low=0,high=n,mid,item,flag=0,i;
	printf("enter %d elements in sorted order\n",n);
	read();
	printf("THE ARRAY YOU ENTERED\n");
	for(i=1;i<=n;++i)
		printf("%d\n",a[i]);
	printf("enter the item to search\n");
	scanf("%d",&item);
	while(low<=high)
	{
		mid=(low+high)/2;
		if(item==a[mid])
		{
			flag=1;
			printf("%d is found at %d position\n",item,mid);
			return;
		}
		else if(item>a[mid])
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	if(flag==0)
	{
		printf("%d is not found\n",item);
	}
}
