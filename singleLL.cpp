/* SINGLE LINKED LIST BASIC OPERATIONS */
#include<stdio.h>
#include<stdlib.h>
//Defining structure of node
struct node
{
int info;
struct node *next;
};
struct node *start=NULL;
//Defining operations
void create()
{
struct node *temp,*ptr;
int i,n;
printf("Number of Nodes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)	//Required memory is not available
    {
		printf("\nList Overflow\n");
		exit(0);
    }
	printf("\nData value for the node %d :\t",i);
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(start==NULL)
	start=temp;
	else
    {
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
    }
}
}//end of create()
void traverse()
{
struct node *ptr=start;
//Check for empty
printf("\nThe List elements are:\n");
while(ptr!=NULL)
{
	printf("%d-->\t",ptr->info );
	ptr=ptr->next ;
}//end of while
}//end of traverse()
void insert_begin()
{
struct node *temp=(struct node *)malloc(sizeof(struct node));
//Check overflow
printf("\nData value for the node:\t" );
scanf("%d",&temp->info);
temp->next=NULL;
temp->next=start;
start=temp;
}//end of insert_begin()
void insert_end()
{
struct node *temp,*ptr;
temp=(struct node *)malloc(sizeof(struct node));
//Check overflow
printf("\nData value for the node :\t");
scanf("%d",&temp->info);
temp->next=NULL;
ptr=start;
while(ptr->next!=NULL)
	ptr=ptr->next;
ptr->next=temp;
}//end of insert_end
void insert_pos()
{
struct node *ptr,*temp;
int i,pos;
temp=(struct node *)malloc(sizeof(struct node));
//Check overflow
printf("\nPosition of the new node to be inserted : \t");
scanf("%d",&pos);
printf("\nData value of the node : \t");
scanf("%d",&temp->info);
temp->next=NULL;
for(i=1,ptr=start;i<pos;i++)
	ptr=ptr->next;
temp->next=ptr->next;
ptr->next=temp;
}//end of insert_pos
void delete_begin()
{
struct node *ptr;
if(start==NULL)
{
	printf("\nList Underflow.\n");
	exit(0);
}
ptr=start;
start=start->next;
printf("\nThe deleted element is : %d",ptr->info);
free(ptr);     
}//end of delete_begin()
void delete_end()
{
struct node *temp=start,*ptr=start->next;
//Check underflow
while(ptr->next!=NULL)
{
	temp=temp->next;
	ptr=ptr->next;
}
temp->next=NULL;
printf("\nThe deleted element is : %d",ptr->info);
free(ptr);
}//end of delete_end()
void delete_pos()
{
int i,pos;
struct node *temp=start,*ptr=start->next;
//Check underflow
printf("\nPosition of the node to be deleted :\t");
scanf("%d",&pos);
for(i=1;i<pos;i++)
{
	temp=temp->next;
	ptr=ptr->next;
}
temp->next =ptr->next ;
printf("\nThe deleted element is : %d",ptr->info );
free(ptr);
}//end of delete_pos()

int main()      //main() starts
{
int choice;
while(1)
{
printf("\n\n***SINGLE LINKED LIST BASIC OPERATIONS:****\n");
printf("\n                MENU                             \n");
printf("---------------------------------------\n");
printf("\n 1.Create\n");
printf("\n 2.Traverse\n");
printf("\n 3.Insert at the beginning\n");
printf("\n 4.Insert at the end\n");
printf("\n 5.Insert after a node\n");
printf("\n 6.Delete from beginning\n");
printf("\n 7.Delete from the end\n");
printf("\n 8.Delete after a node\n");
printf("\n 9.Exit\n");
printf("\n--------------------------------------\n");
printf("Enter your choice : \t");
scanf("%d",&choice);
switch(choice)
{
	case 1:{create();break;}
	case 2:{traverse();break;}
	case 3:{insert_begin();break;}
	case 4:{insert_end();break;}
	case 5:{insert_pos();break;}
	case 6:{delete_begin();	break;}
	case 7:{delete_end();break;}
	case 8:{delete_pos();break;}
	case 9:{exit(0);break;}
	default:
	printf("\n Invalid Choice\n");
}	//end of switch()
}
}//end of main()