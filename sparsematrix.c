#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct element
{
    /* data */
    int i;
    int j;
    int x;
};
struct sparse
{
    /* data */
    int m;
    int n;
    int num;
    struct element *e;
};
void create_sparse(int a[100][100],int r,int c,struct sparse *s,int count)
{
  s->m=r;
  s->n=c;
  s->num=count;
  s->e=(struct element *)malloc(s->num*sizeof(struct element));
  s->e[0].i=r;
  s->e[0].j=c;
  s->e[0].x=count;
  int k=1;
  for(int r=0;r<s->m;r++)
  {
      for(int t=0;t<s->n;t++)
      {
            if(a[r][t]!=0)
            {
                s->e[k].i=r+1;
                s->e[k].j=t+1;
                s->e[k].x=a[r][t];
                k++;

            }
      }
  }
printf("The non zero elements of sparse matrix\n");
printf("[%d %d %d]\n",s->e[0].i,s->e[0].j,s->e[0].x);
for(int q=1;q<=count;q++)//printing elements in 3 column format
    {
        printf("[%d %d %d]\n",s->e[q].i,s->e[q].j,s->e[q].x);
           
    }    
free(s->e);

}

    

int read_matrix(int a[100][100],int r,int c)
{
    int i=0,j=0,count=0;
    printf("Enter elements of matrix\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("[%d][%d] element :",i, j);
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
                count++;
        }
    }
    return count;
}

void main()
{
    int a[100][100],r,c;
    int count=0;
    printf("Enter the size of matrix\n");
    scanf("%d%d",&r,&c);
    struct sparse s;
    count=read_matrix(a,r,c);
    create_sparse(a,r,c,&s,count);
   
}
