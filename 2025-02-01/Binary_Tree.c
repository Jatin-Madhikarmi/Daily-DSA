#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
}Node;

Node* initializeTree(int ,int ,int);//Initializes a basic binary tree
Node* newNode(int);//Creates a new node in the binary tree
Node* insertLeft(Node*,int);//Inserts an element to the left hand side of the tree
Node* insertRight(Node*,int);//Inserts an element to the right hand side of the tree
Node* insert(Node*,int);//recursive function which adds an element to the NUll part of the parent node 
void preOrderTraversal(Node* root) ;

int main()
{
    Node *root=NULL;
    int rootData=10;//Root data 
    int leftData=5;//left hand side data of the tree
    int rightData=15;//Right hand side of the tree
    root=initializeTree(rootData,leftData,rightData);//functionto implement a basic structure of tree 
    /*
        10
       /\
      5  15
    the above initializeTree() function aims to create the above figure
    */ 
    Node *traversalRoot=root;
    traversalRoot=insertLeft(traversalRoot->left,4);
    traversalRoot=insertLeft(traversalRoot->left,6);
    traversalRoot=insertRight(traversalRoot->right,9);
    traversalRoot=insertRight(traversalRoot->right,20);
    printf("Pre-Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");
    return 0;
}

Node *initializeTree(int rootData,int leftData,int rightData)
{
    Node *root=newNode(rootData);
    root->left=newNode(leftData);
    root->right=newNode(rightData);
    return root;
}

Node *newNode(int data)
{
    Node *temp=malloc(sizeof(Node));
    if(temp==NULL)
    printf("Memory Allocation Failed.\n");
    temp->val=data;
    temp->left=temp->right=NULL;
    return temp;
}

Node *insertLeft(Node *root,int data)
{
    root=insert(root,data);
    return root;
}

Node *insertRight(Node *root,int data)
{
    root=insert(root,data);
    return root;
}

Node *insert(Node *root, int data)
{
    if(root==NULL)
    {
        return newNode(data);
    }
    if(data < root->val)
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
        printf("%d ", root->val);  // Process the current node
        preOrderTraversal(root->left);  // Visit left subtree
        preOrderTraversal(root->right);  // Visit right subtree
    }
}


