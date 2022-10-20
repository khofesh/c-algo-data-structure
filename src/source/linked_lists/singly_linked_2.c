#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// self-referential structure
typedef struct node
{
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

// prototypes
void insert(ListNodePtr *head, char value);
void insert_at_end(ListNodePtr *head, char value);
void insert_at_beginning(ListNodePtr *head, char val);
char delete_node(ListNodePtr *head, char value);
void delete_at_beginning(ListNodePtr *head);
int is_empty(ListNodePtr *head);
void print_list(ListNodePtr currentPtr);

int main(int argc, char *argv[])
{
    ListNodePtr head = NULL;
    int choice = 0;
    char item = '\0';

    printf("enter you choice:\n"
           "1 to insert an element into the list in alphabetical order\n"
           "2 to insert an element at the end of the list.\n"
           "3 to insert an element at the beginning of the list.\n"
           "4 to delete an element from the list.\n"
           "5 to delete an element from the beginning of the list.\n"
           "6 to end.\n");

    printf(":: ");
    scanf("%d", &choice);

    while (choice != 6)
    {
        switch (choice)
        {
        case 1:
            printf("enter a character: ");
            scanf("\n%c", &item);
            insert(&head, item);
            print_list(head);
            break;
        case 2:
            printf("enter a character: ");
            scanf("\n%c", &item);
            insert_at_end(&head, item);
            print_list(head);
            break;
        case 3:
            printf("enter a character: ");
            scanf("\n%c", &item);
            insert_at_beginning(&head, item);
            print_list(head);
            break;
        case 4:
            if (!is_empty(&head))
            {
                printf("enter character to be deleted: ");
                scanf("\n%c", &item);

                if (delete_node(&head, item))
                {
                    printf("%c deleted.\n", item);
                    print_list(head);
                }
                else
                {
                    printf("%c not found.\n\n", item);
                }
            }
            else
            {
                printf("list is empty.\n\n");
            }
            break;
        default:
            printf("invalid choice.\n\n");
            printf("enter your choice:\n"
                   "1 to insert an element into the list.\n"
                   "2 to delete an element from the list.\n"
                   "3 to end.\n");
            break;
        }

        printf("? ");
        scanf("%d", &choice);
    }

    printf("end of run.\n");

    return 0;
}

void insert(ListNodePtr *head, char value)
{
    ListNodePtr newPtr;
    ListNodePtr previourPtr;
    ListNodePtr currentPtr;

    newPtr = malloc(sizeof(node_t));

    if (newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        previourPtr = NULL;
        currentPtr = *head;

        // loop to find the correct location in the list
        while (currentPtr != NULL && value > currentPtr->data)
        {
            previourPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // insert new node at the beginning of the list
        if (previourPtr == NULL)
        {
            newPtr->nextPtr = *head;
            *head = newPtr;
        }
        else
        {
            previourPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("%c not inserted. no memory available.\n", value);
    }
}

void insert_at_end(ListNodePtr *head, char value)
{
    ListNodePtr current = *head;

    if (current != NULL)
    {
        while (current->nextPtr != NULL)
        {
            current = current->nextPtr;
        }

        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    }
    else
    {
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextPtr = NULL;
        *head = current;
    }
}

void insert_at_beginning(ListNodePtr *head, char val)
{
    ListNodePtr new_node = malloc(sizeof(node_t));

    new_node->data = val;
    new_node->nextPtr = *head;
    *head = new_node;
}

char delete_node(ListNodePtr *head, char value)
{
    ListNodePtr previourPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;

    // delete first node
    if (value == (*head)->data)
    {
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
        return value;
    }
    else
    {
        previourPtr = *head;
        currentPtr = (*head)->nextPtr;

        // find the correct location in the list
        while (currentPtr != NULL && currentPtr->data != value)
        {
            previourPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // delete node at currentPtr
        if (currentPtr != NULL)
        {
            tempPtr = currentPtr;
            previourPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);

            return value;
        }
    }

    return '\0';
}

void delete_at_beginning(ListNodePtr *head)
{
    ListNodePtr tempPtr = NULL;

    if (head == NULL)
    {
        return;
    }
    else
    {
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
    }
}

int is_empty(ListNodePtr *head)
{
    return head == NULL;
}

void print_list(ListNodePtr currentPtr)
{
    if (currentPtr == NULL)
    {
        printf("list is empty.\n\n");
    }
    else
    {
        printf("the list is:\n");

        // while not the end of the list
        while (currentPtr != NULL)
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}
