/* Double linked list inserting nodes
  here *first is  created under struct so that it could be accessed in main and other functions
  so the changes made in first will be reflected on to the main   
*/
#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int length(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
void create(int A[],int n)
{
    struct Node *t,*last;//here the *first is not local to this function thus changes made here will be reflected on to the main
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
void insert(struct Node *p,int pos,int x)
{
    struct Node *t;
    int i;
    if(pos<0 || pos>length(p))
        printf("Invalid position\n");
    if(pos==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        if(first)
            first->prev=t;
        first=t;
    }
    else
    {
        for(i=0;i<pos-1;i++)
            p=p->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next!=NULL)
            p->next->prev=t;
            p->next=t;
    }
    
}

int main()
{
   int A[90]={12,20,30,65,23};
   create(A,5);
   printf("length of double linked list is %d\n",length(first));
   insert(first,4,88);
   display(first);
   return 0;
}
