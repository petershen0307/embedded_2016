#include <stdlib.h>
#include <string.h>

#include "phonebook_util.h"
#include "phonebook_hash_array.h"

#define PRIME_NUMBER 8527

RETURN_TYPE findName(char lastName[], entry *pHead)
{
    return find_name_array(lastName, pHead);
}

entry *append(char lastName[], entry *e)
{
    return append_hash_table_array(e, lastName);
}

void free_all(entry *pHead)
{
    entry *pHashIndexHead = pHead->pNext;
    for (unsigned int i = 0; i < PRIME_NUMBER; ++i)
    {
#if defined(OPT)
        free_hash_struct(pHashIndexHead[i].pNext);
#else
        free_hash_struct(pHashIndexHead[i].pValue);
#endif
    }
    free(pHashIndexHead);
    free(pHead);
}

void free_hash_struct(RETURN_TYPE pHead)
{
    while (NULL != pHead)
    {
        RETURN_TYPE pTemp = pHead->pNext;
        free(pHead);
        pHead = pTemp;
    }
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

entry *append_hash_table_array(entry *head, char lastName[])
{
    entry **const hash_table_head = &(head->pNext);
    if (NULL == *hash_table_head)
    {
        *hash_table_head = (entry *)malloc(sizeof(entry) * PRIME_NUMBER);
        for (unsigned int i = 0; i < PRIME_NUMBER; ++i)
        {
            (*hash_table_head)[i].pNext = NULL;
            (*hash_table_head)[i].pValue = NULL;
        }
    }
    unsigned int const index = hashU(lastName, PRIME_NUMBER);
#if defined(OPT)
    entry *pPhone_book = (entry *)malloc(sizeof(entry));
    strncpy(pPhone_book->lastName, lastName, MAX_LAST_NAME_SIZE);
    pPhone_book->pNext = (*hash_table_head)[index].pNext;
    (*hash_table_head)[index].pNext = pPhone_book;
#else
    Phone_Book *pPhone_book = (Phone_Book *)malloc(sizeof(Phone_Book));
    pPhone_book->pNext = NULL;
    strncpy(pPhone_book->lastName, lastName, MAX_LAST_NAME_SIZE);
    if (NULL != (*hash_table_head)[index].pValue)
    {
        pPhone_book->pNext = (*hash_table_head)[index].pValue->pNext;
    }
    (*hash_table_head)[index].pValue = pPhone_book;
#endif
    return head;
}

RETURN_TYPE find_name_array(char lastName[], entry *pHead)
{
    unsigned int const index = hashU(lastName, PRIME_NUMBER);
    entry **const hash_table_head = &(pHead->pNext);
    RETURN_TYPE result;
#if defined(OPT)
    entry *pPhone_book = (*hash_table_head)[index].pNext;
    while (NULL != pPhone_book)
    {
        if (0 == strcmp(pPhone_book->lastName, lastName))
        {
            result = pPhone_book;
            break;
        }
        pPhone_book = pPhone_book->pNext;
    }
#else
    Phone_Book *pPhone_book = (*hash_table_head)[index].pValue;
    while (NULL != pPhone_book)
    {
        if (0 == strcmp(pPhone_book->lastName, lastName))
        {
            result = pPhone_book;
            break;
        }
        pPhone_book = pPhone_book->pNext;
    }
#endif
    return result;
}

#if defined(DEBUG)
#include <stdio.h>
int main(void)
{
    entry *pHead = (entry *)malloc(sizeof(entry));
    pHead->pNext = NULL;
    append("aqw", pHead);
    append("klfff", pHead);
    append("gggggggg", pHead);
    printf("%s\n", findName("aqw", pHead)->lastName);
    printf("%s\n", findName("klfff", pHead)->lastName);
    printf("%s\n", findName("gggggggg", pHead)->lastName);
    free_all(pHead);
    return 0;
}
#endif
