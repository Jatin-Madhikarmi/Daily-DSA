#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int val;
    struct List *next;
}List;

void createList(List **head,List **tail,int data);
void printList(List *head);
void mergeList(List *head1,List *head2);
void freeList(List *head);
int main()
{
    printf("Program to merge two sorted linked list.\n");
    List *head1,*tail1,*head2,*tail2;
    head1=tail1=head2=tail2=NULL;
    int arr1[]={1,3,4};
    int arr2[]={2,3,4};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    
    //Creating first list
    for(int i=0;i<n1;i++)
    createList(&head1,&tail1,arr1[i]);
    
    //Creating the secong list
    for(int i=0;i<n2;i++)
    createList(&head2,&tail2,arr2[i]);

    printf("The first list is:\n");
    printList(head1);
    printf("The second list is:\n");
    printList(head2);
    
    //Merge Lists
    mergeList(head1,head2);
    freeList(head1);
    freeList(head2);
    
    
}

void createList(List **head,List **tail,int data)
{
    List *temp=malloc(sizeof(List));
    temp->val=data;
    temp->next=NULL;

    if(*head==NULL)
    *head=*tail=temp;

    else
    {
        (*tail)->next=temp;
        *tail=temp;
    }
}

void printList(List *head)
{
    List *temp=head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->val);
        temp=temp->next;
    }
    printf("NULL\n");
}

void mergeList(List *head1, List *head2)
{
    while(head1!=NULL || head2!=NULL)
    {
        while (head2->val >= head1->val)
        {
            List *temp=head1->next;
            List *backup=head2->next;
            head1->next=head2;
            head2->next=temp;
            head2=backup;
        }
        head1=head1->next;
    }
    printf("The final sorted list is:\n");
    printList(head1);
}

void freeList(List *head)
{
    while(head!=NULL)
    {
        List *temp=head;
        head=head->next;
        free(temp);
    }
}
