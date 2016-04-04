#ifndef _PHONEBOOK_HASH_LINKED_LIST_H_
#define _PHONEBOOK_HASH_LINKED_LIST_H_

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
void free_hash_struct(entry *pHead);

//linked list hash table
struct __Hash_Table
{
    unsigned int index;
    Phone_Book* pValue;
    //linked list: pNext is next item
    struct __Hash_Table* pNext;
#if defined(OPT)
    char lastName[MAX_LAST_NAME_SIZE];
    struct __Hash_Table* pValueNext;
#endif
};

unsigned int hashU(char *v, int m);
entry *append_hash_table_linked_list(entry *head, char lastName[]);
RETURN_TYPE find_name_linked_list(char lastName[], entry *pHead);
#endif //_PHONEBOOK_HASH_LINKED_LIST_H_
