/*
 * C Program to Find the Nearest Sibling of a Node in a Tree 
 */ 
#include <stdio.h>
#include <stdlib.h>
 
struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL;
 
// Function Prototype
void printout(struct btnode*);
struct btnode* newnode(int);
void find(struct btnode *, int);
void find_sibling(struct btnode *, int);
 
void main()
{
    int data, res = 0;
 
    root = newnode(50);
    root->l = newnode(20);
    root->r = newnode(30);
    root->l->l = newnode(70);
    root->l->r = newnode(80);
    root->l->r->r = newnode(60);
    root->l->l->l = newnode(10);
    root->l->l->r = newnode(40);
    printf("tree elements are\n");
    printout(root);
    printf("\nenter element to find");
    scanf("%d", &data);
    if (root->value == data)
        printf("--NO SIBLING FOR ROOT NODE--\n");
    else
    {
        find(root,data);
    }
}
 
// Create a node
struct btnode* newnode(int value)
{
    struct btnode* node = (struct btnode*)malloc(sizeof(struct btnode));
    node->value = value;
    node->l = NULL;
    node->r = NULL;
    return(node);
}
 
// to display the tree
void printout(struct btnode *tree)
{
    if (tree->l)
        printout(tree->l);
    printf("%d\t", tree->value);
    if (tree->r)
        printout(tree->r);
}
 
// To find node in a tree
void find(struct btnode *tree, int data)
{
    static int count = 0;
    struct btnode *ptr = root;
    int i;
 
    if (tree->l || tree->r)
    {
        if (tree->l->value == data)
            find_sibling(tree, 1);
        else if (tree->r->value == data)
            find_sibling(tree, 0);
        else
        {
            find(tree->l, data);
            find(tree->r, data);
        }
    }
}
 
// To find sibling of a node in a tree
void find_sibling(struct btnode *tree,int side)
{
    if (side == 1 && tree->r != NULL)
    {
        printf("--------SIBLING FOUND---------\n");
        printf("%d\n", tree->r->value);
    }
    else if (side == 0 && tree->l != NULL)
    {
        printf("--------SIBLING FOUND---------\n");
        printf("%d\n", tree->l->value);
    }
}
