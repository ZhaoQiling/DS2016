#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int value;
    Node* pNext;
};
int nPeo, line;
Node* pHead, *pTail;
void insertNode(int value){
    Node* pTemp = (Node*)malloc(sizeof(struct Node));
    pTemp->value = value; pTemp->pNext = NULL;

    Node* pCur = pHead;
    while(pCur->pNext != NULL){
        if(value >= pCur->pNext->value)
            break;
        pCur = pCur->pNext;
    }
    pTemp->pNext = pCur->pNext;
    pCur->pNext = pTemp;

    pTail = pHead;
    for(int i = 0; i < line; i++){
        if(pTail->pNext != NULL)
            pTail = pTail->pNext;
        else
            break;
    }
    pTail->pNext == NULL;
}
int main(){
    scanf("%d%d", &nPeo, &line);
    pHead = pTail = (Node*)malloc(sizeof(Node));
    for(int i = 0; i < nPeo; i++){
        int value;
        scanf("%d", &value);
        if(i >= line && value < pTail->value)
            continue;
        insertNode(value);
    }
    Node* pCur = pHead->pNext;
    while(pCur != pTail){
        printf("%d ", pCur->value);
        pCur = pCur->pNext;
    }
    printf("%d", pTail->value);
    return 0;
}
