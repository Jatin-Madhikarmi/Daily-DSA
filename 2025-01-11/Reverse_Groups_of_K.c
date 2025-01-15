#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

void CreateNode(Node **head,Node **tail, int data);
void PrintNodes(Node **head);
void ReverseGroups(Node **head,int k);
void FreeNodes(Node **head);

int main()
{
    printf("Progarm to reverse the groups of K.\n");
    Node *head=NULL;
    Node *tail=NULL;
    CreateNode(&head,&tail,1);
    CreateNode(&head,&tail,2);
    CreateNode(&head,&tail,3);
    CreateNode(&head,&tail,4);
    CreateNode(&head,&tail,5);
    CreateNode(&head,&tail,6);
    PrintNodes(&head);
    ReverseGroups(&head,2);
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

void ReverseGroups(Node **head, int k) 
{
    Node *temp = *head;
    Node *prev = NULL;
    Node *a[k];
    int breaker = 0;

    while (temp != NULL) 
    {
        int count = 0;
        for (int i = 0; i < k; i++) 
        {
            if (temp == NULL) 
            {
                breaker = 1;
                break;
            }
            a[i] = temp;
            temp = temp->link;
            count++;
        }

        if (breaker) break;

        for (int i = count - 1; i >= 0; i--) 
        {
            if (prev == NULL) 
            {
                *head = a[i];
            } 
            else 
            {
                prev->link = a[i];
            }
            prev = a[i];
        }
        prev->link = temp;
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

