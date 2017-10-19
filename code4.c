#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack Stack;
struct Stack{
    int size;
    char arr[25];
};
void pushElement(Stack* stk, char c){
    (stk->size++)[stk->arr] = c;
}
void popElement(Stack* stk){
    stk->size--;
}
char topElement(Stack* stk){
    return (stk->size - 1)[stk->arr];
}
Stack* createStack(){
    Stack* ret = (Stack*) malloc(sizeof(Stack));
    ret->size = 0;
    return ret;
}
void printStack(Stack* stk){
    for(int i = 0; i < stk->size; i++){
        printf("%c ", stk->arr[i]);
    }
    printf("\n");
}
int rank[260];
int rank1[260];
int flag = 0;
int isOp[25];
char buffer[25];
int curBuf = 0;
char ans[200];
int curAns = 0;
void putAns(char c){
    ans[curAns++] = c;
}
int main(){
    rank['+'] = rank['-'] = 1;
    rank['*'] = rank['/'] = 2;
    rank['('] = 3;

    rank1['+'] = rank1['-'] = 1;
    rank1['*'] = rank1['/'] = 2;
    rank1['('] = 0;

    char strIn[25];
    scanf("%s", strIn);
    for(int i = 1; i < strlen(strIn); i++){
        if( ( (strIn[i - 1] >= '0' && strIn[i - 1] <= '9') || strIn[i - 1] == ')')
        &&  (strIn[i] == '+' || strIn[i] == '-' || strIn[i] == '*' || strIn[i] == '/'))
            isOp[i] = 1;
    }
    Stack* stk = createStack();
    int curIn = 0;
    char c;
    for(;strIn[curIn]; curIn++){
        c = strIn[curIn];
        if(isOp[curIn] == 0 && strIn[curIn] != '(' && strIn[curIn] != ')'){
            buffer[curBuf++] = c;
            continue;
        }

        if(curBuf != 0){
            // printf(" ");
            putAns(' ');
            for(int i = 0; i < curBuf; i++)
                // printf("%c", buffer[i]);
                putAns(buffer[i]);
            curBuf = 0;
        }

        if(c == ')'){
            while(topElement(stk) != '('){
                // printf(" %c", topElement(stk));
                putAns(' '); putAns(topElement(stk));
                popElement(stk);
            }
            popElement(stk);
            continue;
        }
        if(stk->size == 0 || rank[topElement(stk)] < rank[c] || topElement(stk) == '('){
            pushElement(stk, c);
            continue;
        }
        while(stk->size != 0 && (rank1[topElement(stk)] >= rank1[c])){
            // printf(" %c", topElement(stk));
            putAns(' '); putAns(topElement(stk));
            popElement(stk);
        }
        pushElement(stk, c);

    }
    if(curBuf != 0){
        // printf(" ");
        putAns(' ');
        for(int i = 0; i < curBuf; i++){
            // printf("%c", buffer[i]);
            putAns(buffer[i]);
        }
        curBuf = 0;
    }

    while(stk->size != 0){
        // printf(" %c", topElement(stk));
        putAns(' ');
        putAns(topElement(stk));
        popElement(stk);
    }
    for(int i = 1; i < curAns; i++){
        if(ans[i] == '+' && ans[i - 1] == ' ' && ans[i + 1] >= '0' && ans[i + 1] <= '9')
            continue;
        printf("%c", ans[i]);
    }
    return 0;
}
