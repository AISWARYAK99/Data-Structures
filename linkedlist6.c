/* deletion operation in linked list
deleting first node ,deleting any node of linked list*/
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
void display(struct Node *z)
{
    while(z!=NULL)
    {
        printf("%d\t",z->data);
        z=z->next;
    }
}
int delete(struct Node *first,int pos)
{
    struct Node *p,*q;
    int x=-1;
    if(pos==1)
    {
        x=first->data;
        p=first;
        first=first->next;
        display(first);
    }
    else if(pos>1) 
    {
        p=first;
        q=NULL;
        for(int i=0;i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            q->next=p->next;
            x=p->data;
             display(first);    
        }
        else
        printf("\nInvalid position");//if pos grater than number of nodes of linked lists
    }
    else
        printf("Invalid position");//if pos less than zero  

    free(p);
    return x;
}
int main()
{
    int A[10]={3,5,8,9,60};
    create(A,5);
    display(first);
    printf("\n");
    delete(first,-1);
}

