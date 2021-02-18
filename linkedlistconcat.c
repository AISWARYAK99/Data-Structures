/* concatenation of two linked list*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first,*second=NULL;

void create1(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(int B[],int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=B[0];
    last=second;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
void concat(struct Node *first,struct Node *second)
{
    struct Node *p=first;
    while(p->next!=NULL)
    {
       p=p->next; 
    }
    p->next=second;
    second=NULL;
}
int main()
{
    int A[10]={3,5,8,9,60};
    int B[6]={7,2,1,66,23};
    create1(A,5);
    create2(B,5);
    display(first);
    display(second);
    concat(first,second);
    display(first);
}