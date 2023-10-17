#include<stdio.h>
#include<stdlib.h>
int count=0;

struct node
{
	int data;
	struct node *next,*pre;
};
struct node *start=NULL;
struct node *end=NULL;

void create();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
void forward_display();
void backward_display();
int main()
{
	int choice;
	while(1)
	{
		printf("\n1.creation\n2.insertion at beginning \n3.insertion at end \n4.insertion at position \n5.deletion at 		beginning\n6.deletion at end \n7.deletion at position\n8.search for element \n9.forward display\n10.backward display 			\n11.exit \n");
		printf("\n enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: create();
			break;
			case 2:
			insert_begin();
			break;
			case 3:
			insert_end();
			break;
			case 4:
			insert_pos();
			break;
			case 5:
			delete_begin();
			break;
			case 6:
			delete_end();
			break;
			case 7:
			delete_pos();
			break;
			case 8:
			search();
			break;
			case 9:
			forward_display();
			break;
			case 10:
			backward_display();
			break;
			case 11:
			exit(0);
			default:
			printf("\n invalid choice");
		}
	}
}

void create()
{
	int n,item,i=0;
	struct node *temp,*ptr;
	if(count!=0)
		printf("list is already created\n");
	else
	{
		printf("enter the number of nodes\n");
		scanf("%d",&n);
		if(n==0)
			printf("creation not possible\n");
		else
		{
			while(i<n)
			{
				printf("enter the element to be inserted\n");
				scanf("%d",&item);
				ptr=(struct node*)malloc(sizeof(struct node));
				ptr->data=item;
				if(count==0)
				{
					start=ptr;
					end=ptr;
					start->next=NULL;
					start->pre=NULL;
					end->next=NULL;
					end->pre=NULL;
					count=1;
					++i;
					temp=start;
				}
				else
				{
					temp->next=ptr;
					ptr->pre=temp;
					ptr->next=NULL;
					end=ptr;
					++i;
					temp=temp->next;
				}
			}
			printf("LIST IS CREATED\n");
		}
	}
}

void forward_display()
{
	struct node *temp;
	if(start==NULL)
		printf("list is empty\n");
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}

void backward_display()
{
	struct node *temp;
	if(end==NULL)
		printf("list is empty\n");
	else
	{
		temp=end;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->pre;
		}
	}
}

void insert_begin()
{
	int item;
	struct node *ptr,*temp;
	printf("enter the item to insert\n");
	scanf("%d",&item);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=item;
	if(start==NULL)
	{
		start=ptr;
		start->next=NULL;
		start->pre=NULL;
		end=ptr;
		end->next=NULL;
		end->pre=NULL;
	}
	else
	{
		temp=start;
		start=ptr;
		ptr->next=temp;
		ptr->pre=NULL;
	}
	printf("item is inserted\n");
}
		
void insert_end()
{
	int item;
	struct node *ptr,*temp;
	printf("enter the item to insert\n");
	scanf("%d",&item);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=item;
	if(start==NULL)
	{
		start=ptr;
		end=ptr;
		start->next=NULL;
		start->pre=NULL;
		end->next=NULL;
		end->pre=NULL;
	}
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->pre=temp;
		end=ptr;
		end->next=NULL;
	}
	printf("item is inserted\n");
}

void insert_pos()
{
	int item,pos,i;
	struct node *temp,*ptr;
	printf("enter the position\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		insert_begin();
	}
	else
	{
		printf("enter the item to insert\n");
		scanf("%d",&item);
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=item;
		temp=start;
		for(i=1;i<pos-1;++i)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("insertion not possible\n");
				return;
			}
			
		}
		ptr->next=temp->next;
		temp->next=ptr;
		ptr->pre=temp;
		printf("inserted\n");
	}
}

void delete_begin()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		temp=start;
		start=temp->next;
		start->pre=NULL;
		free(temp);
	}
	printf("element is deleted\n");
}	
	
void delete_end()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		temp=end;
		end=temp->pre;
		end->next=NULL;
		free(temp);
	}
	printf("deleted\n");
}


void delete_pos()
{
	int pos,i;
	struct node *temp,*ptr;
	printf("enter the position\n");
	scanf("%d",&pos);
	if(start==NULL)
		printf("list is empty\n");
	else
	{
		if(pos==1)
			delete_begin();
		else
		{
			temp=start;
			for(i=1;i<pos-1;++i)
			{
				temp=temp->next;
				if(temp==NULL)
				{
					printf("deletion not possible\n");
					return;
				}
			}
			ptr=temp->next;
			temp->next=ptr->next;
			ptr->next->pre=temp;
			free(ptr);
			printf("node deleted\n");
		}
	}
}

void search()
{
	int item,count=1,flag=0;
	struct node *temp;
	if(start==NULL)
		printf("list is empty\n");
	else
	{
		printf("enter the item to search\n");
		scanf("%d",&item);
		temp=start;
		while(temp!=NULL)
		{
			if(temp->data==item)
			{
				printf("%d found at %d position\n",item,count);
				flag=1;
			}
			++count;
			temp=temp->next;
		}
		if(flag!=1)
		{
			printf("item not found!\n");
		}
	}
}

	
		
		
		
				
		
	
	
	

		
		
		
	

	

					
	

