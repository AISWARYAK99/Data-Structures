#include<stdio.h>
#include<conio.h>
void selectionsort(int *,int);
void swap(int *,int *);
void printarray(int *,int);

int main(){
    int arr[100],n;
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the array elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n);
    printf("the sorted array is :");
    printarray(arr,n);
    return 0;
    
    }

void selectionsort(int arr[],int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        swap(&arr[min],&arr[i]);        
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
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}