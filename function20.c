#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode {
    int Element;
    Tree  Left;
    Tree  Right;
};

// Tree BuildTree(); /* details omitted */
// void Output( int X ); /* details omitted */

void Print_NLT( Tree T,  int X );

int main()
{
    Tree T;
    int X;

    // T = BuildTree();
    scanf("%d", &X);
    Print_NLT( T, X );
    printf("End\n");

    return 0;
}

void Print_NLT( Tree T,  int X ){
    if(T == NULL)
        return;
    Print_NLT(T->Right, X);
    if(T->Element >= X)
        printf("%d ", T->Element);
    Print_NLT(T->Left, X);
}
