/* SIZE OF LINKED LIST */

#include<stdio.h>
#include<stdlib.h>

void create();
int length();

struct node
{
int info;
struct node *next;
}*start=NULL;
int main()
{
printf("\nCreate the list: \n");
create();
printf("\nSize of the list is: %d ", length());
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
int length()
{
	int count=0;
	struct node *temp=start;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}