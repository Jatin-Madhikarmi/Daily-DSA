#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct Queue
{
    Node *node;
    struct Queue *next; 
}Queue;

Node* newNode(int);
Node* insert(Node* ,int );
void deleteNodes(Node*);
void BST(Node*);
void enqueue(Queue**,Queue**,Node*);
Node* dequeue(Queue**,Queue**);

int main()
{
    printf("Implementation of BST for a Tree.\n");
    Node *root=NULL;
    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,4);
    root=insert(root,6);
    root=insert(root,16);
    root=insert(root,20);
    printf("The BST Traversal is: ");
    Node *traversal=root;
    BST(traversal);
    printf("\n");
    printf("The Deleted Nodes are: ");
    deleteNodes(root);
    return 0;
}

Node* newNode(int data)
{
    Node *temp=malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory Allocation Failed.\n");
        exit(-1);
    }
    temp->data=data;
    temp->left=temp->right=NULL;
    return(temp);
}

Node* insert(Node* root,int data)
{
    if(root==NULL)
    {
        return newNode(data);
    }
    if(data < root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

void BST(Node* root)
{
    if(root==NULL)
    return;

    Queue *front=NULL;
    Queue *rear=NULL;

    enqueue(&front,&rear,root);

    while(front!=NULL)
    {
        Node *current=dequeue(&front,&rear);
        printf("%d ",current->data);

        if(current->left!=NULL) enqueue(&front,&rear,current->left);
        if(current->right!=NULL) enqueue(&front,&rear,current->right);
    }
}

void enqueue(Queue** front,Queue** rear,Node* root)
{
    Queue *newElement=malloc(sizeof(Queue));
    newElement->node=root;
    newElement->next=NULL;

    if(*rear==NULL)
    *front=*rear=newElement;
    else
    {
        (*rear)->next=newElement;
        *rear=newElement;
    }
}

Node* dequeue(Queue** front,Queue** rear)
{
    if(front==NULL) return NULL;

    Node *temp=(*front)->node;
    Queue *oldFront=*front;
    (*front)=(*front)->next;

    if(*front==NULL) *rear=NULL;
    free(oldFront);
    return(temp);
}

void deleteNodes(Node* root)
{
    if(root==NULL)
    return;
    deleteNodes(root->left);
    deleteNodes(root->right);
    printf("%d ",root->data);
    free(root);
}