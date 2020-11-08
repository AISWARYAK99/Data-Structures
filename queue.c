/* Queue using Array */
#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void enqueue(struct Queue *,int);
int dequeue(struct Queue *);
int main()
{
    struct Queue q;
    printf("Enter size of queue");
    scanf("%d",&q.size);
    q.Q=(int*)malloc(q.size*sizeof(int));
    q.front=q.rear=-1;
    enqueue(&q,10);
    enqueue(&q,3);
    enqueue(&q,6);
    enqueue(&q,33);
    enqueue(&q,90);
    printf("Queue after enqueue operation is:\n");
    for(int i=0;i<=q.rear;i++)
        printf("%d\n",q.Q[i]);
    int p=dequeue(&q);
   
    int s=dequeue(&q);
   
    printf("Queue after two dequeue operation is:\n");
    for(int i=q.front+1;i<=q.rear;i++)
        printf("%d\n",q.Q[i]);
    free(q.Q);
}
void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
        printf("Queue is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front ==q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
