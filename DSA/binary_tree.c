// Inorder => Left, Root, Right.
// Preorder => Root, Left, Right.
// Post order => Left, Right, Root.

// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

/* Given a binary tree, print its nodes in inorder*/
// Inorder => Left, Root, Right.
void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder(node->right);
}
// closure being used here

// Post order => Left, Right, Root.
void printPostorder(struct node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printPostorder(node->left);

    /* now recur on right child */
    printPostorder(node->right);

    /* then print the data of node */
    printf("%d ", node->data);
}

// Preorder => Root, Left, Right.
void printPreorder(struct node *node)
{
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    printPreorder(node->left);

    /* now recur on right child */
    printPreorder(node->right);
}

/* Driver code*/
int main()
{
    struct node *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(10);

    //              5
    //
    //      3                7
    //
    //  2       4           6       10

    // Function call
    printf("\nInorder traversal of binary tree is \n");
    printInorder(root);
    printf("\n");
    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);
    printf("\n");
    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);
    printf("\n");

    return 0;
}