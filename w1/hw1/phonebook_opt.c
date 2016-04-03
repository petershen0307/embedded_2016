#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

#define PRIME_NUMBER 8527

Phone_Book *findName(char lastName[], entry *pHead)
{
    return find_name_linked_list(lastName, pHead);
}

entry *append(char lastName[], entry *e)
{
    return append_hash_table_linked_list(e, lastName);
}

/* hash function */
unsigned int hashU(char *v, int m)
{
    int a = 31415;
    int const b = 27183;
    int h = 0;
    for (h = 0; '\0' != *v; a = (a * b) % (m - 1), ++v)
    {
        h = (a * h + (*(int*)(void*)v)) % m;
    }
    return h;
}

entry *append_hash_table_linked_list(entry *head, char lastName[])
{
    if (NULL == head->pNext)
    {
        entry **cur_ptr = &head;
        for (unsigned int i = 0; i < PRIME_NUMBER; ++i)
        {
            if (NULL == *cur_ptr)
            {
                *cur_ptr = (entry *)malloc(sizeof(entry));
                (*cur_ptr)->pNext = NULL;
                (*cur_ptr)->pValue = NULL;
            }
            (*cur_ptr)->index = i;
            cur_ptr = &((*cur_ptr)->pNext);
        }
    }
    unsigned int const index = hashU(lastName, PRIME_NUMBER);
    for (entry *cur_index = head; NULL != cur_index; cur_index = cur_index->pNext)
    {
        if (index == cur_index->index)
        {
            Phone_Book *pPhone_book = (Phone_Book *)malloc(sizeof(Phone_Book));
            strncpy(pPhone_book->lastName, lastName, MAX_LAST_NAME_SIZE);
            if (NULL != cur_index->pValue)
            {
                pPhone_book->pNext = cur_index->pValue->pNext;
            }
            cur_index->pValue = pPhone_book;
        }
    }
    return head;
}

Phone_Book *find_name_linked_list(char lastName[], entry *pHead)
{
    unsigned int const index = hashU(lastName, PRIME_NUMBER);
    Phone_Book *result = NULL;
    for (entry *cur_ptr = pHead; NULL != cur_ptr; cur_ptr = cur_ptr->pNext)
    {
        if (index == cur_ptr->index)
        {
            Phone_Book *pPhone_book = cur_ptr->pValue;
            while (NULL != pPhone_book)
            {
                if (0 == strcmp(pPhone_book->lastName, lastName))
                {
                    result = pPhone_book;
                    break;
                }
                pPhone_book = pPhone_book->pNext;
            }
            break;
        }
    }
    return result;
}

//#include <stdio.h>
//int main(void)
//{
//    entry *pHead = (entry *)malloc(sizeof(entry));
//    pHead->pNext = NULL;
//    append("aqw", pHead);
//    append("klfff", pHead);
//    append("gggggggg", pHead);
//    printf("%s\n", findName("aqw", pHead)->lastName);
//    printf("%s\n", findName("klfff", pHead)->lastName);
//    printf("%s\n", findName("gggggggg", pHead)->lastName);
//}
