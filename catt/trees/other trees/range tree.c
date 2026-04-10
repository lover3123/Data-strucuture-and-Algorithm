#include <stdio.h>
#include <math.h>
 
// Structure to represent an range
struct range {
    int low, high;
};
 
// Structure to represent a node in range Search Tree
struct RTNode {
    range *i; // 'i' could also be a normal variable
    int max;
    RTNode *left, *right;
};
 
// A utility function to create a new range Search Tree Node
RTNode * newNode(range i) {
    RTNode *temp = new RTNode;
    temp->i = new range(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
}
;
 
// A utility function to insert a new range Search Tree Node
// This is similar to BST Insert.  Here the low value of range
// is used tomaintain BST property
RTNode *insert(RTNode *root, range i) {
    // Base case: Tree is empty, new node becomes root
    if (root == NULL)
        return newNode(i);
 
    // Get low value of range at root
    int l = root->i->low;
 
    // If root's low value is smaller, then new range goes to
    // left subtree
    if (i.low < l)
        root->left = insert(root->left, i);
 
    // Else, new node goes to right subtree.
    else
        root->right = insert(root->right, i);
 
    // Update the max value of this ancestor if needed
    if (root->max < i.high)
        root->max = i.high;
 
    return root;
}
 
// A utility function to check if given two ranges overlap
bool doOVerlap(range i1, range i2) {
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}
 
// The main function that searches a given range i in a given
// range Tree.
range *rangeSearch(RTNode *root, range i) {
    // Base Case, tree is empty
    if (root == NULL)
        return NULL;
 
    // If given range overlaps with root
    if (doOVerlap(*(root->i), i))
        return root->i;
 
    // If left child of root is present and max of left child is
    // greater than or equal to given range, then i may
    // overlap with an range is left subtree
    if (root->left != NULL && root->left->max >= i.low)
        return rangeSearch(root->left, i);
 
    // Else range can only overlap with right subtree
    return rangeSearch(root->right, i);
}
 
void inorder(RTNode *root) {
    if (root == NULL)
        return;
 
    inorder(root->left);
 
    cout << "[" << root->i->low << ", " << root->i->high << "]" << " max = "
            << root->max << endl;
 
    inorder(root->right);
}
 
// Driver program to test above functions
int main() {
    // Let us create range tree shown in above figure
    range ints[] = { { 15, 20 }, { 10, 30 }, { 17, 19 }, { 5, 20 },
            { 12, 15 }, { 30, 40 } };
    int n = sizeof(ints) / sizeof(ints[0]);
    RTNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, ints[i]);
 
    printf("Inorder traversal of constructed range Tree is\n");
    inorder(root);
 
    range x = { 6, 7 };
 
    printf("\nSearching for range [%d, %d]", x.low, x.high);
    range *res = rangeSearch(root, x);
    if (res == NULL)
        printf("\nNo Overlapping range");
    else
        printf("\nOverlaps with [%d, %d]", res->low, res->high);
}