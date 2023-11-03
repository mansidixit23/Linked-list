/* DOUBLY LINKED LIST OPERATIONS */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next,*pre;
}*start=NULL;

struct node * new_node()
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	return n;
}

void create()
{
  struct node *temp, *ptr;
  int i,n;
  printf("\nHow many nodes do you want to create : ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  	temp = new_node();
  	printf("Enter the data value of the node:\t");
  	scanf("%d",&temp->info);
  	temp -> next = NULL;
  	temp -> pre = NULL;
  	if(start == NULL)
  		start = temp;
  	else
  	{ 
  		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next = temp;
		temp->pre = ptr;
 	}//end of else
  }//End of for
}//end of create()
void insert_begin()
{
struct node *temp;
temp=new_node();
printf("\nEnter the data value for the node:\t" );
scanf("%d",&temp->info);
temp->next =NULL;
temp->pre =NULL;
start->pre=temp;
temp->next=start;
start=temp;
}//end of insert_begin()
void insert_end()
{
struct node *temp,*ptr=start;
temp=new_node();
printf("\nEnter the data value for the node:\t" );
scanf("%d",&temp->info );
temp->next =NULL;
temp->pre =NULL;
while(ptr->next!=NULL)
	ptr=ptr->next;
ptr->next = temp;
temp->pre = ptr;
}//end of insert_end
void insert_pos()
{
struct node *temp,*p1=start,*p2=start->next;
int i,pos;
temp=new_node();
printf("\nEnter the position for the new node to be inserted:\t");
scanf("%d",&pos);
printf("\nEnter the data value of the node:\t");
scanf("%d",&temp->info) ;
temp->next=NULL;
temp->pre=NULL;
for(i=1;i<pos;i++)
{
	p1=p1->next;
	p2=p2->next;
}
p1->next=temp;
p2->pre=temp;
temp->pre=p1;
temp->next=p2;
}//end of insert_pos
void delete_begin()
{
struct node *ptr=start;
start=start->next ;
start->pre=NULL;
printf("\nThe deleted element is :%d\t",ptr->info);
free(ptr);
}//end of delete_begin()
void delete_end()
{
struct node *p1=start,*p2=start->next;
while(p2->next!=NULL)
{
	p1=p1->next;
	p2=p2->next;
}	
p1->next=NULL;
printf("\nThe deleted element is :%d\t",p2->info);
free(p2);
}//end of delete_end()
void delete_pos()
{
int i,pos;
struct node *p1=start,*p2=start,*p3=start;
printf("\nEnter the position of the node to be deleted:\t");
scanf("%d",&pos);
for(i=1;i<pos;i++)
	p1=p1->next;
for(i=1;i<=pos;i++)
   	p2=p2->next;
for(i=1;i<=pos+1;i++)
   	p3=p3->next;
p1->next=p3;
p3->pre=p1;
printf("\nThe deleted element is:%d\t",p2->info );
free(p2);
}//end of delete_pos()
void traverse()
{
struct node *ptr=start;
while(ptr!=NULL)
{
	printf("%d\t",ptr->info );
	ptr=ptr->next ;
}//end of while
}//end of traverse
int main()      //main() starts
{
	int choice;
	while(1)
	{
		printf("\n***DOUBLY LINKED LIST BASIC OPERATIONS*****\n");
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
			printf("\n Invalid Choice\n");}}}	//end of switch()}}//end of main()