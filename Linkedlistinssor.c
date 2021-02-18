/* Inserting elements in a sorted single linked list*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n)
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
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
void sortinser(struct Node *first,int x)
{
    struct Node *p,*q,*t;
    p=first;
    q=NULL;
    while(p && p->data<x)
    {
        q=p;
        p=p->next;
    }
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=q->next;//same if we use t->next=p
    q->next=t;
}
int main()
{
    int A[10]={3,5,8,9,60};
    create(A,5);
    display(first);
    sortinser(first,11);
    display(first);
}