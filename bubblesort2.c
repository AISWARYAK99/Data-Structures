/* Bubble sort using array*/
#include<stdio.h>
#include<conio.h>
void bubblesort(int *,int);
void swap(int * ,int *);
void printarray(int *,int);


int main(){
    int arr[100],n;
    printf("enter size of the array");
    scanf("%d",&n);
    printf("enter array elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,n);
    printf("The sorted array is: ");
    printarray(arr,n);
    return 0;
}
void bubblesort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
               swap(&arr[j],&arr[j+1]);
        }

    }
}
void swap(int *p,int *q){
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;

}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
