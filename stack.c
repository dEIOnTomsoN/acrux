#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*link;
}*header=NULL,*top;
void push()
{
int data;
struct node *newnode;
printf("Enter the data.\n");
scanf("%d",&data);
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->link=header->link;
header->link=newnode;
top=newnode;
}
void pop()
{
struct node*ptr;
if(header->link==NULL)
{
printf("Stack empty\n");
return;
}
else
{
ptr=top->link;
header->link=ptr;
printf("%d deleted\n",top->data);
top=ptr;
}
}
void display()
{
struct node*ptr;
if(header->link==NULL)
{
printf("Stack empty\n");
return;
}
else
{
ptr=header;
while(ptr->link!=NULL)
{
ptr=ptr->link;
printf("%d\t",ptr->data);
}
printf("\n");
}
}
int main()
{
int choice;
header=(struct node*)malloc(sizeof(struct node));
header->link=NULL;
do
{
printf("Enter your choice\n");
printf("1-push\n2-pop\n3-display\n4-exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
display();
break;
case 2:
pop();
display();
break;
case 3:
display();
break;
case 4:
printf("EXITING..\n");
break;
default:
printf("Invalid..\n");
}
}while(choice!=4);
}

