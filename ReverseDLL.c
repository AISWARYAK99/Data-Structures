/* Double linked list reversing it
*/
#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
    struct Node *t,*last;//here the *first is local to this function so to reflect that in main we return the first
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
    
}
void display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void reverse()
{
    struct Node *p1,*p2;
	p1=first;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev; //next of p2 changed to prev 
	}
    first=p1;
//display(first);
}   
int main()
{
   //struct Node *first=NULL;
   int A[90]={12,20,30};
   create(A,3);
   display(first);
   reverse();
   display(first);
   return 0;
}
