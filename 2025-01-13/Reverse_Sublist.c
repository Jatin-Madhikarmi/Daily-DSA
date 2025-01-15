#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

void CreateNode(Node **head,Node **tail, int data);
void PrintNodes(Node **head);
void ReverseSublist(Node **head,int m,int n);
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
    CreateNode(&head,&tail,7);
    CreateNode(&head,&tail,8);
    PrintNodes(&head);
    ReverseSublist(&head,3,6);
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

void ReverseSublist(Node **head, int m, int n)
{
    Node *fast=*head;
    Node *slow=*head;
    Node *first=*head;
    int counter=0,count=1;
    int no=(n-m)+1;
    Node *a[no];
    int j=no-1;
    while(fast!=NULL)
    {
        if(counter<=0)
        {
            slow=*head;
            counter++;
        }
        else
        {
            slow=slow->link;
        }
        fast=fast->link;
        if(m==1)
        {
          for(int i=0;i<no;i++)
            {
                a[i]=first;
                first=first->link;
                fast=fast->link;
            }
            while(j!=0)
            {
                a[j]->link=a[j-1];
                j--;
                if(j==0)
                {
                    a[j]->link=first;
                    *head=a[no-1];
                }
            }  
        }
        if(count+1==m)
        {
            for(int i=0;i<no;i++)
            {
                a[i]=fast;
                if(fast==NULL)
                {
                    break;
                }
                fast=fast->link;
            }
            while(j!=0)
            {
                a[j]->link=a[j-1];
                j--;
                if(j==0)
                {
                    a[j]->link=fast;
                    slow->link=a[no-1];
                }
            }
        }
        count++;
        
    }
}
void FreeNodes(Node **head)
{
    Node *temp;
    int count=0;
    while(*head!=NULL)
    {
        count++;
        printf("\nMemory Dellocated for the Nodes(%d).\n",count);
        temp=*head;
        *head=(*head)->link;
        free(temp);
    }
}

