#include<stdio.h>
#include<conio.h>
void display(int *,int);
void add(int *,int ,int);
void insert(int *,int ,int ,int );
void delete(int *,int,int );
int get(int *,int ,int );
void set(int *,int ,int ,int);
int main()
{
    int arr[]={3,6,9,10,78}, w,x,y,z,n1,a,n2;
    int length=sizeof(arr)/sizeof(arr[0]);
    
    display(arr,length);
    //printf("Enter the element you want to add\n");
    //scanf("%d",&y);
    //add(arr,length,y);
    //printf("Enter the index of array element you want to get\n");
    //scanf("%d",&x);
    //int element=get(arr,length,x);
    //printf("the element at index %d is %d",x,element);
    //printf("Enter the element you want to insert and its index\n");
    //scanf("%d%d",&w,&n1);
    //insert(arr,length,n1,w);
    //printf("Enter the array element you want to delete\n");
    //scanf("%d",&z);
    //delete(arr,length,z);
    printf("Enter the element and the index you want to set\n");
    scanf("%d%d",&a,&n2);
    set(arr,n2,a,length);

   
}
void display(int arr[],int l)
{
    for(int i=0;i<l;i++)
        printf("%d \n",arr[i]);
}

void delete(int arr[],int l,int index)
{
    int x=arr[index];
    for(int i=index;i<l-1;i++)
        arr[i]=arr[i+1];
    l--;
    printf("current length is");
    printf("%d\n",l);
    display(arr,l);

}
void add(int arr[],int l,int x)
{
    arr[l]=x;
    l++;
    printf("current length is");
    printf("%d\n",l);
    printf("The new array after appending is : \n");
    display(arr,l);
}
void insert(int arr[],int l,int index,int x)
{
    for(int i=l;i>index;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[index]=x;
    l++;
    printf("current length is");
    printf("%d\n",l);
    printf("new array after inserting a new element is :\n");
    display(arr,l);
   

}
int get(int arr[],int n,int index)
{
   if(index>=0 && index<n)
        return arr[index];
}
void set(int arr[],int index,int x,int n)
{
    if(index>=0 && index<n)
    {
        arr[index]=x;
    }
    display(arr,n);
}


