#include<stdio.h>

int binarySearchRotated(int [],int,int);

int main()
{
    printf("Binary Search for a possible rotation in a array.\n");
    int arr[]={4,5,6,7,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=0;
    int result=binarySearchRotated(arr,n,target);
    if(result==-1) printf("Target is not present in the array.\n");
    else printf("The target %d is located in the %d index.",target,result);
    return 0;
}

int binarySearchRotated(int arr[],int n,int target)
{
    int left=0,right=n-1,mid=0;
    
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(arr[mid]==target) return mid;

        if(arr[left]<=arr[mid])
        {
            if(arr[left]<=target && target<arr[mid]) right=mid-1;
            else left=mid+1;
        }
        else
        {
            if(arr[mid]<target && target<=arr[right]) left=mid+1;
            else right=mid-1;
        }
    }
    return -1;
}
