/* Finding counts of nodes
 sum of datas in all nodes
 displaying datas of all nodes
 finding max,min value of data in the linked list
 linear search in linked lists
 both iteratively and recursively*/

#include<stdio.h>
#include<stdlib.h>
# define MIN_INT -32768
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
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        RDisplay(p->next);
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
int Rcount(struct Node *p)
{
    int c=0;
    if(p)//same as checking if p!=NULL
        return count(p->next)+1;
    else
        return 0;
    
}
int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int Rsum(struct Node *p)
{
    if(p)//p!=NULL
        return sum(p->next)+p->data;
   else
     return 0;
}
int max(struct Node *p)
{
    int m=MIN_INT;
    while(p)
    {
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    return m;
}
int Rmax(struct Node *p)
{
    int x=MIN_INT;
    if(p==0)
        return MIN_INT;
    else
    {
        x=Rmax(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
        
    }
    
}
int Rmax2(struct Node *p)
{
    int x=MIN_INT;
    if(p==0)
        return MIN_INT;
    else
    {
        x=Rmax(p->next);
        return x>p->data?x:p->data;        
    }
    
}
int min(struct Node *p)
{
    int m=32768;
    while(p)
    {
        if(p->data<m)
            m=p->data;
        p=p->next;
    }
    return m;
}
int Rmin(struct Node *p)
{
    if(p==0)
        return 32768;
    else
    {
        int x=Rmin(p->next);
        if(x<p->data)
            return x;
        else
            return p->data;
        
    }
    
}
struct Node *LSearch(struct Node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
    
}
struct Node *LRSearch(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    else if(key==p->data)
        return p;
    return LRSearch(p->next,key);
    
}
int main()
{
    int A[10]={3,5,8,9,60};
    create(A,5);
    display(first);
    RDisplay(first);
    struct Node *temp1,*temp2;
    printf("\nThe number of nodes is %d ",count(first));
    printf("\nThe number of nodes is %d ",Rcount(first));
    printf("\nThe sum of datas of nodes is %d ",sum(first));
    printf("\nThe sum of datas of nodes is %d ",Rsum(first));
    printf("\nThe maximum value of data is %d ",max(first));
    printf("\nThe maximum value of data is %d ",Rmax(first));
    printf("\nThe maximum value of data is %d ",Rmax2(first));
    printf("\nThe minimum value of data is %d ",min(first));
    printf("\nThe minimum value of data is %d ",Rmin(first));
    temp1=LSearch(first,12);
    if(temp1)
        printf("\nKey is found %d ",temp1->data);
    else
        printf("\nNot found");
    temp2=LRSearch(first,5);
    if(temp2)
        printf("\nKey is found %d",temp2->data);
    else 
        printf("\nNot found\n");
}