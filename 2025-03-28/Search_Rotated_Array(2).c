#include<stdio.h>

int Search(int [],int,int);
int main()
{
    printf("Searching in a rotated array.\n");
    int arr[]={1,1,1,1,1,1,1,1,2,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=2;
    int result=Search(arr,n,target);
    if(result==1) printf("The target %d is present in the given data set.\n",target);
    else printf("The target %d is not found in the given data set.\n",target);
    return 0;
}

int Search(int arr[], int n, int target)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int middle=left+(right-left)/2;

        if(arr[middle]=target) return 1;

        if(arr[middle]== arr[left])
        {
            left++;
            continue;
        }


        if(arr[left] <= arr[middle])
        {
            if(arr[left] <= target && target<arr[middle]) right=middle-1;
            else left=middle+1;
        }
        else
        {
            if(arr[middle] < target && target<=arr[right]) left=middle+1;
            else right=middle-1;
        }

    }
    return 0;
}
