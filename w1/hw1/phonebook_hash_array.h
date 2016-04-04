#ifndef __PHONEBOOK_HASH_ARRAY_H__
#define __PHONEBOOK_HASH_ARRAY_H__

#define MAX_LAST_NAME_SIZE 16
#if defined(OPT)
#define RETURN_TYPE entry*
#else
#define RETURN_TYPE Phone_Book*
#endif

typedef struct __Hash_Table entry;
typedef struct __PHONE_BOOK_ENTRY Phone_Book;

RETURN_TYPE findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);
void free_all(entry *pHead);
void free_hash_struct(RETURN_TYPE pHead);

//linked list hash table
struct __Hash_Table
{
    Phone_Book* pValue;
    // array: pNext is the array head and for compatible with main.c
    struct __Hash_Table* pNext;
#if defined(OPT)
    char lastName[MAX_LAST_NAME_SIZE];
#endif
};

unsigned int hashU(char *v, int m);
entry *append_hash_table_array(entry *head, char lastName[]);
RETURN_TYPE find_name_array(char lastName[], entry *pHead);
#endif //__PHONEBOOK_HASH_ARRAY_H__
