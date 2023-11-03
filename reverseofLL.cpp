/* REVERSE OF LINKED LIST */

#include<stdio.h>
#include<stdlib.h>

void create();
void traverse();
void reverselist();

struct node
{
int info;
struct node *next;
}*start=NULL;
int  main()
{
printf("\nCreate the list: \n");
create();
printf("\nOriginal list: \n");
traverse();
reverselist();
printf("\nReversed list: \n");
traverse();
}
void create()
{
struct node *temp,*ptr;
int i,n;
printf("Number of Nodes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	temp=(struct node *)malloc(sizeof(struct node));
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
while(ptr!=NULL)
{
	printf("%d-->\t",ptr->info );
	ptr=ptr->next ;
}//end of while
}//end of traverse()
void reverselist()
{
    struct node *prevNode, *curNode;

    if(start != NULL)
    {
        prevNode = start;
        curNode = start->next;
        start = start->next;

        prevNode->next = NULL; // Make first node as last node

        while(start != NULL)
        {
            start = start->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = start;
        }

        start = prevNode; // Make last node as head
    }
}

