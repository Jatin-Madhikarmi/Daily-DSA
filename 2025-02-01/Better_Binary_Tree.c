#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* insert(Node* ,int);
Node* newNode(int);
void preOrderTraversal(struct Node* ); 
void deleteNodes(struct Node* ); 

int main()
{
    Node *root=NULL;
    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,4);
    root=insert(root,6);
    root=insert(root,9);
    root=insert(root,20);
    Node *traversalRoot=root;
    printf("Pre-Order Traversal: ");
    preOrderTraversal(traversalRoot);
    printf("\n");
    deleteNodes(root);
    return 0;
}

Node* newNode(int data)
{
    Node *temp=malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
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

void preOrderTraversal(struct Node* root) 
{
    if (root != NULL) 
    {  // Base case: If tree is empty, return
        printf("%d ", root->data);  // Process the current node
        preOrderTraversal(root->left);  // Visit left subtree
        preOrderTraversal(root->right);  // Visit right subtree
    }
}

void deleteNodes(Node *root)
{
    if(root==NULL)
    return;
    deleteNodes(root->left);
    deleteNodes(root->right);
    printf("%d ",root->data);
    free(root);
}
