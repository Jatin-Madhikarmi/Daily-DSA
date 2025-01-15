#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left,*right;
}Node;

Node* InitializeRoot(int key);
Node* InitializeLeft(Node **root,int data);
Node* InitializeRight(Node **root,int data);
void InsertLeft(Node *Left,int data);
void InsertRight(Node *Right,int data);
void PrintLeftNodes(Node *Left);
//void PrintRightNodes(Node *Right);

int main()
{
    int key=100,leftdata=50,rightdata=150;
    printf("Implementation of a Binary Tree.\n");
    Node *Root=InitializeRoot(key);
    Node *Left=InitializeLeft(&Root,leftdata);
    Node *Right=InitializeRight(&Root,rightdata);
    InsertLeft(Left,20);
    InsertLeft(Left,55);
    InsertRight(Right,125);
    InsertRight(Right,152);
    PrintLeftNodes(Left);
    //PrintRightNodes(Right);
}

Node *InitializeRoot(int key)
{
    Node *root=malloc(sizeof(Node));
    if(root==NULL)
    {
        printf("Memory Allocation Failed.\n");
    }
    root->data=key;
    root->left=root->right=NULL;
    return root;
}

Node *InitializeLeft(Node **root, int data)
{
    if(data>(*root)->data)
    {
        printf("Unable to Initialize the Left Node w.r.to Root Node.\n");
    }
    else
    {
        Node *Left=malloc(sizeof(Node));
        if(Left==NULL)
        {
            printf("Memory Allocation Failed.\n");
        }
        Left->data=data;
        Left->left=Left->right=NULL;
        (*root)->left=Left;
        return (*root)->left;
    }
}
Node *InitializeRight(Node **root, int data)
{
    if(data<(*root)->data)
    {
        printf("Unable to Initialize the Right Node w.r.to Root Node.\n");
    }
    else
    {
        Node *Right=malloc(sizeof(Node));
        if(Right==NULL)
        {
            printf("Memory Allocation Failed.\n");
        }
        Right->data=data;
        Right->left=Right->right=NULL;
        (*root)->right=Right;
        return (*root)->right;
    }
}

void InsertLeft(Node *Left, int data)
{
    Node *temp=Left;
    Node *kick_back=Left;
    int counter=0;
    Node *current=malloc(sizeof(Node));
    if(current==NULL)
    {
        printf("Memory Allocation Failed.\n");
    }
    current->data=data;
    current->left=current->right=NULL;
    if(data<Left->data)
    {
        while(temp!=NULL)
        {
            if(counter>0)
            {
                kick_back=kick_back->left;
            }
            counter++;
            temp=temp->left;
        }
        kick_back->left=current;
    }
    else
    {
        while(temp!=NULL)
        {
            if(counter>0)
            {
                kick_back=kick_back->right;
            }
            counter++;
            temp=temp->right;
        }
        kick_back->right=current;
    }
}

void InsertRight(Node *Right, int data)
{
    Node *temp=Right;
    Node *kick_back=Right;
    int counter=0;
    Node *current=malloc(sizeof(Node));
    if(current==NULL)
    {
        printf("Memory Allocation Failed.\n");
    }
    current->data=data;
    current->left=current->right=NULL;
    if(data<Right->data)
    {
        while(temp!=NULL)
        {
            if(counter>0)
            {
                kick_back=kick_back->left;
            }
            counter++;
            temp=temp->left;
        }
        kick_back->left=current;
    }
    else
    {
        while(temp!=NULL)
        {
            if(counter>0)
            {
                kick_back=kick_back->right;
            }
            counter++;
            temp=temp->right;
        }
        kick_back->right=current;
    }

}

void PrintLeftNodes(Node *Left)
{
    Node *temp=Left;
    printf("%d %d %d",temp->data,temp->left->data,temp->right->data);
}
