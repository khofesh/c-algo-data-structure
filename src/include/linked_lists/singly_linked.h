#ifndef SINGLY_LINKED_H

#define SINGLY_LINKED_H

typedef void (*fptrDestroy)(void *);
typedef int (*fptrMatch)(const void *, const void *);

typedef struct ListElmt_
{
    void *data;
    struct ListElmt_ *next;
} ListElmt;

typedef struct List_
{
    int size;
    fptrMatch match;
    fptrDestroy destroy;
    ListElmt *head;
    ListElmt *tail;
} List;

void list_init(List *list, fptrDestroy destroy);
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif