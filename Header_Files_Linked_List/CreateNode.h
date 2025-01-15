#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *link;
}Node;

void CreateNode(Node **head,Node **tail,int data);
void PrintNodes(Node **head);
void FreeNodes(Node **head);
