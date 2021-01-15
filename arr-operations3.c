#include<stdio.h>
#include<conio.h>
void display(int arr[],int l)
{
    for(int i=0;i<l;i++)
        printf("%d ",arr[i]);
}
void reverse(int arr[],int n)
{
    int temp;
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
void main()
{
    int n,arr[100];
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Array before reversing\n");
    display(arr,n);
    reverse(arr,n);
    printf("\nArray after reversing\n");
    display(arr,n);
    }