/*Circular Queue using Array using switch*/
#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void display(struct Queue q)
{
    if(q.front==q.rear)
        printf("Empty Queue\n");
    else
    {
         for(int i=(q.front+1)%q.size;i!=q.rear;i=(i+1)%q.size)
             printf("%d ",q.Q[i]);
         printf("%d ",q.Q[q.rear]);
         printf("\n");
    }
    
}
void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is full\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
    
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
   return x; 
}
  
int main()
{
    struct Queue q;
    int c,x;
    q.front=q.rear=0;
    printf("Enter size of queue");
    scanf("%d",&q.size);
    q.size+=1;
    q.Q=(int*)malloc(q.size*sizeof(int));
  
    printf("Choose\n1 for Enqueue\n2 for Dequeue\n3 to Exit\n");
    printf("Enter your choice");
    scanf("%d",&c);
    while(c!=3)
    {
        switch(c)
        {
            case 1:
                printf("Enter the number to be inserted\n");
                scanf("%d",&x);
                enqueue(&q,x);
                break;
            case 2:
                printf("Element deleted is %d\n",dequeue(&q));
                break;
            default:
                printf("Wrong Choice\n");
                break;
        }
        printf("Enter your choice");
        scanf("%d",&c);
    }
    printf("Elements of circular queue are:");
    display(q);
    free(q.Q);
}