#include <stdlib.h>
#include <stdio.h>
typedef struct Node Node;
struct Node{
    int coe, idx;
    Node* pNext;
};
Node* createNode(int coe, int idx){
    Node* ret = (Node*) malloc(sizeof(Node));
    ret->coe = coe; ret->idx = idx;
    ret->pNext = NULL;
    return ret;
}
Node* createList(int nNode){
    Node* head, *p;
    head = p = NULL;
    while(nNode--){
        int co, id;
        scanf("%d%d", &co, &id);
        if(p == NULL){
            p = createNode(co, id);
            head = p;
        }
        else if(p != NULL){
            p->pNext = createNode(co, id);
            p = p->pNext;
        }
    }
    return head;
}
void plus(Node* pA, Node* pB){
    Node* headAns = NULL;
    Node* pTail = NULL;
    while(pA != NULL || pB != NULL){
        Node* pTemp = NULL;
        if(pA != NULL && pB != NULL && pA->idx == pB->idx){
            pTemp = createNode(pA->coe + pB->coe, pA->idx);
            pA = pA->pNext;
            pB = pB->pNext;
        }
        else if((pA != NULL && pB != NULL && pA->idx < pB->idx) || pA == NULL){
            pTemp = createNode(pB->coe, pB->idx);
            pB = pB->pNext;
        }
        else if((pA != NULL && pB != NULL && pA->idx > pB->idx) || pB == NULL){
            pTemp = createNode(pA->coe, pA->idx);
            pA = pA->pNext;
        }

        if(headAns == NULL){
            pTail = pTemp;
            headAns = pTail;
        }
        else{
            if(pTail->idx == pTemp->idx){
                pTail->coe += pTemp->coe;
            }
            else{
                pTail->pNext = pTemp;
                pTail = pTail->pNext;
            }
        }
    }
    int flag = 0;
    for(Node* p = headAns; p != NULL; p = p->pNext){
        if(p->coe == 0)
            continue;
        if(flag)
            printf(" ");
        printf("%d %d", p->coe, p->idx);
        flag = 1;
    }
    if(flag == 0){
        printf("0 0");
    }
}
const int range = 2500;
int mulAns[6000];
void mul(Node* pA, Node* pB){
    Node* pHead,* pTail;
    pHead = pTail = NULL;
    for(Node* p1 = pA; p1 != NULL; p1 = p1->pNext){
        for(Node* p2 = pB; p2 != NULL; p2 = p2->pNext){
            int idx = (p1->idx) + (p2->idx);
            mulAns[range + idx] += (p1->coe) * (p2->coe);
        }
    }

    int flag = 0;
    for(int i = 5999; i >= 0; i--){
        if(mulAns[i] == 0)
            continue;
        if(flag == 1)
            printf(" ");
        printf("%d %d", mulAns[i], i - range);
        flag = 1;
    }
    if(flag == 0){
        printf("0 0");
    }
}
// 3 3 2 2 1 1 0
// 3 -3 2 -2 1 1 0
int main(){
    int lenA, lenB;
    scanf("%d", &lenA);
    Node* headA = createList(lenA);
    scanf("%d", &lenB);
    Node* headB = createList(lenB);
    mul(headA, headB);
    printf("\n");
    plus(headA, headB);

    return 0;
}
