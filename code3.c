#include <stdio.h>
int unhappy = 0, sad = 0, exciting = 0;
int isRate(){
    if(exciting)
        return 1;
    if(unhappy || sad)
        return 0;
    return 1;
}
int main(){
    char operSeq[100];
    scanf("%s", operSeq);
    int cost = 0, salary = 0;
    int curOper = 0;
    while(curOper++[operSeq] != '$'){
        char c = (curOper - 1)[operSeq];
        if(c == 'X'){
            if(isRate()){
                printf("U");
                unhappy = 1 + 1;
            }
            else
                printf("-");
        }
        else if(c == 'T'){
            if(isRate()){
                cost += 3;
                salary += 10;
                sad = 2 + 1;
                printf("D");
            }
            else{
                printf("-");
            }
        }
        else if(c == 'C'){
            if(isRate()){
                printf("!");
                cost += 3;
                exciting = 2 + 1;
            }
            else{
                printf("-");
            }
        }
        if(unhappy) unhappy--;
        if(sad) sad--;
        if(exciting) exciting--;
    }
    printf("\n%d", salary - cost);
    return 0;
}
