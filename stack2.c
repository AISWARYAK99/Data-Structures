/*stack using array*/

#include<stdio.h>
#include<stdlib.h>
struct stack
{ 
	int top;
	int size;
	int *s;
};

void push(struct stack *st, int x)
{
	if(st->top == st->size-1)
		printf("*ERROR stack is full*\n");
	else
	{
		st->top++;//incrementing top 
		st->s[st->top]=x;//then inserting element to where top points
		
	}
}
 
int pop(struct stack *st)
{
	int x = -1;
	if(st->top == -1)
	{
		printf("*ERROR stack is empty*\n");
		return x;
	}
	x=st->s[st->top];//assigning element where top points to x
	st->top--;//decrementing top
	return x;
}

int peek(struct stack st,int pos)
{
	int x=-1,i =st.top-pos+1;
	if(i<0)
	{
		printf("invalid position\n");
		return x;
	}
	x=st.s[i];
	return x;
}

int isEmpty(struct stack st)
{
	return(st.top == -1);
}
	
int isFull(struct stack st)
{
	return(st.top == st.size-1);
}

void print(struct stack st)
{
	if(st.top==-1)
		printf("stack is empty\n");
	else{
		for(int i=0;i<=st.top;i++)
			printf("%d\t",st.s[i]);
		printf("\n");
	}
}

int main()
{
	int x=0;
	struct stack st;
	st.top = -1;
	st.size=3;

	st.s=(int*)malloc(st.size *sizeof(int));//dynamic allocation of stack

	push(&st,20);
	push(&st,30);
	push(&st,40);

	printf("stack elements: ");
	print(st);

	x=peek(st,1);
	printf("element at 1 position is: %d\n",x);

	if(isFull(st))
		printf("stack is full\n");
	else
		printf("stack is not full\n");

	x=pop(&st);
	printf("deleted element:  %d\n",x);
	
	if(isEmpty(st))
		printf("stack is empty\n");
	else
		printf("stack is not empty\n");
	return(0);
	free(st.s);
}
/*OUTPUT
stack elements: 20      30      40
element at 1 position is: 40
stack is full
deleted element:  40
stack is not empty*/