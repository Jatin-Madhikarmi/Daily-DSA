#include"CreateNode.h"

void CreateNode(Node **head,Node **tail, int data)
{
    if(*head==NULL)
    {
        Node *current=malloc(sizeof(Node));
        if(current==NULL)
        {
            printf("Memory Allocation Failed.\n");
        }
        current->data=data;
        current->link=NULL;
        *head=current;
        *tail=current;
    }
    else
    {
        Node *current=malloc(sizeof(Node));
        if(current==NULL)
        {
            printf("Memory Allocation Failed.\n");
        }
        current->data=data;
        current->link=NULL;
        (*tail)->link=current;
        *tail=current;
    }
}

void PrintNodes(Node **head)
{
    Node *temp=*head;
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->link;
    }
}

void FreeNodes(Node **head)
{
    Node *temp;
    while(*head!=NULL)
    {
        printf("\nMemory Dellocated for the Nodes.\n");
        temp=*head;
        *head=(*head)->link;
        free(temp);
    }
}