#include <stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}
char preOrder[60];
char inOrder[60];
int dfs(int preBegin, int preEnd, int inBegin, int inEnd){
    if(preBegin >= preEnd)
        return 1;
    char rootKey = preOrder[preBegin];
    int i = inBegin;
    for(; i <= inEnd && inOrder[i] != rootKey; i++){}
    return max(dfs(preBegin + 1, preBegin + i - inBegin,
                                                        inBegin, i - 1),
                dfs(preBegin + i - inBegin + 1, preEnd,
                                                        i + 1, inEnd))
                                                                    + 1;
}
int main(){
    int nNode;
    scanf("%d", &nNode);
    scanf("%s%s", preOrder, inOrder);
    printf("%d", dfs(0, nNode - 1, 0, nNode - 1));
    return 0;
}
