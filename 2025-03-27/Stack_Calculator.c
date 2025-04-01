#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
    int val;
    struct stack *next;
}stack;

int evaulate(int size,char *tokens[size],stack *top);
void push(int val,stack **top);
int pop(stack **top);
int main()
{
    printf("Program to evaulate the operations.\n");
    char *tokens[]={"1","2","+","3","*"};
    int size=sizeof(tokens)/sizeof(tokens[0]);
    printf("The operations to be evaulated is:\n");
    for(int i=0;i<size;i++)
    printf("%s ",tokens[i]);

    stack *top=NULL;
    int result=evaulate(size,tokens,top);
    printf("The result of the above expression is %d.\n",result);
}

int evaulate(int size, char *tokens[size], stack *top)
{
    for(int i=0;i<size;i++)
    {
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0)
        {
            if(top==NULL || top->next==NULL) exit(-1);
            int b=pop(&top);
            int a=pop(&top);
            switch (tokens[i][0])
            {
            case '+':
                push(a+b,&top);
                break;
            case '-':
                push(a-b,&top);
                break;
            case '*':
                push(a*b,&top);
                break;
            case '/':
                push(a/b,&top);
                break;    
            default:
                printf("Operation Invalid,\n");
                break;
            }
        }
        else 
        {
            int num=atoi(tokens[i]);
            push(num,&top);
        }
    }
    return (pop(&top));
}

void push(int val, stack **top)
{
    stack *temp=malloc(sizeof(stack));
    temp->val=val;
    temp->next=*top;
    *top=temp;
}

int pop(stack **top)
{
    int val=(*top)->val;
    stack *temp=*top;
    (*top)=(*top)->next;
    printf("\nValue freed is %d.\n",val);
    free(temp);
    return val;
}
