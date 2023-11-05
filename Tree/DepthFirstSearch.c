#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];
int size = 0;

// Function to insert a node into the binary tree
void insert(int value) {
    if (size < MAX_SIZE) {
        tree[size] = value;
        size++;
    } else {
        printf("Tree is full. Cannot insert %d\n", value);
    }
}

// Function to access the left child of a node at index i
int leftChild(int i) {
    int leftChildIndex = 2 * i + 1;
    return (leftChildIndex < size) ? leftChildIndex : -1;
}

// Function to access the right child of a node at index i
int rightChild(int i) {
    int rightChildIndex = 2 * i + 2;
    return (rightChildIndex < size) ? rightChildIndex : -1;
}

// In-order traversal function
void inOrderTraversal(int index) {
    if (index != -1) {
        inOrderTraversal(leftChild(index));
        printf("%d ", tree[index]);
        inOrderTraversal(rightChild(index));
    }
}



// pre-order traversal function
// Pre-order traversal function
void preOrderTraversal(int index) {
    if (index != -1) {
        printf("%d ", tree[index]);
        preOrderTraversal(leftChild(index));
        preOrderTraversal(rightChild(index));
    }
}

//Post-order traversal function
void postOrderTraversal(int index) {
    if (index != -1) {
       
        postOrderTraversal(leftChild(index));
        postOrderTraversal(rightChild(index));
         printf("%d ", tree[index]);
    }
}
int main() {
    // Insert elements into the binary tree
    insert(4);
    insert(2);
    insert(6);
    insert(1);
    insert(3);
    insert(5);
    insert(7);

    // Access and print nodes
    printf("In-order traversal of binary tree: ");
    inOrderTraversal(0); // Start traversal from the root
    printf("\n");
    printf("pre-order traversal of binary tree: ");
    preOrderTraversal(0); // Start traversal from the root
    printf("\n");
    printf("post-order traversal of binary tree: ");
    postOrderTraversal(0); // Start traversal from the root
    printf("\n");
    return 0;
}
