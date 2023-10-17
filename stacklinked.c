#include<stdio.h>
#include<stdlib.h>
int count=0;

struct node
{
int data;
struct node*next;
};
struct node*start;

void create();
void push();
void pop();
void search();
void display();

int main()
{
int choice;
while(1)
{
printf("\n1.creation\n2.push \n3.pop \n4.search \n5.display\n6.exit \n");
printf("\n enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
create();
break;
case 2:
push();
break;
case 3:
pop();
break;
case 4:
search();
break;
case 5:
display();
break;
case 6:
exit(0);
default:
printf("\n invalid choice");
}
}
}

void create()
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
if(count==0)
{
start =ptr;
start ->next=NULL;
count=1;
i++;
temp=start;
}
else
{
temp->next=ptr;

temp=temp->next;
i++;
}
}
}
}
else
printf("\nlist already created\n");
}

void push()
{
struct node*ptr,*temp;
int item;
ptr=(struct node*)malloc(sizeof(struct node*));
printf("\n enter value : ");
scanf("%d",&item);
ptr->data=item;
if(start==NULL)
{
ptr->next=NULL;
start=ptr;
printf("\n node inserted successfully ");
}
else
{
temp=start;
while(temp->next!=NULL)

{
temp=temp->next;
}
temp->next=ptr;
ptr->next=NULL;
printf("\n node inserted ");
}
}

void pop()
{
struct node*ptr,*temp;
if(start==NULL)
{
printf("\n list is empty");
}
else if(start->next==NULL)
{
start=NULL;
free(start);
printf("\n node deleted");
}
else
{
temp=start;
while(temp->next->next!=NULL)
{
temp=temp->next;
}
ptr=temp->next;
temp->next=NULL;
free(ptr);
printf("\n node deleted ");
}
}

void search()
{
struct node*ptr;
int item,count,i=0;
ptr=start;
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


void display()
{
int i=0,n=0,a[50];
struct node*temp;
temp=start;
if(temp==NULL)
printf("\n list is empty");
else
{
//printf("\n list : ");
while(temp!=NULL)
{
a[i]=temp->data;
++i;
++n;
temp=temp->next;
}
for(i=n-1;i>=0;--i)
{
printf("%d\n",a[i]);
}
}
}
