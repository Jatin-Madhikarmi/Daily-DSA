#include<stdio.h>
#include"C:\Users\jatin\OneDrive\Desktop\Daily DSA\Header_Files_Linked_List\CreateNode.h"

void RotateNode(Node **head,int n);

int main()
{
    printf("Program to Rotate a linked list.\n");
    Node *head=NULL;
    Node *tail=NULL;
    CreateNode(&head,&tail,1);
    CreateNode(&head,&tail,2);
    CreateNode(&head,&tail,3);
    CreateNode(&head,&tail,4);
    CreateNode(&head,&tail,5);
    PrintNodes(&head);
    RotateNode(&head,2);
    PrintNodes(&head);
    FreeNodes(&head);
    return 0;
}

void RotateNode(Node **head,int n)
{
    Node *fast=*head;
    Node *slow=*head;
    Node *last=NULL;
    Node *prev=NULL;

    for(int i=0;i<n;i++)
    {
        if(fast==NULL)
        {
            printf("N > no of nodes.\n");
        }
        fast=fast->link;
    }

    while(fast!=NULL)
    {
        last=fast;
        fast=fast->link;
        prev=slow;
        slow=slow->link;
    }

    prev->link=NULL;
    last->link=*head;
    *head=slow;
}






