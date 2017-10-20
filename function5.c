#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
Position Find( List L, ElementType X ){
    while(L != NULL){
        if(L->Data == X)
            return L;
        L = L->Next;
    }
    return ERROR;
}
List Insert( List L, ElementType X, Position P ){
    List pTemp = (List) malloc(sizeof(struct LNode));
    pTemp->Data = X; pTemp->Next = NULL;
    if(L == NULL)
        return pTemp;
    if(P == NULL){
        List pTail = L;
        while(pTail->Next != NULL)
            pTail = pTail->Next;
        pTail->Next = pTemp;
        return L;
    }
    if(L == P){
        pTemp->Next = L;
        return pTemp;
    }
    List pCur = L;
    while(pCur->Next != NULL){
        if(pCur->Next == P){
            pTemp->Next = pCur->Next;
            pCur->Next = pTemp;
            return L;
        }
        pCur = pCur->Next;
    }
    printf("Wrong Position for Insertion\n");
    return ERROR;
}
List Delete( List L, Position P ){
    if(L == NULL){
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    if(L == P){
        List ret = L->Next;
        free(L);
        return ret;
    }
    List pCur = L;
    while(pCur->Next != NULL){
        if(pCur->Next == P){
            List pSave = pCur->Next;
            pCur->Next = pSave->Next;
            free(pSave);
            return L;
        }
        pCur = pCur->Next;
    }
    printf("Wrong Position for Deletion\n");
    return ERROR;
}
