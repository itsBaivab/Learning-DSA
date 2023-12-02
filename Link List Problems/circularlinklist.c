#include <stdio.h>


struct Node{
    int data; 
    struct Node *next;
};

struct Node *head;


void beginsert()
{
    struct Node *ptr, *temp;
    int item;
    ptr = (struct Node *)malloc(sizeof(struct Node *));
    
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");

    }
    else 
    {
        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr->data = item;
        if(head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else 
        {
            temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\nNode inserted\n");
    }
    
}

void lastinsert()
{
    struct Node *ptr, *temp;
    int item;
    ptr = (struct Node *)malloc(sizeof(struct Node *));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");

    }
    else {
        printf("\nEnter value \n");
        scanf("%d",&item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr ;
            ptr -> next = head;

        }
        else{
            temp = head; 
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr ->next = head;
            head    = ptr; 
        }
    }
}


void randominsert()
{
    int i , loc ,item;
    struct Node *ptr, *temp;    
    ptr = (struct Node *)malloc(sizeof(struct Node *));
    if( ptr ==NULL)
    {
        printf("\nOVERFLOW");

    }
    else{
        printf("\nEnter element value");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert");
        scanf("%d",&loc);
        temp = head;
        for(i = 0; i < loc; i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        ptr ->next = temp ->next;
        temp ->next = ptr;
        printf("\nNode inserted\n");
    }

}



void begin_delete()
{
    struct Node *ptr;
    if (head == NULL)

    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        head =NULL;
        free(head);
        printf("\nNode deleted\n");

    }
    else 
    {
        ptr = head;
        while(ptr ->next !=head)
        {
            ptr = ptr ->next;
        }
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nNode deleted\n");

    }
}

void last_delete()
{
    struct Node *ptr, *preptr;
    if(head ==NULL)
    {
        printf("\nUNDERFLOW");
        
    }
    else if (head ->next == head)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");

    }
    else 
    {
        ptr = head;
        while(ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nNode deleted\n");

    }
}












int main()
{
    int choice = 0;
    printf("***********Main Menu**************\n");
    printf("Choose one option from the following list ...\n");
    printf("===============================================\n");
    printf("1.Insert in begining\n");
    printf("2.Insert at last\n");
    printf("3.Insert at any random location\n");
    printf("4.Delete from Beginning\n");
    printf("5.Delete from last\n");
    printf("6.Delete node after specified location\n");
    printf("7.Search for an element\n");
    printf("8.Show\n");
    printf("9.Exit\n");
    printf("===============================================\n");
    printf("Enter your choice?\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        beginsert();
        break;
    case 2:
        lastinsert();
        break;
    case 3:
        randominsert();
        break;

    case 4:
        begin_delete();
        break;

    case 5:
        last_delete();
        break;
    case 6:
        random_delete();
        break;
    case 7:
        search();
        break;
    case 8:
        display();
        break;
    case 9:
        exit(0);
        break;
    

    default:
        printf("Please enter valid choice..");
        break;
    }

}