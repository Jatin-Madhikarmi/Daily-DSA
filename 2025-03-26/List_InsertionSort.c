#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int data;
    struct List *next;
}List;

void createList(List **,List **,int );
void printNodes(List **);
void InsertionSort(List **,int);
void deleteList(List *);

int main()
{
    printf("Insertion Sort for Linked List.\n");
    List *head,*tail;
    head=tail=NULL;

    int arr[]={5,2,4,6,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++)
    createList(&head,&tail,arr[i]);

    int m=0;
    List *trav=head;
    while(trav!=NULL)
    {
        m++;
        trav=trav->next;
    }

    printf("The elements before the sorting is:\n");
    printNodes(&head);
    
    InsertionSort(&head,m);
    printf("The elements after the sorting is:\n");
    printNodes(&head);

    deleteList(head);
}

void createList(List **head, List **tail, int data)
{
    List *temp=malloc(sizeof(List));
    temp->data=data;
    temp->next=NULL;
    if(*head==NULL && *tail==NULL)
    *head=*tail=temp;
    else
    {
        (*tail)->next=temp;
        *tail=temp;
    }
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

void InsertionSort(List **head, int m)
{
    List *comp,*curr;
    comp=curr=*head;
    while(curr!=NULL)
    {
        comp=curr;
        curr=curr->next;
        int key=curr->data;
        while(comp->data > curr->data)
        {
            curr->data=comp->data;
        }
        comp->data=key;

    }
}

void printNodes(List **head)
{
    List *temp=*head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL.\n");
}
