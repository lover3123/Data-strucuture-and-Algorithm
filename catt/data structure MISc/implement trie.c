#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define ALPHABET_SIZE 26
 
struct node {
    int data;
    struct node* link[ALPHABET_SIZE];
};
 
struct node* root = NULL;
 
struct node* create_node() {
    struct node *q = (struct node*) malloc(sizeof(struct node));
    int x;
    for (x = 0; x < ALPHABET_SIZE; x++)
        q->link[x] = NULL;
    q->data = -1;
    return q;
}
 
void insert_node(char key[]) {
    int length = strlen(key);
    int index;
    int level = 0;
    if (root == NULL)
        root = create_node();
    struct node *q = root; // For insertion of each String key, we will start from the root
 
    for (; level < length; level++) {
        index = key[level] - 'a';
 
        if (q->link[index] == NULL) {
            q->link[index] = create_node(); // which is : struct node *p = create_node(); q->link[index] = p;
        }
 
        q = q->link[index];
    }
    q->data = level; // Assuming the value of this particular String key is 11
}
 
int search(char key[]) {
    struct node *q = root;
    int length = strlen(key);
    int level = 0;
    for (; level < length; level++) {
        int index = key[level] - 'a';
        if (q->link[index] != NULL)
            q = q->link[index];
        else
            break;
    }
    if (key[level] == '\0' && q->data != -1)
        return q->data;
    return -1;
}
 
int main(int argc, char **argv) {
    insert_node("by");
    insert_node("program");
    insert_node("programming");
    insert_node("data structure");
    insert_node("coding");
    insert_node("code");
    printf("Searched value: %d\n", search("code"));
    printf("Searched value: %d\n", search("geeks"));
    printf("Searched value: %d\n", search("coding"));
    printf("Searched value: %d\n", search("programming"));
    return 0;
}