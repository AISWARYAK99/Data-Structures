#include<stdio.h>
#include<conio.h>
int linsearch(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}
void main()
{
    int n,arr[100],item;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the item io be searched");
    scanf("%d",&item);
    int result=linsearch(arr,n,item);
    (result==-1)?printf("Element %d not found",item) :printf("Element %d found at index %d",item,result);
}