#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    int key;
    int height;
    Node* left, *right;
};
int max(int a, int b){
    return a > b ? a : b;
}
int getHeight(Node* root){
    return root == NULL ? 0 : root->height;
}
Node* createNode(int key){
    Node* ret = (Node*)malloc(sizeof(Node));
    ret->key = key;
    ret->height = 1;
    ret->left = ret->right = NULL;
    return ret;
}
Node* llrotation(Node* root){
    Node* ret = root->left;
    root->left = ret->right;
    ret->right = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    ret->height = max(getHeight(ret->left), getHeight(ret->right)) + 1;
    return ret;
}
Node* rrrotation(Node* root){
    Node* ret = root->right;
    root->right = ret->left;
    ret->left = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    ret->height = max(getHeight(ret->left), getHeight(ret->right)) + 1;
    return ret;
}
Node* lrrotation(Node* root){
    root->left = rrrotation(root->left);
    return llrotation(root);
}
Node* rlrotation(Node* root){
    root->right = llrotation(root->right);
    return rrrotation(root);
}
Node* insertNode(Node* root, int key){
    if(root == NULL)
        return createNode(key);
    //insert in the left subtree
    if(key < root->key){
        root->left = insertNode(root->left, key);
        //loss balance
        if(getHeight(root->left) - getHeight(root->right) == 2){
            //ll
            if(key < root->left->key)
                root = llrotation(root);
            //lr
            else if(key > root->left->key)
                root = lrrotation(root);
        }
    }
    //insert in the right subtree
    else{
        root->right = insertNode(root->right, key);
        //loss balance
        if(getHeight(root->right) - getHeight(root->left) == 2){
            //rl
            if(key < root->right->key)
                root = rlrotation(root);
            //rr
            else if(key > root->right->key)
                root = rrrotation(root);
        }

    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}
int main(){
    int nNode;
    scanf("%d", &nNode);
    Node* root = NULL;
    while(nNode--){
        int key;
        scanf("%d", &key);
        root = insertNode(root, key);
        // printf("Now root's key is %d\n", root->key);
    }
    printf("%d", root->key);
    // printf("flag");
    return 0;
}
