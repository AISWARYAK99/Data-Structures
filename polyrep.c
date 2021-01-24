#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct term
{
    /* data */
    int coeff;
    int exp;
};
struct poly
{
    /* data */
    int n;
    struct term *t;
};
void main()
{
   
   
    int x,sum=0;
    struct poly p;
    printf("Enter num of non zero terms");
    scanf("%d",&p.n);
   
    p.t=(struct term*)malloc(p.n * sizeof(struct term));
   
    for(int i=0;i<p.n;i++)
        {
            printf("Enter coeff and power of term num %d ",i+1);
            scanf("%d%d",&p.t[i].coeff,&p.t[i].exp);
        }
    for(int j=0;j<p.n;j++)
    {
        sum+=p.t[j].coeff*pow(x,p.t[j].exp);
    }
    for(int i=p.n-1;i>=0;i--)
    {
        if(i>0)
            printf("%dx^%d+",p.t[i].coeff,p.t[i].exp);
        else
             printf("%dx^%d=",p.t[i].coeff,p.t[i].exp);
    }
    printf("%d\n",sum);      
    
}

