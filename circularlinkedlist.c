/* Circular Linked List*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

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
void Rdisplay(struct Node *p)
{
  static int flag=0;
  if(p!=head || flag==0)
    {
        flag=1;
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}
int main()
{
    int A[10]={3,5,8,9,60};
    create(A,5);
    display(head);
    printf("\n");
    Rdisplay(head);
}