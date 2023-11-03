/**** POLYNOMIAL REPRESENTATION AND ADDITION ****/
#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int coef,exp;
	struct poly *next;
}*start1=NULL,*start2=NULL;

struct poly *createPolynomial(struct poly *start)
{
	struct poly *temp,*ptr;
	char ch;
	do
	{
		temp=(struct poly *)malloc(sizeof(struct poly));
		printf("\nEnter the coefficient value: ");
        scanf("%d",&temp->coef);
        printf("\nEnter the exponential value: ");
        scanf("%d",&temp->exp);
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
		printf("\nDo you want to create another term in the polynomial (y/n): ");
        getchar();
        scanf("%c",&ch);
	}while(ch!='n');
	return start;
}

void displayPolynomial(struct poly *start)
{
	struct poly *ptr=start;
		while(ptr!=NULL)
		{
			printf("%dx^%d",ptr->coef,ptr->exp);
			ptr=ptr->next;
			if(ptr!=NULL)
			printf("+");
		}
}

void add_poly(struct poly *start1, struct poly *start2)
{
	struct poly *p1=start1,*p2=start2;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->exp>p2->exp)
		{
			printf("%dx^%d",p1->coef,p1->exp);
			p1=p1->next;
		}
		else if(p1->exp<p2->exp)
		{
			printf("%dx^%d",p2->coef,p2->exp);
			p2=p2->next;
		}
		else
		{
			printf("%dx^%d",p1->coef+p2->coef,p1->exp);
			p1=p1->next;p2=p2->next;
		}
		if(p1!=NULL || p2!=NULL)
		printf("+");
	}
	while(p1!=NULL)
	{
		printf("%dx^%d",p1->coef,p1->exp);	
		p1=p1->next;
		if(p1!=NULL)
		printf("+");
	}
	while(p2!=NULL)
	{
		printf("%dx^%d",p2->coef,p2->exp);	
		p2=p2->next;
		if(p2!=NULL)
		printf("+");
	}
}

int main()
{
    struct poly *p1,*p2;
    int ch;
    do
    {
    printf("\n****** POLYNOMIAL *******"
			"\n1.ENTER FIRST POLYNOMIAL"
			"\n2.DISPLAY FIRST POLYNOMIAL"    
    		"\n3.ENTER THE SECOND POLYNOMIAL"
    		"\n4.DISPLAY SECOND POLYNOMIAL"
			"\n5.ADD POLYNOMIALS"
			"\n6.Exit");
    printf("\nEnter your choice=");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1: p1=createPolynomial(start1); break;
    	case 2: displayPolynomial(p1); break;
    	case 3: p2=createPolynomial(start2); break;
    	case 4: displayPolynomial(p2); break;
    	case 5: printf("\nPolynomial Addition Result=");add_poly(p1,p2); break;
    	case 6: printf("Exit");break;
    	default: printf("\nInvalid choice"); break;
	}
	}while(ch!=6);
}