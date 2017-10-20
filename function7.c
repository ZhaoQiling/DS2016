#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

// Operation GetOp();          /* details omitted */
// void PrintDeque( Deque D ); /* details omitted */
int  GetOp(){
    int val;
    scanf("%d", &val);
    return val;
}
int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push:
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject:
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            // PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}
Deque CreateDeque(){
    Deque ret = malloc(sizeof(struct DequeRecord));
    ret->Front = ret->Rear = NULL;
    return ret;
}
int Push( ElementType X, Deque D ){
    if(D == NULL)
        return 0;
    PtrToNode pTemp = (PtrToNode) malloc(sizeof(struct Node));
    pTemp->Element = X;
    pTemp->Next = pTemp->Last = NULL;

    if(D->Front == NULL && D->Rear == NULL){
        D->Front = D->Rear = pTemp;
        return 1;
    }
    PtrToNode pSave = D->Front;
    D->Front = pTemp;
    pTemp->Next = pSave;
    pSave->Last = pTemp;

    return 1;
}
ElementType Pop( Deque D ){
    if(D == NULL)
        return ERROR;
    if(D->Front == NULL && D->Rear == NULL)
        return ERROR;
    if(D->Front == D->Rear){
        ElementType ret = D->Front->Element;
        free(D->Front);
        D->Front = D->Rear = NULL;
        return ret;
    }
    PtrToNode pSave = D->Front;
    ElementType ret = pSave->Element;
    D->Front = pSave->Next;
    pSave->Next->Last = NULL;
    free(pSave);
    return ret;
}
int Inject( ElementType X, Deque D ){
    if(D == NULL)
        return 0;
    PtrToNode pTemp = (PtrToNode) malloc(sizeof(struct Node));
    pTemp->Element = X;
    pTemp->Next = pTemp->Last = NULL;

    if(D->Front == NULL && D->Rear == NULL){
        D->Front = D->Rear = pTemp;
        return 1;
    }

    PtrToNode pSave = D->Rear;
    pSave->Next = pTemp;
    pTemp->Last = pSave;
    D->Rear = pTemp;
    return 1;
}
ElementType Eject( Deque D ){
    if(D == NULL)
        return ERROR;
    if(D->Front == NULL && D->Rear == NULL)
        return ERROR;
    if(D->Front == D->Rear){
        ElementType ret = D->Front->Element;
        free(D->Front);
        D->Front = D->Rear = NULL;
        return ret;
    }

    PtrToNode pSave = D->Rear;
    ElementType ret = pSave->Element;
    D->Rear = pSave->Last;
    pSave->Last->Next = NULL;
    free(pSave);
    return ret;

}
