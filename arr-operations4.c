#include<stdio.h>
#include<conio.h>
void display(int arr[],int l)
{
    for(int i=0;i<l;i++)
        printf("%d ",arr[i]);
}
void leftshift(int arr[],int n)
{
    int temp=arr[0];
    for(int i=0;i<n-1;i++)
        arr[i]=arr[i+1];
    arr[n-1]=temp;
    display(arr,n);
}
void leftrotate(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
        arr[i]=arr[i+1];
    arr[n-1]=0;
    display(arr,n);
}
void main()
{
    int n,arr[100],choice;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter your choice\n1-LeftShift \n2-LeftRotate \n3-Display\n4-Exit\n");
    scanf("%d",&choice);
    while(choice!=4)
    {
        switch(choice)
        {
            case 1:
                leftshift(arr,n);
                break;
            case 2:
                leftrotate(arr,n);
                break;
            case 3:
                display(arr,n);
                break;
            default:
                printf("Wrong Choice\n");
                break;
        }
        printf("Enter your Choice\n");
        scanf("%d",&choice);
    }
}