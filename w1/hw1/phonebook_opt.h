#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

typedef struct __Hash_Table entry;

typedef struct __PHONE_BOOK_ENTRY
{
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} Phone_Book;

Phone_Book *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);

//linked list hash table
struct __Hash_Table
{
    unsigned int index;
    Phone_Book* pValue;
    struct __Hash_Table* pNext;
};

unsigned int hashU(char *v, int m);

// TODO hash1: all index are linked list
entry *append_hash_table_linked_list(entry *head, char lastName[]);
Phone_Book *find_name_linked_list(char lastname[], entry *pHead);
// TODO hase2: index are array, can be random accessed

#endif
