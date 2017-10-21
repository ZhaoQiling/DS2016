#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int key;
    Node* pNext;
};
Node* createNodelist(){
    Node *pHead, *pTail;
    pHead = pTail = NULL;
    int val;
    while(scanf("%d", &val) && val != -1){
        Node* pTemp = (Node*) malloc(sizeof(Node));
        pTemp->key = val; pTemp->pNext = NULL;
        if(pHead == NULL)
            pHead = pTail = pTemp;
        else
            pTail = pTail->pNext = pTemp;
    }
    return pHead;
}
int main(){
    Node* pHead1 = createNodelist();
    Node* pHead2 = createNodelist();
    if(pHead1 == NULL && pHead2 == NULL){
        printf("NULL");
        return 0;
    }
    int flag = 0;
    while(pHead1 != NULL || pHead2 != NULL){
        if(pHead2 == NULL){
            if(flag == 1) printf(" ");
            printf("%d", pHead1->key);
            flag = 1;
            pHead1 = pHead1->pNext;
            continue;
        }
        if(pHead1 == NULL){
            if(flag == 1) printf(" ");
            printf("%d", pHead2->key);
            flag = 1;
            pHead2 = pHead2->pNext;
            continue;
        }
        if(pHead1->key <= pHead2->key){
            if(flag == 1) printf(" ");
            printf("%d", pHead1->key);
            flag = 1;
            pHead1 = pHead1->pNext;
        }
        else if(pHead1->key > pHead2->key){
            if(flag == 1) printf(" ");
            printf("%d", pHead2->key);
            flag = 1;
            pHead2 = pHead2->pNext;
        }
    }
    return 0;
}
