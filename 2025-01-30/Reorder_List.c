#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

void CreateNode(Node **head,Node **tail, int data);
void PrintNodes(Node **head);
void Reorder(Node **head);
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
    // CreateNode(&head,&tail,6);
    PrintNodes(&head);
    Reorder(&head);
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

void Reorder(Node **head) 
{
    if (*head == NULL || (*head)->link == NULL) {
        return; // No need to reorder if there are 0 or 1 elements
    }

    // Count the number of nodes
    int n = 0;
    Node *traversal = *head;
    while (traversal != NULL) {
        n++;
        traversal = traversal->link;
    }

    Node *a[n];
    traversal = *head;
    for (int i = 0; i < n; i++) {
        a[i] = traversal;
        traversal = traversal->link;
    }

    int i = 0, j = n - 1;
    while (i < j) {
        a[i]->link = a[j];
        i++;
        if (i == j) break; // Handle odd-length list case
        a[j]->link = a[i];
        j--;
    }
    a[j]->link = NULL;
    traversal = *head;
    while (traversal != NULL) {
        printf("%d\t", traversal->data);
        traversal = traversal->link;
    }
    printf("\n");
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

