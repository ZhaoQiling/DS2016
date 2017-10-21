#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node Node;
struct Node{
    char type[50];
    int cnt;
    Node *leftChild, *rightChild;
};
int nTree;
Node* createNode(char name[], int cnt){
    Node* ret = (Node*)malloc(sizeof(Node));
    strcpy(ret->type, name);
    ret->cnt = cnt;
    ret->leftChild = ret->rightChild = NULL;
    return ret;
}
Node* insertNode(Node* root, char name[]){
    if(root == NULL)
        return root = createNode(name, 1);
    int cmp = strcmp(name, root->type);
    if(cmp < 0)
        root->leftChild = insertNode(root->leftChild, name);
    else if(cmp > 0)
        root->rightChild = insertNode(root->rightChild, name);
    else
        root->cnt++;
    return root;
}
void dfs(Node* p){
    if(p == NULL)
        return;
    dfs(p->leftChild);
    printf("%s %.4lf%%\n" ,p->type, p->cnt * 100.0 / nTree);
    dfs(p->rightChild);
}
int main(){
    scanf("%d\n", &nTree);
    Node* root = NULL;
    char name[50];
    int i = 0;
    for(; i < nTree; i++){
        gets(name);
        root = insertNode(root, name);
    }
    dfs(root);
    return 0;
}
