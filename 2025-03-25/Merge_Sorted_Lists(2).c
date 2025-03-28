#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int data;
    struct List *next;
}List;

void createList(List **,List **,int);
void Sort(List **,List **,List **,int,int);
void deleteList(List *);

int main()
{
    printf("Program to sort the array through the sorting methods.\n");
    int arr[]={1,5,8,7,9};
    int brr[]={2,4,5,6,7};
    int n1=sizeof(arr)/sizeof(arr[0]);
    int n2=sizeof(brr)/sizeof(brr[0]);

    List *head1,*tail1,*head2,*tail2;
    head1=tail1=head2=tail2=NULL;
    
    for(int i=0;i<n1;i++)
    createList(&head1,&tail1,arr[i]);
    
    for(int i=0;i<n2;i++)
    createList(&head2,&tail2,brr[i]);
    
    List *traversal=head1;
    printf("The first sorted list is:\n");
    while(traversal!=NULL)
    {
        printf("%d -> ",traversal->data);
        traversal=traversal->next;
    }
    printf("NULL\n");
    
    traversal=head2;
    while(traversal!=NULL)
    {
        printf("%d -> ",traversal->data);
        traversal=traversal->next;
    }
    printf("NULL\n");
    
    tail1->next=head2;
    traversal=head1;
    printf("The merged list is:\n");
    while(traversal!=NULL)
    {
        printf("%d -> ",traversal->data);
        traversal=traversal->next;
    }
    printf("NULL\n");

    printf("The sorted final list is:\n");
    Sort(&head1,&tail1,&head2,n1,n2);
    while(head1!=NULL)
    {
        printf("%d -> ",head1->data);
        head1=head1->next;
    }
    printf("NULL\n");

    deleteList(head1);
    deleteList(head2);
}

void createList(List ** head,List **tail,int data)
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

void Sort(List **head1,List **tail1,List **head2,int n1,int n2)
{
    List *curr=*head1;
    List *traversal=*head2;
    for(int i=0;i<n1+n2;i++)
    {
        traversal=curr !=NULL ? curr->next : NULL ;
        for(int j=i+1;j<n2+n1;j++)
        {
            if(curr==NULL || traversal==NULL) break;
            if(curr->data > traversal->data )
            {
                int temp=curr->data;
                curr->data=traversal->data;
                traversal->data=temp;
            }
            traversal=traversal->next;
        }
        curr=curr->next;
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