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
    printf("The matrix after rotation is:\n");
    Rotate(rows,columns,arr);
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
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            arr[i][j]=arr[j][i];
        }
    }
}
