/**** LINKED LIST IMPLEMENTATION OF STACK ****/
#include <stdio.h>  
#include <stdlib.h>  
struct node   
{  
int info;  
struct node *next;  
}*top=NULL;  
void push ()  
{  
    struct node *temp = (struct node*)malloc(sizeof(struct node));    
    printf("Enter the value");  
    scanf("%d",&temp->info);  
    temp -> next = NULL;  
    if(top==NULL)            
        top=temp;  
    else   
    {  
        temp->next = top;  
        top=temp;  
    }  
    printf("Item pushed is %d",temp->info);           
}    
void pop()  
{  
    int item;  
    struct node *temp;  
    if (top == NULL)  
        printf("Stack Underflow");  
    else  
    {  
        temp = top; 
		printf("Item popped is %d",temp->info);   
        top = top->next;  
        free(temp);            
    }  
}  
void traverse()  
{  
    struct node *temp = top;     
    printf("Printing Stack elements \n");  
    while(temp!=NULL)  
    {  
        printf("%d\n",temp->info);  
        temp = temp->next;  
    }    
}  
  
int main ()  
{  
    int choice;     
    printf("\n*********Stack operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Traverse\n4.Exit");  
        printf("\n Enter your choice \t");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:{push();break;} 
            case 2:{pop();break;}  
            case 3:{traverse();break;}  
            case 4:{printf("Exiting....");break;}  
            default:printf("Please Enter valid choice ");
        }
    };  
}    