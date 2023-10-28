#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Initialize front and rear to -1 in the main function.
int enqueue(int queue[], int item, int *rear, int *front)
{
    if (*rear == MAX_QUEUE_SIZE - 1)
    {
        printf("Queue Overflow\n");
        return 0;
    }
    else
    {
        if (*front == -1 && *rear == -1)
        {
            *front = *rear = 0;
            queue[*rear] = item;
        }
        else
        {
            (*rear)++;
            queue[*rear] = item;
        }
        return 1;
    }
}

int dequeue(int queue[], int *rear, int *front)
{
    int item;
    if (*front == -1 || *front > *rear)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    else
    {
        item = queue[*front];
        if (*front == *rear)
        {
            *front = *rear = -1;
        }
        else
        {
            (*front)++;
        }
        printf("%d is deleted from the queue\n", item); // Print the deleted item.
        return item;
    }
}

int display(int front, int rear, int queue[])
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]); // Add a space after each element.
        }
        printf("\n"); // Add a newline after displaying the queue.
    }
}

int peek(int queue[], int rear, int front)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1; // Return a default value to indicate an empty queue.
    }
    else
    {
        return queue[front];
    }
}

int main()
{
    int queue[MAX_QUEUE_SIZE];
    int front = -1;
    int rear = -1;
    int choice;
    int item;

    while (1) // Use an infinite loop, you can exit it using "choice 5".
    {
        printf("################# Main Menu #################\n");
        printf("Enter your choice:\n");
        printf("1. Insert an element in the queue\n");
        printf("2. Delete an element from the queue\n");
        printf("3. Display the queue\n");
        printf("4. Peek the queue\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted:\n");
            scanf("%d", &item);
            if (enqueue(queue, item, &rear, &front)) // Check if the enqueue operation was successful.
                printf("%d is inserted in the queue\n", item);
            break;

        case 2:
            dequeue(queue, &rear, &front);
            break;

        case 3:
            display(front, rear, queue);
            break;

        case 4:
            item = peek(queue, rear, front);
            if (item != -1) // Check if the queue is not empty before printing the peeked item.
                printf("Peek: %d\n", item);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
