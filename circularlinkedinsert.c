#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;//or t->next=head
        last->next=t;
        last=t;
    }
}
void display(struct Node *p)
{
   do
   {
       printf("%d ",p->data);
       p=p->next;
   } while (p!=head);
   
}
int Circularcount(struct Node *p)
{
    int c=0;
    do
    {
       c++;
       p=p->next;
    }while(p!=head);
    return c;
}
void insert(struct Node *p,int pos,int x)
{
    struct Node *t;
    if(pos<0 || pos>Circularcount(p))
        printf("Invalid position\n");
    if(pos==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)
                p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
        
    }
    else if(pos>0)
    {
        p=head;
        for(int i=0;i<pos-1;i++)
            p=p->next;
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->next=p->next;
            p->next=t;
    }
}
int main()
{
    int A[10]={55,8,3,9,32};
    create(A,5);
    insert(head,55,20);
    display(head);
}