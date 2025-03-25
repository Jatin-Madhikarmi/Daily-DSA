#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int data;
    struct List *link;
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
void Inorder(BST *);
void Delete(List *);
void postorderDeletion(BST *);
int main()
{
    printf("Program to Merge two Sorted Linked Lists.\n");
    List *head1,*tail1;
    head1=tail1=NULL;
    int arr[]={1,2,3,4,5};
    int n1=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n1;i++)
    {
        createList(&head1,&tail1,arr[i]);
    }
    
    List *head2,*tail2;
    head2=tail2=NULL;
    int brr[]={2,1,5,6,3,4};
    int n2=sizeof(brr)/sizeof(brr[0]);
    for(int i=0;i<n2;i++)
    {
        createList(&head2,&tail2,brr[i]);
    }

    tail1->link=head2;
    struct List *trav=head1;

    BST *root=NULL;
    while(head1!=NULL)
    {
        root=insert(root,head1->data);
        head1=head1->link;
    }
    printf("\nThe sorted List is :\n");
    Inorder(root);
    Delete(trav);
    Delete(head2);
    postorderDeletion(root);
    return 0;
}

void createList(List **head, List **tail, int data)
{
    List *temp=malloc(sizeof(List));
    temp->data=data;
    temp->link=NULL;
    if(*head==NULL && *tail==NULL)
    {
        *head=*tail=temp;
    }
    else
    {
        (*tail)->link=temp;
        (*tail)=temp;
    }
}

BST *insert(BST *root, int data)
{
    if(root==NULL)
    return newNode(data);

    if(data <= root->data)
    {
        root->left=insert(root->left,data);
    }

    else
    {
        root->right=insert(root->right,data);
    }
}

BST *newNode(int data)
{
    BST *root=malloc(sizeof(BST));
    root->left=NULL;
    root->right=NULL;
    root->data=data;
    return root;
}

void Inorder(BST *root)
{
    if(root==NULL)
    return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

void Delete(List *head)
{
    while(head!=NULL)
    {
        List *temp=head;
        head=head->link;
        free(temp);
    }
}
void postorderDeletion(BST *root)
{
    if(root=NULL)
    return;
    postorderDeletion(root->left);
    postorderDeletion(root->right);
    free(root);
}
