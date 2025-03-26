#include<stdio.h>

void print(int [],int);
void InsertionSort(int [],int);
int main()
{
    printf("Insertion Sort.\n");
    int arr[]={9,5,2,4,2,1,4,5,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("The elements before the sorting are:\n");
    print(arr,n);
    printf("\nThe elements after the sorting are:\n");
    InsertionSort(arr,n);
    print(arr,n);
}

void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void InsertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j] > key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }

}
