#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* original version */
typedef struct __PHONE_BOOK_ENTRY entry;

entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);
void free_all(entry *pHead);

#endif
