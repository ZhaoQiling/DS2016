#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );
Polynomial Read(){
    PtrToNode pHead = (PtrToNode)malloc(sizeof(struct Node));
    pHead->Coefficient = pHead->Exponent = 0;
    pHead->Next = NULL;
    PtrToNode pTail = pHead;

    int nNode;
    scanf("%d", &nNode);
    int coef, expo;
    for(int i = 0; i < nNode; i++){
        scanf("%d%d", &coef, &expo);
        PtrToNode pTemp = (PtrToNode)malloc(sizeof(struct Node));
        pTemp->Coefficient = coef; pTemp->Exponent = expo;
        pTemp->Next = NULL;

        pTail = pTail->Next = pTemp;
    }
    return pHead;
}
void Print( Polynomial p ){
    p = p->Next;
    while(p != NULL){
        printf("%d %d ", p->Coefficient, p->Exponent);
        p = p->Next;
    }
}

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    // printf("\n----------\n");
    // Print(a);
    // printf("\n");
    // Print(b);
    return 0;
}
Polynomial Add( Polynomial a, Polynomial b ){
    Polynomial sum = (Polynomial) malloc(sizeof(struct Node));
    sum->Coefficient = 0; sum->Exponent = 0;
    sum->Next = NULL;
    Polynomial pTail = sum;

    a = a->Next;  b = b->Next;
    int coef, expo;
    coef = expo = 0;
    PtrToNode pSave = pTail;
    while(1){
        if(expo == pTail->Exponent){
            pTail->Coefficient += coef;
            if(pTail->Coefficient == 0){
                pTail = pSave;
                pSave->Next = 0;
            }
        }
        else{
            pSave = pTail;
            pTail =
                pTail->Next = (PtrToNode) malloc(sizeof(struct Node));
            pTail->Coefficient = coef;
            pTail->Exponent = expo;
            pTail->Next = NULL;
        }
        if(a == NULL && b == NULL)
            break;
        if(b == NULL){
            coef = a->Coefficient;
            expo = a->Exponent;
            a = a->Next;
            continue;
        }
        if(a == NULL){
            coef = b->Coefficient;
            expo = b->Exponent;
            b = b->Next;
            continue;
        }

        if(a->Exponent >= b->Exponent){
            coef = a->Coefficient;
            expo = a->Exponent;
            a = a->Next;
        }
        else{
            coef = b->Coefficient;
            expo = b->Exponent;
            b = b->Next;
        }
    }
    return sum;
}
