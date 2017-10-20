#include <stdio.h>
typedef struct Node Node;
struct Node{
    char key;
    int leftChild;
    int rightChild;
};
Node tree1[15], tree2[15];
int isEx[30];
int main(){
    int nNode1;
    scanf("%d\n", &nNode1);
    for(int i = 0; i < nNode1; i++){
        char l, r;
        scanf("%c %c %c\n", &tree1[i].key, &l, &r);
        tree1[i].leftChild = (l == '-') ? -1 : (l - '0');
        tree1[i].rightChild = (r == '-') ? - 1 : (r - '0');
        isEx[tree1[i].key - 'A'] = 1;
    }
    int nNode2;
    scanf("%d\n", &nNode2);
    for(int i = 0; i < nNode2; i++){
        char l, r;
        scanf("%c %c %c\n", &tree2[i].key, &l, &r);
        tree2[i].leftChild = (l == '-') ? -1 : (l - '0');
        tree2[i].rightChild = (r == '-') ? -1 : (r - '0');
        if(isEx[tree2[i].key - 'A'] == 0){
            printf("No");
            return 0;
        }
    }
    // for(int i = 0; i < nNode; i++){
    //     printf("%c %d %d\n", tree1[i].key, tree1[i].leftChild, tree1[i].rightChild);
    // }
    // for(int i = 0; i < nNode; i++){
    //     printf("%c %d %d\n", tree2[i].key, tree2[i].leftChild, tree2[i].rightChild);
    // }
    if(nNode1 != nNode2){
        printf("No");
        return 0;
    }
    for(int i = 0; i < nNode1; i++){
        int j = 0;
        while(tree2[j].key != tree1[i].key) j++;
        //tree1左子树　等于　tree2左子树　tree1右子树　等于　tree2右子树
        if((tree1[tree1[i].leftChild].key == tree2[tree2[j].leftChild].key
            && tree1[tree1[i].rightChild].key == tree2[tree2[j].rightChild].key) ||
            // 左子树　等于　右子树　右子树　等于　左子树
            (tree1[tree1[i].leftChild].key == tree2[tree2[j].rightChild].key
                && tree1[tree1[i].rightChild].key == tree2[tree2[j].leftChild].key)){
            continue;
        }
        printf("No");
        return 0;
    }
    printf("Yes");
    return 0;
}
