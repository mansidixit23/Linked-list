/* CONCATENATION OF TWO LINKED LIST */

#include<stdio.h>
#include<stdlib.h>

struct node * create(struct node *start);
void traverse(struct node *start);
void concat(struct node *start1, struct node *start2);

struct node
{
int info;
struct node *next;
}*start1=NULL,*start2=NULL;

int main()
{
printf("\nCreate first list: \n");
start1=create(start1);
printf("\nCreate second list: \n");
start2=create(start2);
printf("\nThe first list is: \n");
traverse(start1);
printf("\nThe first list is: \n");
traverse(start2);
concat(start1,start2);
printf("\nThe concatenated list is: \n");
traverse(start1);
}
struct node * create(struct node *start)
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
return start;
}//end of create()
void traverse(struct node *start)
{
struct node *ptr=start;
while(ptr!=NULL)
{
	printf("%d-->\t",ptr->info );
	ptr=ptr->next ;
}//end of while
}//end of traverse()
void concat(struct node *start1, struct node *start2)
{
	struct node *temp=start1;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=start2;
	//return start1;	
}