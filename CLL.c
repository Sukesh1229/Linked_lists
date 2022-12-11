//Creation and display and Insertion of  Circular linked list.
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
		printf("\n\nMENU\n1.create\n2.display\n3.insert at begin position\n4.insert at end\n5.insert at specified position\n6.Delete at begin\n7.Delete at end\n8.Delete at specified position\n8.count");
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
		new->next=new;
		if(head==NULL)
		{
			head=temp=new;
		}
		else
		{
			temp->next=new;
			temp=new;
			new->next=head;
		}
		printf("\n Do you want to enter another value(y/n):");
		fflush(stdin);
		scanf("%c",&c);
	}while(c=='y');
}
void display()
{
	temp=head;
	while(temp->next!=head)
	{
		printf("%d->",temp->data);
		temp=temp->next;
    }
    printf("%d->",temp->data);
}
void insert_at_begin()
{
	int value;
	new=(struct Node *) malloc(sizeof(struct Node));
	printf("\n Enter data");
	scanf("%d",&value);
	new->data=value;
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=new;
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
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=new;
	new->next=head;
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
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	d=head;
	printf("Deleted node is %d",head->data);
	head=head->next;
	temp->next=head;
	d->next=NULL;
	free(d);
}
void delete_at_end()
{
	temp=head;
	while(temp->next->next!=head)
	{
		temp=temp->next;
	}
	d=temp->next;
	temp->next=head;
	printf("Deleted node is %d",d->data);
	d->next=NULL;
	free(d);
}
void delete_at_position()
{
	temp=head;
	printf("Enter position:");
	scanf("%d",&pos);
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
	    temp->next=d->next;
	    printf("Deleted Node is %d",d->data);
	    d->next=NULL;
	    free(d);
	}	
}
void count()
{
	temp=head;
	c=0;
	while(temp->next!=head)
	{
		c+=1;
		temp=temp->next;
	}
	printf("Number of nodes=%d",c+1);
}

