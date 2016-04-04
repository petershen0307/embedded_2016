#ifndef __PHONE_BOOK_UTIL_H__
#define __PHONE_BOOK_UTIL_H__

#define MAX_LAST_NAME_SIZE 16
struct __PHONE_BOOK_ENTRY
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
};

#endif //__PHONE_BOOK_UTIL_H__
