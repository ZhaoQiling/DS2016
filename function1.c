#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

// List Read(); /* 细节在此不表 */
// void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    // L1 = Read();
    // L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}
List Reverse( List L ){
    if(L == NULL)
        return NULL;
    if(L->Next == NULL)
        return L;
    List pPre = NULL;
    List pHead = L;
    List pSave;
    while(pHead->Next != NULL){
        pSave = pHead->Next;
        pHead->Next = pPre;
        pPre = pHead;
        pHead = pSave;
    }
    pHead->Next = pPre;
    return pHead;
}
