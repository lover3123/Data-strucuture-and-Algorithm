/* C Program for creating the mirror image of a given tree.*/
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node* left, *right;
};
 
/*
 * Function to create new nodes.
 */
 
struct node* createnode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
 
    return(newnode);
}
 
/*
 *Function to swap left and right child of  a node for creating mirror image.
 */
 
void mirrorimage(struct node* root)
{
  if (root != NULL)
    {
        struct node* temp;
        /*first traversing the left subtree */
        mirrorimage(root->left);      
        /* Traversing the right subtree. */
        mirrorimage(root->right);     
 
        /* swap the left and right child of all the nodes to create
         * a mirror image of a tree
         */
 
        temp = root->left;
        root->left  = root->right;   
        root->right = temp;
 
    }
}
 
/*
 * Function to find the height of a tree.
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
 
void currentlevel(struct node* root, int level)
{
    if (root != NULL)
    {
        if (level == 1)
        {
            printf("%d ", root->info);
        }
 
        else if (level > 1)
        {
            currentlevel(root->left, level-1);
            currentlevel(root->right, level-1);
        }
    }
 
}
 
int main()
{
   /* Creating first Tree.*/
 
    struct node *newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);
 
    /* Sample Tree 1- Balanced Tree.
 
 
                    25                   |                      25
                  /    \                 |                    /     \
                 27     19               |                  19      27
                / \     / \              |                 /  \    /  \
              17  91   13 55             |                55  13  91   17
 
             Input Tree                 Mirror           Output Tree
    */
 
    printf("Level Order Traversal of Tree 1 "
           "before creating its mirror image is \n");
 
    int i;
    int height = heightoftree(newnode);
 
    /* calling current level function, by passing levels one by one 
     * in an increasing order.
     */
 
    for(i = 1; i <= height; i++)      
    {
        currentlevel(newnode,i);
    }
    printf("\n\nLevel Order Traversal of Tree 1 "
               "after creating its mirror image is \n");
 
 
    height = heightoftree(newnode);
    mirrorimage(newnode);
 
   /* calling current level function, by passing levels one by one 
    * in an increasing order.
    */
 
    for(i = 1; i <= height; i++)   
    {
        currentlevel(newnode,i);
    }
 
    /*Creating second Tree.*/
 
    struct node *node = createnode(1);
    node->right = createnode(2);
    node->right->right = createnode(3);
    node->right->right->right = createnode(4);
    node->right->right->right->right = createnode(5);
 
    /* Sample Tree 2-   Right Skewed Tree (Unbalanced).
 
      1                                   |                                  1
       \                                  |                                 /
        2                                 |                                2
         \                                |                               /
          3                               |                              3
           \                              |                             /
            4                             |                            4
             \                            |                           /
              5                           |                          5
 
           Input Tree                   Mirror                    Output Tree
    */  
 
    printf("\n\nLevel Order Traversal of Tree 2 "
               "before creating its mirror image is \n");
 
    height = heightoftree(node);
 
    /* calling current level function, by passing levels one by one
     * in an increasing order.
     */
 
    for(i = 1; i <= height; i++)
    {
        currentlevel(node,i);
    }
 
    printf("\n\nLevel Order Traversal of Tree 2 "
               "after creating its mirror image is \n");
 
    height = heightoftree(node);
    mirrorimage(node);
 
    /* calling current level function, by passing levels one by one
     * in an increasing order.
     */
 
    for(i = 1; i <= height; i++)      
    {
        currentlevel(node,i);
    }
 
    /* Creating  third tree having just one root node */
    struct node *root = createnode(15);
 
 
 
    /* Sample Tree 3 -   Tree having just one root node.
 
                   15           |              15
             Input Tree                      Output Tree
                              Mirror
    */
 
    printf("\n\nLevel Order Traversal of Tree 3 "
               "before creating its mirror image is \n");
    height = heightoftree(root);
 
    /* calling current level function, by passing levels one by one
     * in an increasing order.
     */
 
    for(i = 1; i <= height; i++)  
    {
        currentlevel(root,i);
    }
 
    printf("\n\nLevel Order Traversal of Tree 3 "
               "after creating its mirror image is \n");
    height = heightoftree(root);
    mirrorimage(root);
 
    /* calling current level function, by passing levels one by one
     * in an increasing order.
     */
 
    for(i = 1; i <= height; i++)
    {
        currentlevel(root,i);
    }
 
    return 0;
}