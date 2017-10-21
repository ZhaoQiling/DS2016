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

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */
Operation GetOp(){
    char ch[20];
    scanf("%s", ch);
    if(ch[0] == 'P' && ch[1] == 'u')
        return push;
    if(ch[0] == 'P' && ch[1] == 'o')
        return pop;
    if(ch[0] == 'I' && ch[1] == 'n')
        return inject;
    if(ch[0] == 'E' && ch[1] == 'j')
        return eject;
    if(ch[0] == 'E' && ch[1] == 'n')
        return end;
}
void PrintDeque( Deque D ){
    PtrToNode pCur = D->Front->Next;
    while(pCur != NULL){
        printf("%d ", pCur->Element);
        pCur = pCur->Next;
    }
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
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}
Deque CreateDeque(){
    Deque ret = (Deque)malloc(sizeof(struct DequeRecord));
    PtrToNode node = (PtrToNode)malloc(sizeof(struct Node));
    node->Last = node->Next  = NULL;
    ret->Front = ret->Rear = node;
    return ret;
}
int Push( ElementType X, Deque D ){
    PtrToNode pTemp = (PtrToNode)malloc(sizeof(struct Node));
    if(!pTemp)
        return 0;
    pTemp->Element = X;
    pTemp->Last = pTemp->Next = NULL;

    pTemp->Next = D->Front->Next;
    pTemp->Last = D->Front;
    D->Front->Next = pTemp;
    if(pTemp->Next != NULL)
        pTemp->Next->Last = pTemp;
    else
        D->Rear = pTemp;
    return 1;
}
ElementType Pop( Deque D ){
    if(D->Front == D->Rear)
        return ERROR;
    PtrToNode pSave = D->Front->Next;
    ElementType ret = pSave->Element;
    D->Front->Next = pSave->Next;
    if(pSave->Next == NULL){
        D->Rear = D->Front;
    }
    else{
        pSave->Next->Last = D->Front;
    }
    free(pSave);
    return ret;
}
int Inject( ElementType X, Deque D ){
    PtrToNode pTemp = (PtrToNode) malloc(sizeof(struct Node));
    if(!pTemp)
        return 0;
    pTemp->Element = X;
    pTemp->Last = pTemp->Next = NULL;

    pTemp->Last = D->Rear;
    D->Rear->Next = pTemp;
    D->Rear = pTemp;
    return 1;
}
ElementType Eject( Deque D ){
    if(D->Front == D->Rear)
        return ERROR;
    PtrToNode pSave = D->Rear;
    ElementType ret = pSave->Element;
    D->Rear = pSave->Last;
    pSave->Last->Next = NULL;
    free(pSave);
    return ret;
}
