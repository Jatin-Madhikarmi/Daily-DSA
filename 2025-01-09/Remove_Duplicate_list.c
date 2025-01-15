#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

void CreateNode(Node **head,Node **tail, int data);
void PrintNodes(Node **head);
void RemoveDuplicateNodes(Node **head);
void FreeNodes(Node **head);

int main()
{
    printf("Progarm to remove duplicate nodes in a given linked list.\n");
    Node *head=NULL;
    Node *tail=NULL;
    CreateNode(&head,&tail,1);
    CreateNode(&head,&tail,1);
    CreateNode(&head,&tail,2);
    CreateNode(&head,&tail,3);
    CreateNode(&head,&tail,3);
    CreateNode(&head,&tail,4);
    CreateNode(&head,&tail,4);
    CreateNode(&head,&tail,4);
    CreateNode(&head,&tail,5);
    CreateNode(&head,&tail,5);
    PrintNodes(&head);
    RemoveDuplicateNodes(&head);
    PrintNodes(&head);
    FreeNodes(&head);
    return 0;
}

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
    printf("\n");
}

void RemoveDuplicateNodes(Node **head)
{
    Node *temp=*head;
    while(temp!=NULL)
    {
        while(temp->link!=NULL && temp->data==temp->link->data)
        {
            Node *current=temp->link;
            temp->link=temp->link->link;
            free(current);
        }
        temp=temp->link;
    }
    printf("The Final Node after the deletion of the duplicate node is :\n");
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