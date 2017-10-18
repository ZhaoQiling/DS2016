#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack Stack;
struct Stack{
    int size;
    char arr[30];
};
void pushElement(Stack* stk, char ch){
    (stk->size++)[stk->arr] = ch;
}
void popElement(Stack* stk){
    stk->size--;
}
char topElement(Stack* stk){
    return (stk->size - 1)[stk->arr];
}
Stack* createStack(){
    Stack* ret = (Stack*)malloc(sizeof(Stack));
    ret->size = 0;
    return ret;
}
int ansArr[5000][2];
int curAns = 0;
void addAns(int a, int b){
    ansArr[curAns][0] = a;
    ansArr[curAns][1] = b;
    curAns++;
}
int main(){
    Stack* stk = createStack();
    char s1[30], s2[30];
    scanf("%s%s", s1, s2);
    int cur1 = 0, cur2 = 0;
    //cur1　入栈元素
    //cur2 出栈元素
    while(cur1 != strlen(s1)){
        if(s1[cur1] != s2[cur2]){
            pushElement(stk, s1[cur1++]);
            // printf("1->3\n");
            addAns(1, 3);
        }
        else if(s1[cur1] == s2[cur2]){
            // printf("1->2\n");
            addAns(1, 2);
            cur1++; cur2++;
        }

        if(stk->size > 26){
            printf("Are you kidding me?\n");
            return 0;
        }

        while(stk->size != 0 && topElement(stk) == s2[cur2]){
            popElement(stk);
            cur2++;
            // printf("3->2\n");
            addAns(3, 2);
        }
    }
    if(stk->size != 0)
        printf("Are you kidding me?\n");
    else
        for(int i = 0; i < curAns; i++)
            printf("%d->%d\n", ansArr[i][0], ansArr[i][1]);
    return 0;
}
