#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    char *val;
    struct stack *next;
}stack;

void reversePolish(char *tokens[],int size,stack *top);
void push(char *operator,stack **top);
char *pop(stack **top);
int main()
{
    printf("Program to conevert an expression into reverse polish notation.\n");
    char *tokens[]={"1","+","2"};
    printf("The original notation is:\n");
    int size=sizeof(tokens)/sizeof(tokens[0]);
    for(int i=0;i<size;i++)
    printf("%s ",tokens[i]);

    printf("\nIt's equivalent reverse polish notation is\n");
    stack *top=NULL;
    reversePolish(tokens,size,top);
    return 0;
}

void reversePolish(char *tokens[], int size, stack *top)
{
    for(int i=0;i<size;i++)
    {
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 || strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0)
        {
            push(tokens[i],&top);
        }
        else printf("%s ",tokens[i]);
    }
    while(top!=NULL)
    {
        char *num=pop(&top);
        printf("%s ",num);
        top=top->next;
    }
}

void push(char *operator, stack ** top)
{
    stack *temp=malloc(sizeof(stack));
    temp->val=operator;
    temp->next=*top;
    *top=temp;
}

char *pop(stack **top)
{
    char *val=(*top)->val;
    stack *temp=*top;
    (*top)=(*top)->next;
    free(temp);
    return val;
}
