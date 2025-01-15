#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}Node;

void CreateNode(Node **head,Node **tail, int data);
void PrintNodes(Node **head);
void SplitNodes(Node **head,int k);
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
    //PrintNodes(&head);
    SplitNodes(&head,4);
    //PrintNodes(&head);
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


void SplitNodes(Node **head, int k)
{
    int counter=0;
    Node *temp=*head;
    while(temp!=NULL)
    {
        temp=temp->link;
        counter++;
    }
    int a=(counter-1)/k;
    int b=(counter-1)%k;
    Node *arr[k];
    Node *fast[k];
    Node *slow[k];
    for(int length=0;length<k;length++)
    {
        arr[length]=*head;
        slow[length]=*head;
        fast[length]=(*head)->link;

    }
    int i=0,j=0,itertion=1;
    while(fast[i]!=NULL)
    {
        if(itertion==1)
        {
            for(int j=0;j<(a+b-1);j++)
            {
                arr[i]=*head;
                fast[i]=fast[i]->link;
                slow[i]=slow[i]->link;
            }
            i++;
            fast[i]=fast[i-1];
            slow[i]->link=NULL;
            itertion=0;
        }
        else
        {
            arr[i]=slow[i]=fast[i-1];
            fast[i]=fast[i-1]->link;
            for(int j=0;j<(a-1);j++)
            {
                fast[i]=fast[i]->link;
                slow[i]=slow[i]->link;
            }
            if(slow[i]==arr[i])
            {
                arr[i]=slow[i];
                fast[i]=fast[i]->link;
                if(fast[i]==NULL)
                {
                    break;
                }
            }
            i++;
        }
    }

    for(int j=0;j<k;j++)
    {
        printf("%d \n",arr[j]->data);
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
