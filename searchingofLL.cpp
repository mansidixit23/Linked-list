/* SEARCHING LINKED LIST */

#include<stdio.h>
#include<stdlib.h>

void create();
void traverse();
void search(int key);

struct node
{
int info;
struct node *next;
}*start=NULL;
int  main()
{
int key;
printf("\nCreate the list: \n");
create();
printf("\nThe list is: \n");
traverse();
printf("\nEnter the data value to be searched:");
scanf("%d",&key);
search(key);
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
void search(int key)
{
int count=0,flag=0;
struct node *temp=start;
while (temp != NULL)
{
 	count++;
	if (temp->info == key)
	{
	 flag=1;break;	
	}
    temp = temp->next;
}
if(flag==1)
printf("Element %d found at location %d\n",key,count);
else
printf("Element not found\n");
}