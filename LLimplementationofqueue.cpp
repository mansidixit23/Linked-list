/**** LINKED LIST IMPLEMENTATION OF QUEUE ****/
#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
}*front=NULL,*rear=NULL;   
void enqueue()  
{  
    struct node *ptr;        
    ptr = (struct node *) malloc (sizeof(struct node));     
    printf("\nEnter value=");  
    scanf("%d",&ptr->data);  
    ptr -> next = NULL;  
    if(front == NULL && rear==NULL)  
        front = rear = ptr;  
    else   
    {  
        rear -> next = ptr;  
        rear = ptr;  
    }    
}     
void dequeue()  
{  
    struct node *ptr=front;  
    if(front == NULL && rear==NULL)   
        printf("\nQueue Underflow\n");    
    else  if(front==rear)
		front=rear=NULL;
	else   
		front = front -> next;  
    printf("\nDeleted element is %d",ptr->data);
    free(ptr);  
}  
void traversal()  
{  
    struct node *ptr = front;      
	printf("\nQueue elements are : \n");  
    while(ptr != NULL)   
    {  
        printf("%d\t",ptr -> data);  
        ptr = ptr -> next;  
    }    
}   
int main ()  
{  
    int choice;   
    while(choice != 4)   
    {     
        printf("\n*************************Main Menu*****************************\n");  
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the Queue\n4.Exit\n");
        printf("\nEnter your choice =");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:enqueue();break;  
            case 2:dequeue();break;  
            case 3:traversal();break;  
            case 4:exit(0);break;  
            default:printf("\nEnter valid choice??\n");  
        }  
    }  
}  