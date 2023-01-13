#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "singly_linked.h"

void list_init(List *list, fptrDestroy destroy)
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->head = NULL;
}

void list_destroy(List *list)
{
    void *data;

    while (list_size(list) > 0)
    {
        int res = list_rem_next(list, NULL, (void **)&data);
        // (void *)res;

        if (res != 0)
        {
            printf("Error: list_rem_next return non-zero\n");
        }
    }

    // no operations are allowed now, but clear the structure as a precaution.
    memset(list, 0, sizeof(List));
}

int list_ins_next(List *list, ListElmt *element, const void *data)
{
    ListElmt *new_element = (ListElmt *)malloc(sizeof(ListElmt));

    if (new_element == NULL)
    {
        return -1;
    }

    // insert the element into the list
    new_element->data = (void *)data;

    if (element == NULL)
    {
        // handle insertion at the head of the list.
        if (list_size(list) == 0)
        {
            list->tail = new_element;
        }

        new_element->next = list->head;
        list->head = new_element;
    }
    else
    {
        // handle insertion somewhere else
        if (element->next == NULL)
        {
            list->tail = new_element;
        }

        new_element->next = element->next;
        element->next = new_element;
    }

    // adjust the size of the list
    list->size++;

    return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data)
{
    ListElmt *old_element;

    // avoid removing element from an empty list
    if (list_size(list) == 0)
    {
        return -1;
    }

    // remove element from the list
    if (element == NULL)
    {
        // handle removal from the head of the list
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;

        if (list_size(list) == 1)
        {
            list->tail = NULL;
        }
    }
    else
    {
        // handle removal from somewhere else.
        if (element->next == NULL)
        {
            return -1;
        }

        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;

        if (element->next == NULL)
        {
            list->tail = element;
        }
    }

    free(old_element);

    list->size--;

    return 0;
}
