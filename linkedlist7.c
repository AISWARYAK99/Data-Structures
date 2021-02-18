#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first,*last=NULL;
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
void InsertLast(struct Node *p,struct Node *q,int x)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node *));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
        last=t;
       
    }
    else
    {
        last->next=t;
        last=t;
       
    }
}

int main()
{
  
   InsertLast(first,last,12);
   InsertLast(first,last,6);
   InsertLast(first,last,2);
   display(first);
}