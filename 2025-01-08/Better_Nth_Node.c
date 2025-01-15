#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

void CreateNodes(Node **head,Node **tail,int data);
void PrintNodes(Node **head);
void TraversalNodes(Node **head,int data);
void FreeNodes(Node **head);

int main()
{
    printf("Program to find the Nth Node from the last Node.\n");
    Node *head=NULL;
    Node *tail=NULL;
    CreateNodes(&head,&tail,1);
    CreateNodes(&head,&tail,2);
    CreateNodes(&head,&tail,3);
    CreateNodes(&head,&tail,4);
    CreateNodes(&head,&tail,5);
    PrintNodes(&head);
    TraversalNodes(&head,2);
    FreeNodes(&head);
    return 0;
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

void TraversalNodes(Node **head,int N)
{
    Node *fast=*head;
    Node *slow=*head;

    for(int i=0;i<N;i++)
    {
        if(fast==NULL)
        {
            printf("Nodes < N.\n");
        }
        fast=fast->link;
    }

    while(fast!=NULL)
    {
        fast=fast->link;
        slow=slow->link;
    }
    printf("The value the is %d from the %d w.r.to the last node .\n",slow->data,N);
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
