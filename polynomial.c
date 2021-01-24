#include<stdio.h>
#include<stdlib.h>
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
void print(struct poly p)
{   int z;
     for(z=0;z<p.n;z++)
    {
        printf("%dx^%d",p.t[z].coeff,p.t[z].exp);
        if(z+1==p.n)
            printf("=0");
        else
             printf("+");

    }
}
void polysum(struct poly p1,struct poly p2,struct poly *p3)
{
    int i=0,j=0,k=0;
    p3->n=p1.n+p2.n;
    p3->t=(struct term*)malloc(p3->n * sizeof(struct term));
    while(i<p1.n && j<p2.n)
    {
        if(p1.t[i].exp > p2.t[j].exp)
            p3->t[k++]=p1.t[i++];
        
        else
        {

          if(p1.t[i].exp < p2.t[j].exp)
             p3->t[k++]=p2.t[j++];
          else
          {
              p3->t[k].exp=p1.t[i].exp;
              p3->t[k++].coeff=p1.t[i++].coeff + p2.t[j++].coeff;
          }
        }

          
    }
    
    while(i<p1.n)
        p3->t[k++]=p1.t[i++];
    
   
    while(j<p2.n)
        p3->t[k++]=p2.t[j++];
  
    p3->n=k;

}
void main()
{
   
    
    struct poly p1,p2,p3;
    printf("Enter num of non zero terms in p1");
    scanf("%d",&p1.n);
    p1.t=(struct term*)malloc(p1.n * sizeof(struct term));
   
    for(int i=0;i<p1.n;i++)
        {
            printf("Enter coeff and power of term num %d ",i+1);
            scanf("%d%d",&p1.t[i].coeff,&p1.t[i].exp);
        }

    printf("Enter num of non zero terms in p2");
    scanf("%d",&p2.n);
    p2.t=(struct term*)malloc(p2.n * sizeof(struct term));
    for(int j=0;j<p2.n;j++)
        {
            printf("Enter coeff and power of term num %d ",j+1);
            scanf("%d%d",&p2.t[j].coeff,&p2.t[j].exp);
        }
    system("cls");
    
    printf("\nP1 :");print(p1);
    printf("\nP2 :"); print(p2);    
    polysum(p1,p2,&p3);
    printf("\nP3 :");print(p3);
        
}

