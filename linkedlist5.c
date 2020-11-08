/* inserting elements in a linked list
at first,last and valid position*/
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
}
int count(struct Node *p)
{
    int c=0;
    while(p)//same as checking if p!=NULL
    {
        c++;
        p=p->next;
    }
    return c;
}
void insert(struct Node *p,int pos,int x)
{
    struct Node *t;
    if(pos<0 ||pos>count(p))
        printf("Invalid position");
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(pos==0)
    {

        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
       for(int i=0;i<pos-1 && p;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
        display(first);
      
       
    }
}
int main()
{
    int A[10]={3,5,8,9,60};
    create(A,5);
    display(first);
    printf("\n");
    insert(first,-1,30);

}