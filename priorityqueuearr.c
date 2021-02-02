/* Priority Queue using Array Smaller elements have higher priority we store elements in increasing order and delete higher 
priority(smaller element)using front*/
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
    int c,x;
    int A[100]={};
    printf("Enter size of queue");
    scanf("%d",&q.size);
    q.Q=(int*)malloc(q.size*sizeof(int));
    q.front=q.rear=-1;
    printf("Enter elements of priority queue\n");
    for(int i=0;i<q.size;i++)
    {
        scanf("%d",&x);
        enqueue(&q,x);
    }
    printf("priority queue elements are :\n");
    for(int i=q.front+1;i<=q.rear;i++)
        printf("%d ",q.Q[i]);
    printf("\ndeleted element is %d ",dequeue(&q));
    printf("\ndeleted element is %d ",dequeue(&q));
    printf("\ndeleted element is %d ",dequeue(&q));
    printf("\npriority queue elements are :\n");
    for(int i=q.front+1;i<=q.rear;i++)
        printf("%d ",q.Q[i]);
    
    free(q.Q);
}
void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
        printf("Queue is full\n");
    else if(q->rear==-1)
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
    else
    {
         
        int i,j;
        for(i=q->front+1;i<=q->rear;i++)
        {
            if(x<q->Q[i])
            {
               j=q->rear;
               while(j>=i)
               {
                   q->Q[j+1]=q->Q[j];
                   j--;
               }
                q->Q[i]=x;
                break;
            }
           
        }
        if(i>q->rear)
            q->Q[q->rear+1]=x;

        q->rear++;
    
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
