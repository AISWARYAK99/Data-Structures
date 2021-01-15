#include<stdio.h>
#include<conio.h>
int binsearch(int arr[],int l,int h,int x)
{
    int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
           h=mid-1;
        else
           l=mid+1;
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
    printf("Enter the item to be searched\n");
    scanf("%d",&item);
    int result=binsearch(arr,0,n-1,item);
    (result==-1)?printf("Element %d not found",item) :printf("Element %d found at index %d",item,result);
}