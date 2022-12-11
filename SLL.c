//Code of Single linked list and its applications.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void create();
void display();
void insert_at_begin();
void insert_at_end();
void insert_at_position();
void delete_at_begin();
void delete_at_end();
void delete_at_position();
void count();
struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*new,*head,*temp,*d;
int i,pos,value,c;
void main()
{
	int ch;
	while(1)
	{
		printf("\n\nMENU\n1.create\n2.display\n3.insert at begin position\n4.insert at end\n5.insert at specified position\n6.Delete at begin\n7.Delete at end\n8.Delete at specified position\n9.count");
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();break;
			case 2:display();break;
			case 3:insert_at_begin();break;
			case 4:insert_at_end();break;
			case 5:insert_at_position();break;
			case 6:delete_at_begin();break;
			case 7:delete_at_end();break;
			case 8:delete_at_position();break;
			case 9:count();break;
			default:printf("\n Choose a valid option");
		}
	}
}
void create()
{
	char c;
	do
	{
		new =(struct Node *) malloc(sizeof(struct Node));
		printf("\n Enter a value");
		scanf("%d",&value);
		new->data=value;
		new->next=NULL;
		if(head==NULL)
		{
			head=temp=new;
		}
		else
		{
			temp->next=new;
			temp=new;
		}
		printf("\n Do you want to enter another value(y/n):");
		fflush(stdin);
		scanf("%c",&c);
	}while(c=='y');
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
    }
}
void insert_at_begin()
{
	int value;
	new=(struct Node *) malloc(sizeof(struct Node));
	printf("\n Enter data");
	scanf("%d",&value);
	new->data=value;
	new->next=head;
	head=new;
}
void insert_at_end()
{
	new=(struct Node *)malloc(sizeof(struct Node));
	printf("\n Enter data");
	scanf("%d",&value);
	new->data=value;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new;
	new->next=NULL;
	temp=new;
}
void insert_at_position()
{
	new=(struct Node *)malloc(sizeof(struct Node));
	printf("Enter position:");
	scanf("%d",&pos);
	printf("\n Enter a value");
	scanf("%d",&value);
	temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	new->data=value;
	new->next=temp->next;
	temp->next=new;
}
void delete_at_begin()
{
	temp=head;
	printf("Deleted node is %d",temp->data);
	head=head->next;
	temp->next=NULL;
	free(temp);
}
void delete_at_end()
{
	temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	d=temp->next;
	printf("Deleted node is %d",d->data);
	temp->next=NULL;
	free(d);
}
void delete_at_position()
{
	printf("Enter position:");
	scanf("%d",&pos);
	temp=head;
	if(pos==1)
	{
		delete_at_begin();
	}
	else
	{
		for(i=1;i<pos-1;i++)
     	{
	    	temp=temp->next;
    	}
    	d=temp->next;
	    printf("Deleted Node is %d",d->data);
    	temp->next=d->next;
    	d->next=NULL;
	    free(d);
	}	
}
void count()
{
	temp=head;
	c=0;
	while(temp!=NULL)
	{
		c+=1;
		temp=temp->next;
	}
	printf("Number of nodes=%d",c);
}


