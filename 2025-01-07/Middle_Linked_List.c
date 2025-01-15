#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *link;
}Node;

void CreateNode(Node **head,Node **tail,int data);
void PrintNodes(Node **head);
void MiddleNodes(Node **head);
void FreeNodes(Node **head);

int main()
{
    printf("Program to find the middle of a linked list.\n");
    Node *head=NULL;
    Node *tail=NULL;
    CreateNode(&head,&tail,1);
    CreateNode(&head,&tail,2);
    CreateNode(&head,&tail,3);
    CreateNode(&head,&tail,4);
    CreateNode(&head,&tail,5);
    PrintNodes(&head);
    MiddleNodes(&head);
    FreeNodes(&head);
    return  0;
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

void MiddleNodes(Node **head)
{
    Node *fast=*head;
    Node *slow=NULL;
    int counter=0,fast_counter=0,slow_counter=0,n=2;
    while((fast->link)!=NULL)
    {
        if(fast_counter>0)
        {
            for(int i=0;i<n;i++)
            {
                fast=fast->link;
                counter++;
            }
        }
        else
        {
            counter++;
            fast=fast->link;
        }

        if(slow_counter<=0)
        {
            slow=*head;
        }

        else
        {
            slow=slow->link;
        }
        slow_counter++;
        if((slow_counter%2)!=0)
        {
            fast_counter=1;
        }
        else
        {
            fast_counter=0;
        }
    }
    if(counter%2!=0)
    {
        printf("The Middle Node is %d.\n",slow->link->data);
    }
    else
    {
        printf("The Middle Node is %d.\n",slow->data);
    }

}

void PrintNodes(Node **head)
{
    Node *temp=*head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
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
