// Header file declarations
#include <stdio.h>
#include <stdlib.h> 

// Stucture for Binary Tree nodes
typedef struct Node {
    int data;        
    struct Node *left; 
    struct Node *right; 
} Node;

// Function to create Binary Tree nodes
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Handle memory allocation error
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for inserting Binary Tree nodes into the tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to calculate the height of the binary tree
int height(struct Node* node) {
    // Base case: If the tree is empty, its height is -1 (or 0 if counting nodes)
    if (node == NULL) {
        return -1; // Or 0 if you define height as number of nodes
    } else {
        // Recursively calculate the height of the left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // The height of the current node is 1 plus the maximum of the
        // heights of its left and right subtrees
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

int main() {
    // Create a sample binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6); // Example for a non-perfect tree

    printf("Height of the binary tree is: %d\n", height(root)); // Expected output: 2 (edges)

    // Example for a single-node tree
    struct Node* singleNodeTree = newNode(10);
    printf("Height of single-node tree is: %d\n", height(singleNodeTree)); // Expected output: 0

    // Example for an empty tree
    struct Node* emptyTree = NULL;
    printf("Height of empty tree is: %d\n", height(emptyTree)); // Expected output: -1

    // Free allocated memory (important in C)
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->left);
    free(root->right);
    free(root);
    free(singleNodeTree);

    return 0;
}
