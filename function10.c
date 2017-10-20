#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

// BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT;
    // = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
void InorderTraversal( BinTree BT ){
    if(BT == NULL)
        return;
    InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    InorderTraversal(BT->Right);
}
void PreorderTraversal( BinTree BT ){
    if(BT == NULL)
        return;
    printf(" %c", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}
void PostorderTraversal( BinTree BT ){
    if(BT == NULL)
        return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}
void LevelorderTraversal( BinTree BT ){
    if(BT == NULL)
        return;
    Position arr[100];
    int head, tail;
    head = tail = 0;
    arr[tail] = BT;
    tail++;
    while(head < tail){
        BinTree front = arr[head];
        if(front->Left != NULL)
            arr[tail++] = front->Left;
        if(front->Right != NULL)
            arr[tail++] = front->Right;
        printf(" %c", front->Data);
        head++;
    }
}
