/* SORTING OF LINKED LIST */

#include<stdio.h>
#include<stdlib.h>

void create();
void traverse();
void sort();

struct node
{
int info;
struct node *next;
}*start=NULL;

int main()
{
printf("\nCreate the list: \n");
create();
printf("\nOriginal list is: \n");
traverse();
sort();
printf("\nThe sorted list is: \n");
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
void sort()
{
	struct node *temp,*temp1,*temp2;
	for(temp=start;temp!=NULL;temp=temp->next)
	{
		for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
		{
			if(temp->info>temp1->info)
			{
				temp2->info=temp->info;
				temp->info=temp1->info;
				temp1->info=temp2->info;
			}
		}
	}
}