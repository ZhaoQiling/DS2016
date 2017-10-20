#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
List MakeEmpty(){
    List ret = (List) malloc(sizeof(struct LNode));
    ret->Next = NULL; ret->Data = -1111;
    return ret;
}
Position Find( List L, ElementType X ){
    L = L->Next;
    while(L != NULL){
        if(L->Data == X)
            return L;
        L= L->Next;
    }
    return ERROR;
}
bool Insert( List L, ElementType X, Position P ){
    List pTemp = (List) malloc(sizeof(struct LNode));
    pTemp->Data = X; pTemp->Next = NULL;
    List pCur = L;
    while(pCur != NULL){
        if(pCur->Next == P){
            pTemp->Next = pCur->Next;
            pCur->Next = pTemp;
            return true;
        }
        pCur = pCur->Next;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}
bool Delete( List L, Position P ){
    if(P == NULL || L == NULL){
        printf("Wrong Position for Deletion\n");
        return false;
    }
    List pCur = L;
    while(pCur != NULL){
        if(pCur->Next == P){
            List pSave = P;
            pCur->Next = P->Next;
            free(P);
            return true;
        }
        pCur = pCur->Next;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}
