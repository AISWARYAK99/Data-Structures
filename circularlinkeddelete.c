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
int delete(struct Node *p,int pos)
{
    struct Node *q;
    int x=-1;
    if(pos<0 || pos>Circularcount(p))
        return -1;
    if(pos==1)
    {
        while(p->next!=head)
            p=p->next;
        x=head->data;
        if(p==head)
        {
            free(head);
            head=NULL;
        }
        else
        {
            p->next=head->next;;
            free(head);
            head=p->next;
        }
        
    }
    else
    {
        for(int i=0;i<pos-2;i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
        
    }
    return x;
    
}

int main()
{
    int A[10]={55,8,3,9,32};
    create(A,5);
    delete(head,5);
    display(head);
}