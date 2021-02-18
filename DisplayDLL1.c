/* Double linked list creating,display,finding length
  here *first is not created under struct but created locally in main and create functions
  so the changes made in first to be reflected on to the main then we need to return its address to main
  that is done in create function 
*/
#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node * create(int A[],int n)
{
    struct Node *t,*last,*first;//here the *first is local to this function so to reflect that in main we return the first
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
    return first;
}
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
int main()
{
   struct Node *first=NULL;
   int A[90]={12,20,30,65,23};
   first=create(A,5);
   printf("length of double linked list is %d\n",length(first));
   display(first);
   return 0;
}
