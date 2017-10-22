#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    long long key;
    int cnt;
    Node *leftChild, *rightChild;
};
Node* createNode(long long key){
    Node* ret = (Node*) malloc(sizeof(Node));
    ret->key = key;
    ret->cnt = 1;
    ret->leftChild = ret->rightChild = NULL;
    return ret;
}
int maxAns = 0;
Node* insertNode(Node* root, long long key){
    if(!root)
        return createNode(key);
    // printf("\n------%lld------\n", root->key);
    if(key < root->key)
        root->leftChild = insertNode(root->leftChild, key);
    else if(key > root->key)
        root->rightChild = insertNode(root->rightChild, key);
    else if(key == root->key){
        root->cnt++;
        if(root->cnt > maxAns)
            maxAns = root->cnt;
    }
    return root;
}
long long minTeleNum = -1;
int nSame = 0;
void inOrder(Node* root){
    if(!root)
        return;
    inOrder(root->leftChild);
    if(root->cnt == maxAns){
        if(root->cnt == maxAns)
            nSame++;
        if(minTeleNum == -1)
            minTeleNum = root->key;
    }
    inOrder(root->rightChild);
}
int main(){
    Node* root = NULL;
    int nRecord;
    scanf("%d", &nRecord);
    while(nRecord--){
        long long key;
        scanf("%lld", &key);
        root = insertNode(root, key);
        scanf("%lld", &key);
        root = insertNode(root, key);
    }
    // printf("%d", maxAns);
    inOrder(root);
    printf("%lld %d", minTeleNum, maxAns);
    if(nSame != 1)
        printf(" %d", nSame);
    return 0;
}
