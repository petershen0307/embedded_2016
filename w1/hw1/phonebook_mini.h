#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* mini struct version */
typedef struct __PHONE_BOOK_ENTRY orig_entry;

typedef struct __Mini_entry
{
    orig_entry* detail;
    struct __Mini_entry *pNext;
#if defined(OPT)
    char lastName[MAX_LAST_NAME_SIZE];
#endif
} entry;

#if defined(OPT)
entry *findName(char lastname[], entry *pHead);
#else
orig_entry *findName(char lastname[], entry *pHead);
#endif
entry *append(char lastName[], entry *e);
void free_all(entry *pHead);

#endif
