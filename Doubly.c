#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node
{
	  int data;
	  struct node *prev;
	  struct node *next;
};
struct node *beg= NULL, *end=NULL;
void creation();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
void fdisplay();
void bdisplay();

int main()
{
	int choice;
	while(1)
	{
		printf("\n1.creation\n2.insert beginning \n3.insert end \n4.insert position \n5.delete beginning \n6.delete end \n7.delete position \n8.search \n9.forward display \n10.backward 		display\n11.exit \n");
		printf("\n enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			creation();
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
			fdisplay();
			break;
			case 10:
			bdisplay();
			break;
			case 11:
			exit(0);

			default:
			printf("\n invalid choice");
		}
	}
}
void creation()
{
	int n,item,i=0,f=0;
	node *ptr,*temp;
	if(count==0)
	{
		printf("\nEnter the no of nodes to be inserted");
		scanf("%d",&n);
		if(n==0)
		{
			printf("\nno creation");
		}
		else
		{
			while(i<n)
			{
				printf("\nEnter value to insert : ");
				scanf("%d",&item);
				ptr=(node*)malloc(sizeof(node));
			 	ptr->data=item;
			 	ptr->next=NULL;
			 	if(count==0)
			 	{
				 	beg =ptr;
					beg ->prev=NULL;
					beg->next=NULL;
					end=ptr;
					end->prev=NULL;
					end->next=NULL;
					count=1;
					i++;
					temp=beg;
			 	}
			 	else
			 	{
			 		temp->next=ptr;
			 		ptr->prev=temp;
			 		ptr->next=NULL;
			 		end=ptr;
			 		temp=temp->next;
			 		i++;
			 	}
			}
			printf("\nlist is created\n");
		}
	}
	else
	printf("\nlist already created\n");
}
void insert_begin()
{
	int data;
		node *ptr;
		
		printf("\nEnter value to insert : ");
		scanf("%d",&data);
		
		ptr=(node*)malloc(sizeof(node));
		ptr->data=data;
			
		if(beg  == NULL)
		{
				beg=ptr;
				beg ->next=NULL;
				beg->prev=NULL;
		}
		else
		{
				ptr->prev=NULL;
				ptr->next=beg ;
				beg->prev=ptr;
				beg=ptr;
		}
}
void insert_end()
{
	struct node*ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	printf("\n enter value : ");
	scanf("%d",&item);
	ptr->data=item;
	if(end==NULL)
	{
		ptr->next=NULL;
		beg=ptr;
		end=ptr;
		printf("\n node inserted successfully ");
	}
	else
	{
		temp=end;
		ptr->prev=temp;
		ptr->next=NULL;
		temp->next=ptr;
		end=ptr;
		printf("\n node inserted ");
	}
}
void insert_pos()
{
	int item;
	int pos,i;
	struct node*ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node*));
	printf("\n enter value : ");
	scanf("%d",&item);
	ptr->data=item;
	printf("\n enter position : ");
	scanf("%d",&pos);
	temp=beg;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("\n insertion not possible");
			return;
		}
	}
	ptr->next=temp->next;
	ptr->prev=temp;
	temp->next->prev=ptr;
	temp->next=ptr;
	printf("\n node inserted \n");
}
void delete_begin()
{
	struct node*temp;
	if(beg==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp=beg;
		beg=temp->next;
		beg->prev=NULL;
		free(temp);
		printf("\n node deleted");
	}
}
void delete_end()
{
	struct node*ptr,*temp;
	if(end==NULL)
	{
		printf("\n list is empty");
	}
	else if(end->prev==NULL)
	{
		end=NULL;
		beg=NULL;
		free(beg);
		printf("\n node deleted");
	}
	else
	{
		temp=end;
		end=temp->prev;
		end->next=NULL;
		free(temp);
		printf("\n node deleted ");
	}
}
void delete_pos()
{
	struct node*ptr,*temp;
	int pos,i;
	printf("\n enter position ");
	scanf("%d",&pos);
	temp=beg;
	if(temp==NULL)
	{
		printf("\n deletion not possible ");
		return;
	}
	else if(pos==1)
	{
		beg=temp->next;
		beg->prev=NULL;
		free(temp);
		printf("\n node deleted");
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("\n deletion not possible ");
				return;
			}
		}
	ptr=temp->next;
    ptr->next->prev=temp;
	temp->next=ptr->next;
	free(ptr);
	printf("\n node deleted ");
	}
}
void fdisplay()
{
	 	node*ptr;
		ptr=beg;
		if(ptr==NULL)
		printf("\n list is empty");
		else
		{
			printf("\n list : ");
			while(ptr!=NULL)
			{
				printf("\n %d",ptr->data);
				ptr=ptr->next;
			}
		}
}
void search()
{
struct node*ptr;
int item,count,i=0;
ptr=beg;
if(ptr==NULL)
{
printf("\n empty list");
}
else
{
printf("\n enter element to be searched ");
scanf("%d",&item);
while(ptr!=NULL)
{
if(ptr->data==item)
{
printf("\n %d found at position %d ",ptr->data,i+1);
count=1;
break;
}
ptr=ptr->next;
i++;
}
if(count==0)
{
printf("\n element not found");
}
}
}
void bdisplay()
{
	 	node*ptr;
		ptr=end;
		if(ptr==NULL)
		printf("\n list is empty");
		else
		{
			printf("\n list : ");
			while(ptr!=NULL)
			{
				printf("\n %d",ptr->data);
				ptr=ptr->prev;
			}
		}
}
