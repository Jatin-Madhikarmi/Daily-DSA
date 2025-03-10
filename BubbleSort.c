#include<stdio.h>

void BubbleSort(int arr[]);
int main()
{
    printf("Program to demonstrate the Bubble Sort.\n");
    int arr[5]={65,22,11,1,2};
    BubbleSort(arr);
    return 0;
}

void BubbleSort(int arr[])
{
    int n=5;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if ( arr[j] > arr[j+1])
            {
                int temp=0;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The sorted array is \n");
    for(int i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,arr[i]);
    }
}
