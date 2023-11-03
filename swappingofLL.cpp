/* Swapping OF LINKED LIST */
#include<stdio.h>
#include<stdlib.h>
void create();
void traverse();
void node_swap(int loc);
struct node
{
int info;
struct node *next;
}*start=NULL;
int main()
{
int loc;
printf("\nCreate the list: \n");
create();
printf("\nTraverse the list: \n");
traverse();
printf("\nEnter location of node to swap:  ");
scanf("%d",&loc);
node_swap(loc);
printf("\nAfter swapping the list is: \n");
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
void node_swap(int loc)
{
	struct node *p=start, *q=start, *r=start;
	int i;
	for(i=1;i<loc-1;i++)
		p=p->next;
	for(i=1;i<loc;i++)
		q=q->next;
	for(i=1;i<loc+1;i++)
		r=r->next;
	q->next=r->next;
	r->next=q;
	p->next=r;	
}