#include<stdio.h>

void printMatrix(int rows, int columns, int arr[rows][columns]);
void Rotate(int rows,int columns,int arr[rows][columns]);
int main()
{
    printf("Rotate an image by 90 degress.\n");
    int rows=3,columns=3;;
    int arr[rows][columns];
    int no=1;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            arr[i][j]=no;
            no++;
        }
    }
    printf("The matrix before the rotation is:\n");
    printMatrix(rows,columns,arr);
    Rotate(rows,columns,arr);
    printf("The matrix after rotation is:\n"); 
    printMatrix(rows,columns,arr);
}


void printMatrix(int rows, int columns, int arr[rows][columns])
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%d \t",arr[i][j]);
        }
        printf("\n");
    }
}

void Rotate(int rows, int columns, int arr[rows][columns])
{
    int temp=0;
    int nRows=(rows-1);
    int Rows=nRows;
    for(int i=0;i<rows;i++)
    {
        for(int j=i;j<columns;j++)
        {
            temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    printf("Transpose is:\n");
    printMatrix(rows,columns,arr);
    
    for(int i=0;i<rows;i++)
    {
        nRows=Rows;
        for(int j=0;j<columns/2;j++)
        {
            int temp=arr[i][j];
            printf("The value of a[%d][%d] before swapping is %d.\n",i,j,arr[i][j]);
            arr[i][j]=arr[i][nRows];
            printf("The value of a[%d][%d] after swapping is %d.\n",i,j,arr[i][nRows]);
            arr[i][nRows]=temp;
            nRows--;
        }

    }

}
