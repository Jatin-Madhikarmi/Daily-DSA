#include<stdio.h>

int BinarySearch(int [],int);
int main()
{
    int target=5;
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int index=BinarySearch(arr,target);
    printf("The index is %d.\n",index);
    return 0;
}

int BinarySearch(int arr[], int traget)
{
    int m=sizeof(&arr);
    int left=0;
    int right=m-1;
    while(left<=right)
    {
        int middle=left+(right-left)/2;
        if(arr[middle]==traget) return middle;

        if(traget < arr[middle]) right=middle-1;

        else left=middle+1;
    }
    return left;
}
