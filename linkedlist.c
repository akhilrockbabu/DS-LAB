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
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
void display();
int main()
{
int choice;
while(1)
{
printf("\n1.creation\n2.insert beginning \n3.insert end \n4.insert position \n5.delete beginning
\n6.delete end \n7.delete position \n8.search \n9.display \n10.exit \n");
printf("\n enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
create();
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
display();
break;
case 10:
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
void insert_begin()
{
int data;
node *ptr;
printf("\nEnter value to insert : ");
scanf("%d",&data);
ptr=(node*)malloc(sizeof(node));
ptr->data=data;
if(start == NULL)
{
start =ptr;
start ->next=NULL;
}
else{
ptr->next=start ;
start =ptr;
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
temp=start;
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
temp->next=ptr;
printf("\n node inserted \n");
}
void delete_begin()
{
struct node*temp;
if(start==NULL)
{
printf("\n list is empty");
}
else
{
temp=start;
start=temp->next;
free(temp);
printf("\n node deleted");
}
}

void delete_end()
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
void delete_pos()
{
struct node*ptr,*temp;
int pos,i;
printf("\n enter position ");
scanf("%d",&pos);
temp=start;
if(temp==NULL)
{
printf("\n deletion not possible ");
return;
}
else if(pos==1)
{
start=temp->next;
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
temp->next=ptr->next;
free(ptr);
printf("\n node deleted ");
}}
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
struct node*ptr;
ptr=start;
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
