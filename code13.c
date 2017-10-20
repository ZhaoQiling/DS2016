#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int data;
    Node* pNext;
};
int main(){
    int theLoc;
    scanf("%d", &theLoc);
    int key;
    int cntInput = 0;
    int cntNode = 0;
    Node* pHead = (Node*)malloc(sizeof(Node));
    Node* pTail = pHead;
    while(scanf("%d", &key) && key >= 0){
        cntInput++;
        Node* pTemp = (Node*)malloc(sizeof(Node));
        pTemp->data = key; pTemp->pNext = NULL;

        cntNode++;
        pTail->pNext = pTemp;
        pTail = pTemp;

        if(cntNode > theLoc){
            cntNode--;
            pHead->pNext = pHead->pNext->pNext;
        }
    }
    if(cntInput < theLoc){
        printf("NULL");
        return 0;
    }
    printf("%d", pHead->pNext->data);
    return 0;
}
