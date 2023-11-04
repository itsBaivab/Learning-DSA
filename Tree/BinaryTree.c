#include <stdio.h>

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
    return (leftChildIndex < size) ? tree[leftChildIndex] : -1;
}

// Function to access the right child of a node at index i
int rightChild(int i) {
    int rightChildIndex = 2 * i + 2;
    return (rightChildIndex < size) ? tree[rightChildIndex] : -1;
}

int main() {
    // Insert elements into the binary tree
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(70);
    insert(56);

    // Access and print nodes
    printf("Root Node: %d\n", tree[0]);
    printf("Left Child of Root: %d\n", leftChild(0));
    printf("Right Child of Root: %d\n", rightChild(0));
    printf("Left Child of 2: %d\n", leftChild(1));
    printf("Right Child of 2: %d\n", rightChild(1));
    printf("Left Child of 3: %d\n", leftChild(2));
    printf("Right Child of 3: %d\n", rightChild(2));
    printf("Left Child of 4: %d\n", leftChild(3));
    printf("Right Child of 4: %d\n", rightChild(3));


    return 0;
}
