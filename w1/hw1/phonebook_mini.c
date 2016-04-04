#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_util.h"
#include "phonebook_mini.h"

/* mini struct version */
#if defined(OPT)
entry *findName(char lastname[], entry *pHead)
{
    while (pHead != NULL)
    {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}
#else
orig_entry *findName(char lastname[], entry *pHead)
{
    while (pHead != NULL)
    {
        if (NULL != pHead->detail
                && strcasecmp(lastname, pHead->detail->lastName) == 0)
            return pHead->detail;
        pHead = pHead->pNext;
    }
    return NULL;
}
#endif

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
#if defined(OPT)
    char (*pDst)[] = &(e->lastName);
#else
    e->detail = (orig_entry *) malloc(sizeof(orig_entry));
    char (*pDst)[] = &(e->detail->lastName);
#endif
    strcpy(*pDst, lastName);
    e->pNext = NULL;

    return e;
}

void free_all(entry *pHead)
{
    do
    {
        entry *pTemp = pHead->pNext;
        free(pHead);
        pHead = pTemp;
    }
    while (NULL != pHead);
}

#if defined(DEBUG)
#include <stdio.h>
int main(void)
{
    entry *pHead = (entry *)malloc(sizeof(entry));
    pHead->pNext = NULL;
    entry *e = pHead;
    e = append("aqw", e);
    e = append("klfff", e);
    e = append("gggggggg", e);
    printf("%s\n", findName("aqw", pHead)->lastName);
    printf("%s\n", findName("klfff", pHead)->lastName);
    printf("%s\n", findName("gggggggg", pHead)->lastName);
    return 0;
}
#endif
