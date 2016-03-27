#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct _List
{
    struct _List *next;
    int val;
} List;

bool is_duplicate_value_exist(int const value, List const* head, List const* tail)
{
    for (List const* current = head; current != tail; current = current->next)
    {
        if (value == current->val)
        {
            return true;
        }
    }
    return false;
}

void print_list(List const* head)
{
    for (List const* current = head; current != NULL; current = current->next)
    {
        printf("%d ", current->val);
    }
    printf("\n");
}

void free_list(List* head)
{
    while (head != NULL)
    {
        List* to_remove = head;
        head = head->next;
        free(to_remove);
        to_remove = NULL;
    }
}

void random_without_duplicate(unsigned int const size, List** head, List** tail)
{
    for (unsigned int i = 0; size != i; ++i)
    {
        List* new_item = (List*)malloc(sizeof(List));
        new_item->next = NULL;
        new_item->val = 0;

        do
        {
            new_item->val = rand() % size + 1;
        }
        while(is_duplicate_value_exist(new_item->val, *head, *tail));

        if (NULL == *head)
        {
            *head = new_item;
            *tail = new_item;
        }
        else
        {
            new_item->next = *head;
            *head = new_item;
        }
    }
}

void shuffle_list(unsigned int const size, List** head, List** tail)
{
    for (unsigned int i = 0; size != i; ++i)
    {   
        List* new_item = (List*)malloc(sizeof(List));
        new_item->next = NULL;
        new_item->val = i + 1;
        if (NULL == *head)
        {
            *head = new_item;
            *tail = new_item;
        }
        else
        {
            new_item->next = *head;
            *head = new_item;
        }
    }

    List* first = (*head);
    for (unsigned int i = size; 0 != i; --i, first = first->next)
    {
        List* second = (*head);
        int const pos = rand() % size;
        for (int j = 1; j <= pos; ++j)
        {
            second = second->next;
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}

int main()
{
    srand(time(NULL));
    List* head = NULL;
    List* tail = NULL;
    int const size = 10000;
//    random_without_duplicate(size, &head, &tail);
    shuffle_list(size, &head, &tail);
//    print_list(head);
    free_list(head);
    return 0;
}

