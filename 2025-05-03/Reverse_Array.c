#include<stdio.h>

void printArray(int arr[],int n);
void reverseArray(int arr[],int n);

int main()
{
    printf("Program to reverse an array.\n");
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("The original array is: \n");
    printArray(arr,n);
    reverseArray(arr,n);
    printf("The reversed array is: \n");
    printArray(arr,n);
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

void reverseArray(int arr[], int n)
{
    int L=0,R=n-1;
    for(int i=0;i<n/2;i++)
    {
        int temp=arr[L];
        arr[L]=arr[R];
        arr[R]=temp;
        L++,R--;
    }

}
