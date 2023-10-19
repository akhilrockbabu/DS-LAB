#include<stdio.h>
int rear=-1,front=-1,max=5;
int a[5];
void insertion();
void deletion();
void display();
void search();
int main()
{
	int c;
	while(1)
	{
		printf("MENU\n_______\n1.insertion\n2.deletion\n3.display\n4.search\n5.exit\nenter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:insertion();
			break;
			case 2:deletion();
			break;
			case 3:display();
			break;
			case 4:search();
			break;
			case 5:return 0;
			defualt:printf("wrong choice\n");
		}
	}
}

void insertion()
{
	int item;
	if((rear+1)%max==front)
		printf("queue is full\n");
	else
	{
		printf("enter the item to insert\n");
		scanf("%d",&item);
		if(rear==-1&&front==-1)
		{
			rear=0;
			front=0;
		}
		else
		{
			rear=(rear+1)%max;
		}
		a[rear]=item;
		printf("%d inserted\n",item);
	}
}

void deletion()
{
	int item;
	if(front==-1)
		printf("queue is empty\n");
	else
	{
		if(front==rear)
		{
			item=a[front];
			rear=-1;
			front=-1;
		}
		else
		{
			item=a[front];
			front=(front+1)%max;
		}
		printf("%d is deleted\n",item);
	}
		
}

void display()
{
	int i;
	if(front==-1)
		printf("queue is empty\n");
	else
	{
		printf("THE LIST IS:\n");
		if(front==0)
		{
			for(i=front;i<=rear;++i)
			{
				printf("%d\n",a[i]);
			}
			for(i=rear;i<max-1;++i)
			{
				printf("-\n");
			}
		}
		if(front>rear)
		{
			for(i=0;i<=rear;++i)
			{
				printf("%d\n",a[i]);
			}
			for(i=rear+1;i<front;++i)
			{
				printf("-\n");
			}
			for(i=front;i<max;++i)
			{
				printf("%d\n",a[i]);
			}
		}
		if(front<rear&&front!=0)
		{
			for(i=0;i<front;++i)
			{
				printf("-\n");
			}
			for(i=front;i<=rear;++i)
			{
				printf("%d\n",a[i]);
			}
			for(i=rear+1;i<max;++i)
			{
				printf("-\n");
			}
		}
	}
}

void search()
{
	int item,loc=-1,i;
	if(front==-1)
		printf("queue is empty\n");
	else
	{
		printf("enter the item to search\n");
		scanf("%d",&item);
		if(front==0)
		{
			for(i=front;i<=rear;++i)
			{
				if(item==a[i])
				{
					loc=i;
					break;
				}
			}
		}
		if(front>rear)
		{
			for(i=0;i<=rear;++i)
			{
				if(item==a[i])
				{
					loc=i;
					break;
				}
			}
			for(i=front;i<max;++i)
			{
				if(item==a[i])
				{
					loc=i;
					break;
				}
			}
		}
		if(front<rear&&front!=0)
		{
			for(i=front;i<=rear;++i)
			{
				if(item==a[i])
				{
					loc=i;
					break;
				}
			}
			
		}
		if(loc==-1)
			printf("%d not found\n",item);
		else
			printf("%d found at position %d\n",item,loc+1);
	}
	
}
		
		
		
				

			
