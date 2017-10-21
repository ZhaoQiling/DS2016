#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    long long  key;
    int count;
    Node* pNext;
};
int maxAns = 1;
int para = 0;
Node* pHead;
void insertNode(long long val){
    Node* pCur = pHead;
    while(pCur->pNext != NULL){
        if(pCur->pNext->key == val){
            pCur->pNext->count++;
            if(pCur->pNext->count > maxAns){
                maxAns = pCur->pNext->count;
            }
            return;
        }
        if(val < pCur->pNext->key)
            break;
        pCur = pCur->pNext;
    }
    Node* pTemp = (Node*) malloc(sizeof(Node));
    pTemp->key = val; pTemp->pNext = NULL; pTemp->count = 1;
    pTemp->pNext = pCur->pNext;
    pCur->pNext = pTemp;
}
int main(){
    pHead = (Node*) malloc(sizeof(Node));
    pHead->pNext = NULL;
    int nPair;
    scanf("%d", &nPair);
    long long record;
    for(int i = 0; i < nPair; i++){
        scanf("%lld", &record);
        insertNode(record);
        scanf("%lld", &record);
        insertNode(record);
    }
    Node* pCur = pHead->pNext;
    int flag = 0;
    while(pCur != NULL){
        if(pCur->count == maxAns && flag == 1)
            para++;
        if(pCur->count == maxAns && flag == 0){
            printf("%lld %d", pCur->key, pCur->count);
            flag = 1; para = 1;
        }
        pCur = pCur->pNext;
    }
    // printf("maxAns is %d\n", maxAns);
    if(para != 1)
        printf(" %d", para);
    return 0;
}
