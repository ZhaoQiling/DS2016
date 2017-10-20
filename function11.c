#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};
Tree BuildTree(); /* details omitted */
void PrintNode( Tree NodePtr )
{
   printf(" %d", NodePtr->Element);
}
void Level_order ( Tree T, void (*visit)(Tree ThisNode) );
int main()
{
    Tree T;
    //  = BuildTree();
    printf("Level-order:");
    Level_order(T, PrintNode);
    return 0;
}
void Level_order ( Tree T, void (*visit)(Tree ThisNode) ){
    if(T == NULL)
        return;
    Tree arr[500];
    int head, tail;
    head = tail = 0;
    arr[tail++] = T;
    while(head < tail){
        Tree front = arr[head];
        visit(front);
        if(front->Left != NULL)
            arr[tail++] = front->Left;
        if(front->Right != NULL)
            arr[tail++] = front->Right;
        head++;
    }
}
