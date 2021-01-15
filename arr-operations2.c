#include<stdio.h>
#include<conio.h>
int max(int arr[],int n)
{
    int max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}
int min(int arr[],int n)
{
    int min=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
            min=arr[i];
    }
    return min;
}
int sum(int arr[],int n)
{
    int total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
    }
    return total;
}
int avg(int arr[],int n)
{
    int total=0;
    for(int i=0;i<n;i++)
    {
        total+=arr[i];
    }
    return total/n;
}
void main()
{
    int n,arr[100],choice,result;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter your choice\n 1-Maximum\n 2-Minimum\n 3-Sum\n 4-Average\n 5-Exit");
    scanf("%d",&choice);
    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
                printf("largest value of array is %d\n",max(arr,n));
                break;
            case 2:
                printf("Minimum value of array is %d\n",min(arr,n));
                break;
            case 3:
                printf("Sum of elements of array is %d\n",sum(arr,n));
                break;
            case 4:
                printf("Average of elements in array ia %d\n",avg(arr,n));
                break;
            default:
                printf("Wrong Choice\n");
                break;
            
        }
        printf("Enter your choice\n");
        scanf("%d",&choice);
    }
}
