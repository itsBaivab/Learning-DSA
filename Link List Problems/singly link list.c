    #include <stdio.h>
    #include <stdlib.h>

    struct Node {
        int data;
        struct Node* next;
    };

    struct Node *head;

    void beginsert();
    void lastinsert();
    void randominsert();
    void begin_delete();
    void last_delete();
    void random_delete();
    void display();
    void search();

    void beginsert() {
        struct Node *ptr;
        int item;
        ptr = (struct Node *) malloc(sizeof(struct Node));
        if(ptr == NULL) {
            printf("\nOVERFLOW");
        }
        else {
            printf("\nEnter the element\n");
            scanf("%d", &item);
            ptr->data = item;
            ptr->next = head;
            head = ptr;
            printf("\nNode inserted");
        }
    }

    void lastinsert() {
        struct Node *ptr, *temp;
        int item;
        ptr = (struct Node*)malloc(sizeof(struct Node));

        if (ptr == NULL) {
            printf("\nOVERFLOW");
        }
        else if (head == NULL) {
            printf("\nEnter the element\n");
            scanf("%d", &item);
            ptr->data = item;
            ptr->next = NULL;
            head = ptr;
        }
        else {
            printf("\nEnter the element\n");
            scanf("%d", &item);
            ptr->data = item;
            ptr->next = NULL;
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            printf("\nNode inserted");
        }
    }

    void randominsert() {
        int i = 0, loc, item;
        struct Node *ptr, *temp;
        ptr = (struct Node *)malloc(sizeof(struct Node));
        if (ptr == NULL) {
            printf("\nOverflow");
        }
        else {
            printf("\nEnter the element\n");
            scanf("%d", &item);
            ptr->data = item;
            printf("\nEnter the location after which you want to insert\n");
            scanf("%d", &loc);
            temp = head; 
            while(i < loc-1) {
                if (temp == NULL){
                    printf("\nwrong location \n");
                    return;

                }
                temp = temp->next;
                i++;
                
            }
                ptr->next = temp->next;
                temp->next = ptr;
                printf("\nNode inserted");

        }
    }

    void begin_delete() {
        struct Node *ptr;
        ptr = head;
        if (ptr == NULL) {
            printf("\nUNDERFLOW");
        }
        else {
            ptr = head;
            head = ptr->next;
            free(ptr);
            printf("\nNode deleted");
        }
    }

    void last_delete() {
        if (head == NULL) {
            printf("\nUnderflow");
        }
        else {
            struct Node *ptr, *temp;
            temp = head;
            while (temp->next != NULL) {
                ptr = temp;
                temp = temp->next;
            }
            ptr->next = NULL;
            free(temp);
            printf("\nNode deleted");
        }
    }

    void random_delete() {
        int i, loc;
        struct Node *ptr, *temp;
        printf("\nEnter the location of the node after which you want to perform deletion \n");
        scanf("%d", &loc);
        temp = head;
        for(i = 0; i < loc; i++) {
            ptr = temp;
            temp = temp->next;
            if (temp == NULL) {
                printf("\nCan't delete");
                return;
            }
        }
        ptr->next = temp->next;
        free(temp);
        printf("\nDeleted node %d", loc + 1);
    }
    void display() {
        struct Node *ptr;
        ptr = head;
        if (ptr == NULL) {
            printf("\nNothing to print");
        }
        else {
            printf("\nPrinting values ....... \n");
            while (ptr != NULL) {
                printf("\n%d", ptr->data);
                ptr = ptr->next;
            }
        }
    }

    void search() {
        struct Node *ptr;
        int item, i = 0, flag = 1;
        ptr = head;
        if (ptr == NULL) {
            printf("\nEmpty List");
        }
        else {
            printf("\nEnter item which you want to search?\n");
            scanf("%d", &item);
            while (ptr != NULL) {
                if(ptr->data == item) {
                    printf("\nItem found at location %d", i + 1);
                    flag = 0;
                    break;
                }
                i++;
                ptr = ptr->next;
            }
            if (flag == 1) {
                printf("\nItem not found");
            }
        }
    }

    int main() {
        int choice = 0;
        while (choice != 9) {
            printf("\n\n*****MAIN MENU*****\n");
            printf("======================================\n");
            printf("1.Insert at beginning\n2.Insert at last\n3.Insert at random\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Display\n8.Search for an element\n9.Exit\n");
            printf("Enter your choice?\n");
            scanf("%d", &choice);
            switch (choice) {
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
                    display();
                    break;
                case 8:
                    search();
                    break;
                case 9:
                    exit(0);
                    break;
                default:
                    printf("Please enter valid choice..\n");
            }
        }
        return 0;
    }
