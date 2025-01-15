#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

void CreateNodes(Node **head,Node **tail,int data);
void PrintNodes(Node **head);
void TraversalNodes(Node **head,Node **stack);
void push(Node *temp,Node **stack);
void Result(Node **stack,int data);
void FreeNodes(Node **head);
void FreeStack(Node **head);

int main()
{
    printf("Program to find the Nth Node from the last Node.\n");
    Node *head=NULL;
    Node *tail=NULL;
    Node *stack=NULL;
    CreateNodes(&head,&tail,1);
    CreateNodes(&head,&tail,2);
    CreateNodes(&head,&tail,3);
    CreateNodes(&head,&tail,4);
    CreateNodes(&head,&tail,5);
    PrintNodes(&head);
    TraversalNodes(&head,&stack);
    Result(&stack,2);
    FreeNodes(&head);
    FreeStack(&stack);
}

void CreateNodes(Node **head,Node **tail,int data)
{
    if(*head==NULL)
    {
        Node *temp=malloc(sizeof(Node));
        if(temp==NULL)
        {
            printf("Memory Allocation Failed.\n");
        }
        temp->data=data;
        temp->link=NULL;
        *head=temp;
        *tail=temp;
    }
    else
    {
        Node *temp=malloc(sizeof(Node));
        if(temp==NULL)
        {
            printf("Memory Allocation Failed.\n");
        }
        temp->data=data;
        temp->link=NULL;
        (*tail)->link=temp;
        *tail=temp;
    }
}

void PrintNodes(Node **head)
{
    Node *temp=*head;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
    
}

void TraversalNodes(Node **head, Node **stack)
{
    Node *temp=*head;
    while(temp!=NULL)
    {
        push(temp,stack);
        temp=temp->link;
    }
}

void push(Node *temp,Node **stack)
{
    Node *current=malloc(sizeof(Node));
    if(current==NULL)
    {
        printf("Memory Allocation Failed.\n");
    }
    current->data=temp->data;
    current->link=*stack;
    *stack=current;
}

void Result(Node **stack,int data)
{
    int counter=0;
    Node *temp=*stack;
    for(int i=0;i<=data-1;i++)
    {
        if(counter>0)
        {
            temp=temp->link;
        }
        counter++;
    }
    printf("The Nth node from the last node is %d.\n",temp->data);
}

void FreeNodes(Node **head)
{
    Node *temp;
    while(*head!=NULL)
    {
        printf("Memory Dellocated for the Nodes.\n");
        temp=*head;
        *head=(*head)->link;
        free(temp);
    }

}

void FreeStack(Node **stack)
{
    Node *temp;
    while(*stack!=NULL)
    {
        printf("Memory Dellocated for the Stacks.\n");
        temp=*stack;
        *stack=(*stack)->link;
        free(temp);
    }

}