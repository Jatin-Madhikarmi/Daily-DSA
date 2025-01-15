#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

void CreateNodes(Node **head,Node **tail,int data);
void PrintNode(Node **head);
void ReverseNode(Node **head);
void FreeReversedNode(Node *Reversedhead);
void FreeNode(Node **head);

int main()
{
    printf("Reversal of a Single Linked List.\n");
    Node *head=NULL;
    Node *tail=NULL;
    CreateNodes(&head,&tail,1);
    CreateNodes(&head,&tail,2);
    CreateNodes(&head,&tail,3);
    PrintNode(&head);
    ReverseNode(&head);
    FreeNode(&head);
    return 0;
}

void CreateNodes(Node **head, Node **tail, int data)
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

void PrintNode(Node **head)
{
    Node *temp=*head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}

void ReverseNode(Node **head)
{
    Node *temp1=NULL;
    Node *temp=*head;
    Node *ReversedHead;
    while(temp!=NULL)
    {
        Node *current=malloc(sizeof(Node));
        current->data=temp->data;
        current->link=temp1;
        temp1=current;
        ReversedHead=current;
        temp=temp->link;
    }
    Node *temp3=ReversedHead;
    printf("The reversed Node are:\n");
    while(temp3!=NULL)
    {
        printf("%d\n",temp3->data);
        temp3=temp3->link;
    }
    FreeReversedNode(ReversedHead);

}

void FreeReversedNode(Node *Reversedhead)
{
    Node *temp;
    while(Reversedhead!=NULL)
    {
        printf("Freed Reversed Node\n");
        temp=Reversedhead;
        Reversedhead=Reversedhead->link;
        free(temp);
    }
}

void FreeNode(Node **head)
{
    Node *temp;
    while(*head!=NULL)
    {
        printf("Memory Freed from Heap.\n");
        temp=*head;
        *head=(*head)->link;
        free(temp);
    }
}
