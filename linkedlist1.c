/* creating single linked list of 2 nodes*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
int main()
{
    struct Node *first,*current;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=10;
    first->next=NULL;
    current =(struct Node *)malloc(sizeof(struct Node));
    current->data=100;
    current->next=NULL;
    first->next=current;
    display(first);

}
