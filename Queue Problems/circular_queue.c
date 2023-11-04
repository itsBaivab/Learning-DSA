// Circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called 'Ring Buffer'.
//
// Circular Queue is also called 'Ring Buffer'.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100




int enqueue(int queue[],int item , int *rear, int *front)
{
     if(*front == -1 && *rear == -1)
        {
            *front = *rear = 0;
            queue[*rear] =item;
        }
    elseif ((*rear+1)%MAX_QUEUE_SIZE == front )
    {
        printf("queue is full\n");
    }
    else
    {
        *rear = (*rear+1)%MAX_QUEUE_SIZE;
        queue[*rear] = item;

    }
}

int dequeue(int queue[], int *rear, int *front)
{
    if (*front == -1 && *rear == -1)
    {
        printf("queue is empty \n");

    }
    else if (*front == *rear)
    {
        pringf("%d is deleted from the queue\n", queue[*front]);
        *front = *rear = -1;

    }
    else
    {
        
        printf("%d is delelted from the queue \n", queue[*front]);
        *front = (*front+1)%MAX_QUEUE_SIZE;

    }
    
}

void display(int *front, int *rear, int queue[])
{
    if (*front == -1 && *rear == -1 )
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("queue elements are : \n");
        for (int i = *front; i != *rear; i = (i+1)%MAX_QUEUE_SIZE)
        {
            printf("%d\n", queue[i]);
        }
    }
}

int peek(int *front, int *rear , int queue[])
{
    if (*front == -1 && *rear == -1 )
    {
        printf("queue is empty\n");
        printf("no elements to peek\n");

    }
    else
    {
        printf("peek element is %d\n", queue[*front]);
    }
}

int main ()
{
    int choice, item;
    int *front, *rear;
    int queue[MAX_QUEUE_SIZE];
    *front = *rear = -1;
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("3. display\n");
    printf("4. exit\n");
    printf("5. peek\n");
    do 
    {
        printf("enter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("enter the element to be inserted\m");
                scanf("%d", &item);
                enqueue(queue, &rear,&front, item);
                break;
            case 3:
                display(&front, &rear, queue);
                break;
            case 2:
                dequeue(queue, &rear, &front);
                break;
            case 3
        }
    }

}