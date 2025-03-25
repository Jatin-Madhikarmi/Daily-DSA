#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int data;
    struct List *next;
}List;

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}BST;

void createList(List **,List **,int);
BST *insert(BST *,int);
BST *newNode(int);
void Inorder(BST *,List **,List **);
void deleteList(List *);
void deleteBST(BST *);
int main()
{
    printf("Program to sort the elements of the linked list.\n");
    List *head,*tail;
    head=tail=NULL;
    int arr[]={1,3,4,2,3,4,6,6,4,2,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    createList(&head,&tail,arr[i]);

    List *trav=head;
    printf("The elements before the sorting are:\n");
    while(trav!=NULL)
    {
        printf("%d -> ",trav->data);
        trav=trav->next;
    }
    printf("NULL\n");
    trav=head;
    
    BST *root=NULL;
    while(trav!=NULL)
    {
        root=insert(root,trav->data);
        trav=trav->next;
    }

    printf("\nThe elements after the sorting are:\n");
    List *newHead,*newTail;
    newHead=newTail=NULL;
    Inorder(root,&newHead,&newTail);
    
    List *temp=newHead;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    deleteList(newHead);
    deleteList(trav);
    deleteBST(root);

}

void createList(List **head,List **tail,int data)
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

BST *insert(BST *root,int data)
{
    if(root==NULL)
    return newNode(data);

    if(data <= root->data)
    root->left=insert(root->left,data);

    else
    root->right=insert(root->right,data);

}

BST *newNode(int data)
{
    BST *temp=malloc(sizeof(BST));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

void Inorder(BST *root,List ** head,List **tail)
{
    if(root==NULL)
    return;

    Inorder(root->left,head,tail);
    createList(head,tail,root->data);
    Inorder(root->right,head,tail);
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

void deleteBST(BST *root)
{
    if(root==NULL)
    return ;

    deleteBST(root->left);
    deleteBST(root->right);
    free(root);
}