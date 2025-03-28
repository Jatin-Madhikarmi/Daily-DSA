#include<stdio.h>

int main()
{
    printf("Calculator through stack.\n");
    char *message[]={"1","2","*","5","+"};
    int size=sizeof(message)/sizeof(message[0]);
    for(int i=0;i<size;i++)
    printf("%s ",message[i]);
    return 0;
}