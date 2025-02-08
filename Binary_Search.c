#include<stdio.h>

int binarySearch(int arr[], int n, int target);

int main()
{
    printf("Program to implement the binary search in an array.\n");
    int arr[]={0,1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=0;
    int result=binarySearch(arr,n,target);
    if(result==-1) printf("Target is not in the array.\n");
    else printf("The target %d is at the index %d.",target,result);
    return 0;
}

int binarySearch(int arr[], int n, int target)
{
    int left=0,right=n-1,mid=0;
    while(left<=right)
    {
        mid=left+(right-left)/2;

        if(target==arr[mid]) return mid;

        if(target<arr[mid]) right=mid-1;
        else left=mid+1;
    }
    return -1;
    
}
