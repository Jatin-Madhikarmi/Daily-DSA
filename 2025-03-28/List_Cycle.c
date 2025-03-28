#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int data;
    struct List *next;
}List;

void createList(List **,List **,int);
int detectList(List *);
void deleteList(List *);

int main()
{
    printf("Program to determine whether a linked list contains a cycle or not.\n");
    List *head,*tail;
    head=tail=NULL;
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    createList(&head,&tail,arr[i]);
    int cycle=detectList(head);
    if(cycle==0) printf("There is no cycle in the list.\n");
    else printf("There is a cycle in the list.\n");
    deleteList(head);
}

void createList(List **head,List **tail,int data)
{
    List *temp=malloc(sizeof(List));
    temp->data=data;
    temp->next=NULL;

    if(*head==NULL)
    *head=*tail=temp;

    else
    {
        (*tail)->next=temp;
        *tail=temp;
    }
}

int detectList(List *head)
{
    List *fast=head;
    List *slow=head;
    while(fast!=NULL)
    {
        for(int i=0;i<2;i++)
        {
            fast=fast!=NULL ? fast->next : NULL;
            if(fast==NULL) return 0;
        }
        if(fast==slow) return 1;
        if(fast->next==slow) return 1;
    }
    return 0;
}

void deleteList(List *head)
{
    while(head!=NULL)
    {
        List *temp=head;
        head=head->next;
        free(temp);
    }
}