/* Reversing linked list by reversing the elements in linked list using an array*/
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
void rev(struct Node *first)
{
    struct Node *p=first;
    int i=0;
    int A[10];
    while(p!=NULL)
    {
        A[i++]=p->data;
        p=p->next;
    }
    p=first;
    i--;//bcoz we are exiting out from loop with i incremented thus to get exact i we decrement it
    while(p!=NULL)
    {
        p->data=A[i--];
        p=p->next;
    }
}
int main()
{
    int A[10]={3,5,8,9,60};
    create(A,5);
    display(first);
    rev(first);
    display(first);
}