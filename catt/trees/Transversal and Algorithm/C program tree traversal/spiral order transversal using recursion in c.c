/* C Program for Spiral Traversal of a given Tree */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node* left, *right;
};
 
 
struct node* createnode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
 
    return(newnode);
}
 
/*
 * Function to ascertain the height of a Tree
 */
 
int heightoftree(struct node* root)
{
    int max;
 
    if (root!=NULL)
    {
        /*Finding the height of left subtree.*/
        int leftsubtree = heightoftree(root->left); 
 
        /*Finding the height of right subtree.*/
        int rightsubtree = heightoftree(root->right); 
 
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}
 
/*
 * Function to print all the nodes left to right of the current level
 */
 
void left_to_right(struct node* root, int level)
{
    if (root != NULL)
    {
        if (level == 1)
        {
            printf("%d ", root->info);
        }
 
        else if (level > 1)
        {
            left_to_right(root->left, level-1);
            left_to_right(root->right, level-1);
        }
    }
}
 
void right_to_left(struct node *root, int level)
{
    if(root!=NULL)
    {
        if(level==1)
        {
            printf("%d ", root->info);
        }
        else
        {
            right_to_left(root->right, level-1);
            right_to_left(root->left, level-1);
        }
    }
}
 
 
/*
 * Main Function
 */
 
int main()
{
    int flag = 0;
    struct node *newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);
 
    /* Sample Tree 1- Balanced Tree
    
    
                    25
                  /    \
                 27     19
                / \     / \
              17  91   13 55
    */
 
    printf("Spiral Traversal of Tree 1 is \n");
 
    int i;
    int height = heightoftree(newnode);
    for(i = 1; i <= height; i++)
    {
        if(i%2 != 0)
        {   
            flag = 0;
            left_to_right(newnode,i);
        }
 
        if(i%2 == 0)
        {
            flag = 1;
            right_to_left(newnode,i);
        }
    }
 
    struct node *node = createnode(1);
    node->right = createnode(2);
    node->right->right = createnode(3);
    node->right->right->right = createnode(4);
    node->right->right->right->right = createnode(5);
    node->left = createnode(13);
 
    /* Sample Tree 2-  Unbalanced Tree
    	  
                   1
                /     \
               13      2
                        \
                         3
                          \
                           4
                            \
                             5
    */
 
    printf("\n\nSpiral Traversal of Tree 2 is \n");
 
    height = heightoftree(node);
    for(i = 1; i <= height; i++)
    {
        if(i%2 != 0)
        {
            flag = 0;
            left_to_right(node,i);
        }
 
        if(i%2 == 0)
        {
            flag = 1;
            right_to_left(node,i);
        }
    }
 
    struct node *root = createnode(15);
 
    /* Sample Tree 3- Tree having just one root node.
 
 
                   15                
 
    */
 
   printf("\n\nSpiral Traversal of Tree 3 is \n");
 
    height = heightoftree(root);
    for(i = 1; i <= height; i++)
    {
        if(i%2 != 0)
        {
            flag = 0;
            left_to_right(root,i);
        }
 
        if(i%2 == 0)
        {
            flag = 1;
            right_to_left(root,i);
        }
    }
    return 0;
}