#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

typedef struct __Hash_Table entry;
typedef struct __PHONE_BOOK_ENTRY Phone_Book;

Phone_Book *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);

//linked list hash table
struct __Hash_Table
{
#if defined(LINKED_LIST)
    unsigned int index;
#endif
    Phone_Book* pValue;
    //linked list: pNext is next item
    // array: pNext is the array head and for compatible with main.c
    struct __Hash_Table* pNext;
#if defined(OPT)
    char lastName[MAX_LAST_NAME_SIZE];
#endif
};

unsigned int hashU(char *v, int m);

#if defined(LINKED_LIST)
// hash1: all index are linked list
entry *append_hash_table_linked_list(entry *head, char lastName[]);
Phone_Book *find_name_linked_list(char lastName[], entry *pHead);
#else
// hase2: index are array, can be random accessed
entry *append_hash_table_array(entry *head, char lastName[]);
Phone_Book *find_name_array(char lastName[], entry *pHead);
#endif
#endif //_PHONEBOOK_H
