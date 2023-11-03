/* CIRCULAR LINKED LIST BASIC OPERATIONS */
#include<stdio.h>
#include<stdlib.h>
//Structure of a node
struct node
{
	int info;
	struct node *next;
};
struct node *start=NULL;

struct node * new_node()
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	return n;
}
//To define create function
void create()
{
	struct node *temp,*ptr;
	int i,n;
	printf("\nHow many nodes do you want to create : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=new_node();
		printf("\nEnter the data value of the node : ");
		scanf("%d",&temp->info);
		temp->next=temp;
		if(start==NULL)
		start=temp;
		else
		{
			ptr=start;
			while(ptr->next!=start)
				ptr=ptr->next;
			ptr->next=temp;
			temp->next=start;
		}//End of else
	}//End of for loop
}//End of create()
void insert_begin()
{
	struct node *temp=new_node(),*ptr=start;
	printf("\nEnter the data value of the node : ");
	scanf("%d",&temp->info);
	temp->next=temp;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=temp;
	temp->next=start;
	start=temp;		
}//End of insert_begin ()
void insert_end()
{
	struct node *temp=new_node(),*ptr=start;
	printf("\nEnter the data value of the node : ");
	scanf("%d",&temp->info);
	temp->next=temp;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=temp;
	temp->next=start;
}//End of insert_end()
void insert_pos()
{
	struct node *temp=new_node(),*ptr=start;
	int i,pos;
	printf("\Enter the position of the new node to be inserted : ");
	scanf("%d",&pos);
	printf("\nEnter the data value of the node : ");
	scanf("%d",&temp->info);
	temp->next=temp;
	for(i=1;i<pos;i++)
		ptr=ptr->next;
	temp->next=ptr->next;
	ptr->next=temp;
}//End of insert_pos()
void delete_begin()
{
	struct node *temp=start, *ptr=start;
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=start->next;
	start=start->next;
	printf("\nThe deleted elemnt is : %d\n",temp->info);
	free(temp);
}//End of delete_begin()
void delete_end()
{
	struct node *temp=start,*ptr=start->next;
	while(ptr->next!=start)
	{
		temp=temp->next;
		ptr=ptr->next;
	}
	temp->next=start;
	printf("\nDeleted eleemnt is : %d\n",ptr->info);
	free(ptr);
}//End of delete_end()
void delete_pos()
{
	int i,pos;
	struct node *temp=start,*ptr=start->next;
	printf("\nPosition of the node to be deleted :\t");
	scanf("%d",&pos);
	for(i=1;i<pos;i++)
	{
		temp=temp->next;
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	printf("\nThe deleted element is : %d",ptr->info);
	free(ptr);
}//End of delete_begin()
void traverse()
{
	struct node *ptr=start;
	while(ptr->next!=start)
	{
		printf("%d--->\t",ptr->info);
		ptr=ptr->next;
	}
	printf("%d",ptr->info);
}//End of traverse()

// Main program
int  main()
{
	int choice;
	while(1)
	{
		printf("\n***CIRCULAR LINKED LIST BASIC OPERATIONS*****\n");
		printf("\n                MENU              \n");
		printf("---------------------------------------\n");
		printf("\n1. Create\n");
		printf("\n2. Insert at the beginning\n");
		printf("\n3. Insert at the end\n");
		printf("\n4. Insert after a node\n");
		printf("\n5. Delete at begin\n");
		printf("\n6. Delete at end\n");
		printf("\n7. Delete after a node\n");
		printf("\n8. Traversal\n");
		printf("\n9. Exit\n");
		printf("\n-------------------------------------\n");
		printf("\nEnter your choice : \t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:{create();break;}
			case 2:{insert_begin();break;}
			case 3:{insert_end();break;}
			case 4:{insert_pos();break;}
			case 5:{delete_begin();	break;}
			case 6:{delete_end();break;}
			case 7:{delete_pos();break;}
			case 8:{traverse();break;}
			case 9:{exit(0);break;}
			default:
			printf("\n Invalid Choice\n");
		}	//end of switch()
	}
}//end of main()

